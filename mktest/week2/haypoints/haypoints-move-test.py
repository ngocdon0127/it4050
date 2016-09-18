import sys
import time
import random
import os
import shutil

stt = 1

for stt in range(8, 11):
	# time.sleep(2)
	name = ['test', str(stt)]
	os.mkdir(''.join(name))
	os.rename(''.join(['haypoint-', str(stt), '.INP']), 'haypoints.INP')
	# os.rename(''.join(['haypoints.0', str(stt), '.ans']), 'haypoints.OUT')
	shutil.move('haypoints.INP', ''.join(['test', str(stt), '/haypoints.INP']))
	# shutil.move('haypoints.OUT', ''.join(['test', str(stt), '/haypoints.OUT']))
	stt = stt + 1
	# random.seed(time.localtime().tm_sec)
	# f = open(''.join(name + ['/8queens.INP']), 'w')

	# for i in range(8):
	# 	position = random.randint(0, 7)
	# 	f.write(''.join(['.' * (position - 0)] + ['*'] + ['.' * (7 - position)] + (['\n'] if (i < 7) else [])))
	# f.close()
