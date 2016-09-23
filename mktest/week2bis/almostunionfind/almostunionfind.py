#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Tạo n tập đánh số từ 1 đến n
# group[i] = j nghĩa là phần từ i đang nằm ở tập có chỉ số j
# các phần tử của tập thứ i được liệt kê trong mảng elements[i]
# tổng của các phần tử trong tập thứ i được lưu tại biến sum_group[i]

# Duyệt qua mỗi thao tác, cập nhật 3 biến trên cho phù hợp với từng thao tác và in ra màn hình nếu gặp yêu cầu

# Độ phức tạp thuật toán O(t * m * n) với t là số test case, m là số thao tác và k là số phần từ

def process(text):
	n = int(text[0])
	m = int(text[1])

	# Init
	group = {}
	elements = {}
	sum_group = {}
	for i in range(1, n + 1):
		group[i] = i
		elements[i] = [i]
		sum_group[i] = i

	# print "-----"
	# print group
	# print elements
	# print sum_group
	# print "-----"

	# Process
	for i in range(m):
		# print "-----"
		text = raw_input().split()
		operand = int(text[0])
		if (operand == 1):
			# print "operand %d" % operand
			p, q = int(text[1]), int(text[2])
			if (group[p] != group[q]):
				g_min = group[p] if (len(elements[group[p]]) <= len(elements[group[q]])) else group[q]
				g_max = group[p] if (len(elements[group[p]]) > len(elements[group[q]])) else group[q]
				# print "g_min %d g_max %d" % (g_min, g_max)
				# print "elements before"
				# print elements[g_max]
				elements[g_max] += elements[g_min]
				# print "elements after"
				# print elements[g_max]
				for e in elements[g_min]:
					group[e] = g_max
				elements[g_min] = []
				sum_group[g_max] += sum_group[g_min]
				sum_group[g_min] = 0
		elif (operand == 2):
			# print "operand %d" % operand
			p, q = int(text[1]), int(text[2])
			if (group[p] != group[q]):
				elements[group[q]].append(p)
				sum_group[group[q]] += p
				sum_group[group[p]] -= p
				elements[group[p]].pop(elements[group[p]].index(p))
				group[p] = group[q]
		else:
			# print "operand %d" % operand
			p = int(text[1])
			print "%d %d" % (len(elements[group[p]]), sum_group[group[p]])

		# print group
		# print elements
		# print sum_group
		# print "-----"



while True:
	try:
		text = raw_input()
		process(text.split())
	except EOFError:
		break