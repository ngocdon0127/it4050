#!/usr/bin/env python
# -*- coding: utf-8 -*-

# phonelist là cây, mỗi nút có nhãn là 1 chữ số.
# Mỗi khi đọc được 1 số điện thoại, gán cur_pointer vào gốc của phonelist
# Duyệt từng chữ số i của số điện thoại đó, 
# Kiểm tra xem nếu cur_pointer[i] == -1 thì in ra NO,
# Ngược lại tạo cây con cho cur_pointer và gán cur_pointer = cur_pointer[i]
# Duyệt xong số điện thoại, gán cur_pointer[last_digit] = -1,
# đánh dấu lại đó là kết thúc của 1 số điện thoại
#
# Độ phức tạp O(n)

test_cases = int(raw_input())

def process():
	num_phones = int(raw_input())
	phonelist = {}
	check = True
	for j in range(num_phones):
		phone = raw_input()
		cur_pointer = phonelist
		for index, char in enumerate(phone):
			if (char in cur_pointer and cur_pointer[char] == -1):
				# print 'NO'
				check = False
			if (check):
				if (index == len(phone) - 1):
					# print phonelist
					# print '-1 ne'
					if (char in cur_pointer):
						check = False
					else:
						cur_pointer[char] = -1
				else:
					if (not char in cur_pointer):
						cur_pointer[char] = {}
					cur_pointer = cur_pointer[char]
		# print phonelist
	print 'YES' if check else 'NO'
	return


for i in range(test_cases):
	process()