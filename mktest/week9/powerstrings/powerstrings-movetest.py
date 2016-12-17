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
	# os.rename(''.join(['peragrams-', '0' if stt < 10 else '', str(stt), '.in']), 'peragrams.in')
	# os.rename(''.join(['peragrams-', '0' if stt < 10 else '', str(stt), '.ans']), 'peragrams.out')
	# shutil.move('peragrams.in', ''.join(['test', str(stt), '/peragrams.in']))
	# shutil.move('peragrams.out', ''.join(['test', str(stt), '/peragrams.out']))
	# stt = stt + 1
	# random.seed(time.localtime().tm_sec)
	# f = open(''.join(name + ['/8queens.INP']), 'w')

	# for i in range(8):
	# 	position = random.randint(0, 7)
	# 	f.write(''.join(['.' * (position - 0)] + ['*'] + ['.' * (7 - position)] + (['\n'] if (i < 7) else [])))
	# f.close()
