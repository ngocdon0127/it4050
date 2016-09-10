#!/usr/bin/env python
# -*- coding: utf-8 -*-

text = raw_input()

cookies = []

def arrive(d):
	cookies.append(d)
	cookies.sort()

def send():
	count = len(cookies)
	# print "count: %d" % count
	if (count % 2 == 1):
		print cookies.pop((count - 1) / 2)
	else:
		index = count / 2
		print cookies.pop(index)

while (text != None):
	if (text == '#'):
		send()
	else:
		arrive(int(text))
	try:
		text = raw_input()
	except EOFError:
		break
		# pass