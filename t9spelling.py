#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import re

key_squence = {
	'a': '2',
	'b': '22',
	'c': '222',
	'd': '3',
	'e': '33',
	'f': '333',
	'g': '4',
	'h': '44',
	'i': '444',
	'j': '5',
	'k': '55',
	'l': '555',
	'm': '6',
	'n': '66',
	'o': '666',
	'p': '7',
	'q': '77',
	'r': '777',
	's': '7777',
	't': '8',
	'u': '88',
	'v': '888',
	'w': '9',
	'x': '99',
	'y': '999',
	'z': '9999',
	' ': '0'
}

keyboards = {
	'a': '2',
	'b': '2',
	'c': '2',
	'd': '3',
	'e': '3',
	'f': '3',
	'g': '4',
	'h': '4',
	'i': '4',
	'j': '5',
	'k': '5',
	'l': '5',
	'm': '6',
	'n': '6',
	'o': '6',
	'p': '7',
	'q': '7',
	'r': '7',
	's': '7',
	't': '8',
	'u': '8',
	'v': '8',
	'w': '9',
	'x': '9',
	'y': '9',
	'z': '9',
	' ': '0'
}

def process(text, index):
	s = ['Case #', str(index), ': ']
	s.append(key_squence[text[0]])
	# print type(s)
	# print s
	pre_char = text[0]
	text = text[1:]
	# print text
	for i in text:
		if (keyboards[i] == keyboards[pre_char]):
			# print keyboards[i] == keyboards[pre_char],
			s.append(' ')
		s.append(key_squence[i])
		pre_char = i
	s = ''.join(s)
	print s

n = int(raw_input())
for i in range(n):
	text = raw_input()
	process(text.lower(), i + 1)