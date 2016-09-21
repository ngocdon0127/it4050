#!/usr/bin/env python
# -*- coding: utf-8 -*-

from Queue import *

offset = 40000
base = 100000
max_distance = 1000



def make_pair(a, b):
	# min_ = a if (a < b) else b
	# max_ = a if (a > b) else b
	# return min_ * base + max_
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
	# for s in stores:
	# 	mark[s] = 0
	# print 'graph'
	# print graph
	# print 'mark'
	# print mark
	# print 'stores'
	# print stores
	# return
	# BFS
	q = Queue()
	q.put(stores[0])
	mark[stores[0]] = 1
	while (not q.empty()):
		coordination = q.get()
		if (coordination == destination):
			print 'happy'
			return
		if (coordination in graph): # Does know why i need to check this
			for c in graph[coordination]:
				if (mark[c] == 0):
					q.put(c)
					mark[c] = 1
	print 'sad'

test_cases = int(raw_input())

for i in range(test_cases):
	process()