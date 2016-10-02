import sys
import time
import random
import os
import shutil

stt = 1

for stt in range(1, 5):
	# time.sleep(2)
	name = ['test', str(stt)]
	os.mkdir(''.join(name))
	os.rename(''.join(['F', str(stt), '.txt']), 'CLEANRBT.INP')
	os.rename(''.join(['F', str(stt), '.out']), 'CLEANRBT.OUT')
	shutil.move('CLEANRBT.INP', ''.join(['test', str(stt), '/CLEANRBT.INP']))
	shutil.move('CLEANRBT.OUT', ''.join(['test', str(stt), '/CLEANRBT.OUT']))
	# stt = stt + 1
	# random.seed(time.localtime().tm_sec)
	# f = open(''.join(name + ['/8queens.INP']), 'w')

	# for i in range(8):
	# 	position = random.randint(0, 7)
	# 	f.write(''.join(['.' * (position - 0)] + ['*'] + ['.' * (7 - position)] + (['\n'] if (i < 7) else [])))
	# f.close()
