#!/usr/bin/env python
# -*- coding: utf-8 -*-


# Nếu n có hàng đơn vị bằng 9 thì chia nhỏ bài toán
# Ngược lại tính tổng các chữ số của n và giải bải toán với n - 1
#
# Độ phức tạp thuật toán O(n)

dic = {}
def f(n):
	# print 'calculating %d' % n
	if (n in dic):
		return dic[n]
	result = 0
	if (n < 10):
		for i in range(n + 1):
			result += i
		dic[n] = result
		return dic[n]
	else:
		if (n % 10 == 9):
			dic[n] = 10 * f(n / 10) + (n / 10 + 1) * 45
		else:
			dic[n] = sum_digit(n) + f(n - 1)
		return dic[n]

def sum_digit(n):
	result = 0
	while (n > 0):
		result += n % 10
		n /= 10
	return result

# print sum_digit(123)
test_cases = int(raw_input())
for i in range(test_cases):
	a, b = raw_input().split()
	print f(int(b)) - f(int(a)) + sum_digit(int(a))