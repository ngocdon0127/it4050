#!/usr/bin/env python
# -*- coding: utf-8 -*-

text = raw_input()

catalog = {}
can_sell = 0

while (text != '0 0'):
	text = text.split()
	n = int(text[0])
	m = int(text[1])
	can_sell = 0
	for i in range(n):
		cd = int(raw_input())
		catalog[cd] = 1

	for i in range(m):
		cd = int(raw_input())
		if (cd in catalog):
			can_sell = can_sell + 1
	print can_sell
	catalog = {}
	text = raw_input()