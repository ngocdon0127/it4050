import sys
import time
import random
import os
import shutil

stt = 1

for stt in range(10, 11):
	# time.sleep(2)
	# name = ['test', str(stt)]
	# os.mkdir(''.join(name))
	os.rename(''.join(['phone', str(stt), '.INP']), 'phonelist.INP')
	os.rename(''.join(['phone', str(stt), '.out']), 'phonelist.OUT')
	shutil.move('phonelist.INP', ''.join(['test', str(stt), '/phonelist.INP']))
	shutil.move('phonelist.OUT', ''.join(['test', str(stt), '/phonelist.OUT']))
	# stt = stt + 1
	# random.seed(time.localtime().tm_sec)
	# f = open(''.join(name + ['/8queens.INP']), 'w')

	# for i in range(8):
	# 	position = random.randint(0, 7)
	# 	f.write(''.join(['.' * (position - 0)] + ['*'] + ['.' * (7 - position)] + (['\n'] if (i < 7) else [])))
	# f.close()
