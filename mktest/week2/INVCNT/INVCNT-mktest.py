#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import time
import random
import os

stt = 1

for test in range(10):
	print "starting file %d" % test
	time.sleep(2)
	name = ['test', str(stt)]
	os.mkdir(''.join(name))
	stt = stt + 1
	random.seed(time.localtime().tm_sec)
	f = open(''.join(name + ['/INVCNT.INP']), 'w')

	test_case = stt
	f.write(str(test_case))
	f.write('\n\n')
	for tc in range(test_case):
		arrlen = 10 + stt * 10000
		f.write(str(arrlen))
		f.write('\n')
		for i in range(arrlen):
			f.write(str(random.randint(0, 10000000)))
			f.write('\n')
		if (tc != test_case - 1):
			f.write('\n')
	f.close()