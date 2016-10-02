import sys
import time
import random
import os
import shutil

stt = 1

for stt in range(1, 11):
	# time.sleep(2)
	name = ['test', str(stt)]
	os.mkdir(''.join(name))
	os.rename(''.join(['test', str(stt), '.inp']), '1010.INP')
	os.rename(''.join(['test', str(stt), '.out']), '1010.OUT')
	shutil.move('1010.INP', ''.join(['test', str(stt), '/1010.INP']))
	shutil.move('1010.OUT', ''.join(['test', str(stt), '/1010.OUT']))
	# stt = stt + 1
	# random.seed(time.localtime().tm_sec)
	# f = open(''.join(name + ['/8queens.INP']), 'w')

	# for i in range(8):
	# 	position = random.randint(0, 7)
	# 	f.write(''.join(['.' * (position - 0)] + ['*'] + ['.' * (7 - position)] + (['\n'] if (i < 7) else [])))
	# f.close()