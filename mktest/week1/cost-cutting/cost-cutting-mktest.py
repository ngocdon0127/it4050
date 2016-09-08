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
	f = open(''.join(name + ['/cost-cutting.INP']), 'w')

	test_cases = random.randint(3, 20)
	f.write(str(test_cases))
	f.write('\n')
	for i in range(test_cases):
		f.write(' '.join([str(random.randint(1000, 10000)), str(random.randint(1000, 10000)), str(random.randint(1000, 10000))]))
		f.write('\n')
	f.close()
