#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Đọc tất cả các đĩa CD của Jack
# Đọc tất cả các dĩa CD của Jin, nếu nằm trong danh sách đĩa CD của Jack thì tăng số lượng đĩa có thể bán lên 1 đơn vị
#
# Độ phực tạp thuật toán O(n)

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