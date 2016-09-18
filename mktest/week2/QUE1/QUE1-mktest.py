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
	f = open(''.join(name + ['/QUE1.INP']), 'w')
	f.close()

	# test_case = stt * 2
	# f.write(str(tét_case))
	# f.write('\n')
	# for tc in range(tét_case):
	# 	arlen = 10 + stt * 1000
	# 	f.write(str(arlen))
	# 	f.write('\n')
	# 	for i in range(arlen):
	# 		f.write(str(random.randint(0, 10000000)))
	# 		f.write(' ')
	# 	# ì (tc != tét_case - 1):
	# 	f.write('\n')
	# f.close()