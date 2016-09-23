#!/usr/bin/env python
# -*- coding: utf-8 -*-

MAX = 100100

fenwick = [0] * MAX
n = 0
smaller = [0] * MAX
bigger = [0] * MAX

def sum(index):
	result = 0
	while (index > 0):
		result += fenwick[index]
		index -= index & (-index)

	return result

def update(index, val):
	while (index <= n):
		fenwick[index] += val
		index += index & (-index)

# main

n = int(raw_input())

a = [0]

text = raw_input().split()

for t in text:
	a.append(int(t))

for i in range(n, 0, -1):
	smaller[i] = sum(a[i] - 1)
	update(a[i], 1)

fenwick = [0] * MAX

for i in range(1, n + 1):
	bigger[i] = sum(n) - sum(a[i])
	update(a[i], 1)

count = 0

for i in range(1, n + 1):
	count += smaller[i] * bigger[i]

print count