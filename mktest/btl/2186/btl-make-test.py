import sys
import time
import random
import os
import shutil

stt = 1
vertexs = 10000
edges = 50000

for stt in range(1, 11):
	vertex = vertexs / (10 / stt)
	edge = edges / (10 / stt)
	base = vertex + 1
	name = ['test', str(stt)]
	os.mkdir(''.join(name))
	# os.rename(''.join(['cookieselection.0', str(stt), '.in']), 'cookieselection.INP')
	# os.rename(''.join(['cookieselection.0', str(stt), '.ans']), 'cookieselection.OUT')
	# shutil.move('cookieselection.INP', ''.join(['test', str(stt), '/cookieselection.INP']))
	# shutil.move('cookieselection.OUT', ''.join(['test', str(stt), '/cookieselection.OUT']))
	random.seed(time.localtime().tm_sec)
	f = open(''.join(name + ['/2186.in']), 'w')

	f.write(str(vertex) + ' ' + str(edge) + '\n')
	s = set()
	while (len(s) < edge):
		v1 = random.randint(1, vertex)
		v2 = v1
		while (v1 == v2):
			v2 = random.randint(1, vertex)
		value = v1 * base + v2
		if (value not in s):
			f.write(' '.join([str(v1), str(v2), '\n']))
			s.add(value)
	f.close()
	# shutil.move('2186.in', ''.join(['test', str(stt), '/2186.in']))
	stt = stt + 1
	time.sleep(2)
