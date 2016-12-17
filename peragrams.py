#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Lưu lại số lần xuất hiện của từng ký tự
# 1 xâu muốn là peragrams thì số ký tự có số lần xuất hiện lẻ không được lớn hơn 1
#
# Độ phức tạp thuật toán O(n)

text = raw_input()

dic = {}

for char in text:
	if (char in dic):
		dic[char] += 1
	else:
		dic[char] = 1

count = -1

for key in dic:
	if (dic[key] % 2 == 1):
		count += 1

count = 0 if (count < 0) else count
print count