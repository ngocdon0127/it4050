#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Đọc từng tọa độ vào bộ nhớ
# Xây dựng đồ thị, các đỉnh là tọa độ điểm đầu, điểm cuối và các nhà hàng
# Với mỗi đỉnh U, xây dựng tập cạnh {V} sao cho khoảng các UV không lớn hơn 1000 mét
# (chính là khoảng cách để có thể đi từ U đến V mà không hết bia)
# Dùng thuật toán BFS để tìm đường đi ngắn nhât từ điểm đầu tới điểm cuối.
#
# Nếu tìm được thì in ra happy, ngược lại in ra sad
#
# Độ phức tạp thuật toán O(m * (n + e)) với m là số test case, n là số địa điểm, 
# e là số lớn nhất trong số các cạnh của n địa điểm.

from Queue import *

offset = 40000
base = 100000
max_distance = 1000



def make_pair(a, b):
	return a * base + b

def extract_pair(pair):
	return pair / base, pair % base

def process():
	graph = {}
	mark = {}
	stores = []
	destination = 0
	n = int(raw_input())

	# Init Graph
	for i in range(n + 2):
		text = raw_input().split()
		x = int(text[0]) + offset
		y = int(text[1]) + offset
		coordination = make_pair(x, y)
		stores.append(coordination)
		mark[coordination] = 0
		for index, s in enumerate(stores):
			# mark[s] = 0
			if (index == len(stores) - 1):
				break
			x_, y_ = extract_pair(s)
			if (abs(x - x_) + abs(y - y_) <= max_distance):
				coordination_ = s
				if (coordination_ in graph):
					graph[coordination_].append(coordination)
				else:
					graph[coordination_] = [coordination]
				if (coordination in graph):
					graph[coordination].append(coordination_)
				else:
					graph[coordination] = [coordination_]
	destination = stores[len(stores) - 1]
	
	# BFS
	q = Queue()
	q.put(stores[0])
	mark[stores[0]] = 1
	while (not q.empty()):
		coordination = q.get()
		if (coordination == destination):
			print 'happy'
			return
		if (coordination in graph): # Does not know why i need to check this
			for c in graph[coordination]:
				if (mark[c] == 0):
					q.put(c)
					mark[c] = 1
	print 'sad'

test_cases = int(raw_input())

for i in range(test_cases):
	process()