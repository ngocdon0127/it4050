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
	f = open(''.join(name + ['/8queens.INP']), 'w')

	for i in range(8):
		position = random.randint(0, 7)
		f.write(''.join(['.' * (position - 0)] + ['*'] + ['.' * (7 - position)] + (['\n'] if (i < 7) else [])))
	f.close()
