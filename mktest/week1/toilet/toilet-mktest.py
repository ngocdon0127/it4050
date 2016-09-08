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
	f = open(''.join(name + ['/toilet.INP']), 'w')

	for i in range((test + 1) * 100):
		char = random.randint(0, 10)
		f.write('U' if (char % 2 == 1) else 'D')
	f.close()
