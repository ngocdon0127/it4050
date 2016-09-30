import sys
import psyco
psyco.full()
def isset(a, b): return ((a >> b) & 1) != 0
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return [foo(x) for x in raw_input().split()]



def doit(i, j):
	if (i, j) in mem:
		return mem[(i, j)]
	if (j >= len(phrase)):
		return 1
	if (i >= len(text)):
		return 0
	res = doit(i + 1, j)
	if (text[i] == phrase[j]):
		res += doit(i + 1, j + 1)
	res %= 10000
	mem[(i, j)] = res
	return res

def run_test(test):
	dbg("Test %d\n" % (test + 1))
	global text, phrase, mem
	text = raw_input()
	phrase = "welcome to code jam"
	mem = {}
	
	print "Case #%d: %04d" % (test + 1, doit(0, 0))
	
	

for test in range(readint()):
	run_test(test)

