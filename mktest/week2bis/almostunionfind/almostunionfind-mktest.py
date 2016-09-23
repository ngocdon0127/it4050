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
	# os.rename(''.join(['cookieselection.0', str(stt), '.in']), 'cookieselection.INP')
	# os.rename(''.join(['cookieselection.0', str(stt), '.ans']), 'cookieselection.OUT')
	# shutil.move('cookieselection.INP', ''.join(['test', str(stt), '/cookieselection.INP']))
	# shutil.move('cookieselection.OUT', ''.join(['test', str(stt), '/cookieselection.OUT']))
	stt = stt + 1
	random.seed(time.localtime().tm_sec)
	f = open(''.join(name + ['/almostunionfind.INP']), 'w')

	n = 10000 * (stt - 1)
	m = 10000 * (stt - 1)
	f.write(' '.join([str(n), str(m)]))
	f.write('\n')
	for i in range(m):
		operand = random.randint(1, 3)
		if (operand == 3):
			f.write(' '.join(['3', str(random.randint(1, n))]))
		else:
			f.write(' '.join([str(operand), str(random.randint(1, n)), str(random.randint(1, n))]))
		f.write('\n')
	f.close()

	# for i in range(8):
	# 	position = random.randint(0, 7)
	# 	f.write(''.join(['.' * (position - 0)] + ['*'] + ['.' * (7 - position)] + (['\n'] if (i < 7) else [])))
	# f.close()
