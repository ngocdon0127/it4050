import sys
import time
import random
import os
import shutil

stt = 1

for stt in range(1, 8):
	# time.sleep(2)
	name = ['test', str(stt)]
	os.mkdir(''.join(name))
	os.rename(''.join(['cookieselection.0', str(stt), '.in']), 'cookieselection.INP')
	os.rename(''.join(['cookieselection.0', str(stt), '.ans']), 'cookieselection.OUT')
	shutil.move('cookieselection.INP', ''.join(['test', str(stt), '/cookieselection.INP']))
	shutil.move('cookieselection.OUT', ''.join(['test', str(stt), '/cookieselection.OUT']))
	# stt = stt + 1
	# random.seed(time.localtime().tm_sec)
	# f = open(''.join(name + ['/8queens.INP']), 'w')

	# for i in range(8):
	# 	position = random.randint(0, 7)
	# 	f.write(''.join(['.' * (position - 0)] + ['*'] + ['.' * (7 - position)] + (['\n'] if (i < 7) else [])))
	# f.close()
