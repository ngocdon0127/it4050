#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Đọc input và tính lương tương ứng với các từ khóa
#
# Độ phức tạp O(n)

text = raw_input().split()
m = int(text[0])
n = int(text[1])

dic = {}

for i in range(m):
	dic_line = raw_input().split()
	dic[dic_line[0]] = int(dic_line[1])

i = 0
salary = 0

while (i < n):
	description = raw_input()
	if (description == '.'):
		i = i + 1
		print salary
		salary = 0
		continue
	words = description.split()
	for k in words:
		if (k in dic):
			salary = salary + dic[k]