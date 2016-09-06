import sys
import time
import random
import os

stt = 1

for test in range(10):
	time.sleep(2)
	name = ['test', str(stt)]
	os.mkdir(''.join(name))
	stt = stt + 1
	random.seed(time.localtime().tm_sec)
	f = open(''.join(name + ['/chess.INP']), 'w')

	test_case = 3 + test * 10
	f.write(str(test_case))
	f.write('\n')
	for k in range(test_case):
		x1 = random.randint(0, 7) + 65
		y1 = random.randint(0, 7)
		x2 = random.randint(0, 7) + 65
		y2 = random.randint(0, 7)
		line = [unichr(x1), str(y1), unichr(x2), str(y2)]
		f.write(' '.join(line))
		f.write('\n')
	f.close()
