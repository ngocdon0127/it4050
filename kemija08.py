#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Thay thế tất các apa thành a, epe thành e, ...
#
# Độ phức tạp thuật toán O(n)

import re

text = raw_input()

reg = [
	{
		'regex': 'apa',
		'replace': 'a'
	},
	{
		'regex': 'epe',
		'replace': 'e'
	},
	{
		'regex': 'ipi',
		'replace': 'i'
	},
	{
		'regex': 'opo',
		'replace': 'o'
	},
	{
		'regex': 'upu',
		'replace': 'u'
	}
]

for i in range(len(reg)):
	text = re.sub(reg[i]['regex'], reg[i]['replace'], text)
print text
