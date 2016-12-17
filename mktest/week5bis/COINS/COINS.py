#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Lời giản bài toán khi n = 1 là 1; n = 0 là 0
# Đệ quy tính số tiền đổi được nếu đổi đồng tiền thành 3 đồng có giá trị
# n / 2, n / 3 và n / 4
# So sánh với n, output giá trị cao hơn
#
# Độ phức tạp thuật toán O(n * n)

dic = {}
dic[1] = 1
dic[0] = 0

def coins(n):
	if (n not in dic):
		tmp = coins(n / 2) + coins(n / 3) + coins(n / 4)
		if (tmp > n):
			dic[n] = tmp
		else:
			dic[n] = n
	return dic[n]

while True:
	try:
		text = raw_input()
		n = int(text)
		print coins(n)
	except EOFError:
		break
