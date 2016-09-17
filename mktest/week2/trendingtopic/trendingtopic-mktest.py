import sys
import time
import random
import os
import shutil

stt = 1

for stt in range(1, 6):
	# time.sleep(2)
	name = ['test', str(stt)]
	os.mkdir(''.join(name))
	os.rename(''.join([str(stt), '.in']), 'trendingtopic.INP')
	os.rename(''.join([str(stt), '.out']), 'trendingtopic.OUT')
	shutil.move('trendingtopic.INP', ''.join(['test', str(stt), '/trendingtopic.INP']))
	shutil.move('trendingtopic.OUT', ''.join(['test', str(stt), '/trendingtopic.OUT']))
	# stt = stt + 1
	# random.seed(time.localtime().tm_sec)
	# f = open(''.join(name + ['/8queens.INP']), 'w')

	# for i in range(8):
	# 	position = random.randint(0, 7)
	# 	f.write(''.join(['.' * (position - 0)] + ['*'] + ['.' * (7 - position)] + (['\n'] if (i < 7) else [])))
	# f.close()
