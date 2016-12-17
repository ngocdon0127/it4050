#!/usr/bin/env python
# -*- coding: utf-8 -*-

# while True:
# 	text = raw_input()
# 	if (text == '.'):
# 		break
# 	s_len = len(text)
# 	result = 1
# 	for sub_len in range(1, s_len / 2 + 1):
# 		if (s_len % sub_len == 0):
# 			first = text[0:sub_len]
# 			check = True
# 			for i in range(sub_len, s_len - sub_len + 1, sub_len):
# 				cur_sub_string = text[i:i + sub_len]
# 				if (first != cur_sub_string):
# 					check = False
# 					break
# 			if (check):
# 				result = s_len / sub_len
# 				break
# 	print result

# import re

# while True:
# 	text = raw_input()
# 	if (text == '.'):
# 		break
# 	s_len = len(text)
# 	result = 1
# 	for sub_len in range(1, s_len / 2 + 1):
# 		if (s_len % sub_len == 0):
# 			arr = re.findall('.' * sub_len, text)
# 			dic = {}
# 			check = True
# 			for e in arr:
# 				dic[e] = 1
# 				if (len(dic) > 1):
# 					check = False
# 					break
# 			if (check):
# 				# print 'sub_len: %d' % sub_len
# 				result = s_len / sub_len
# 				break
# 	print result

while True:
	text = raw_input()
	if (text == '.'):
		break
	tmp = text[1:] + text
	p = tmp.index(text)
	print len(text) / (p + 1)