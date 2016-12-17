#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Dùng Dijkstra tạo graph biếu diễn đường đi ngắn nhất từ s đến các đỉnh còn lại.
# Duyệt đồ thị từ t. Đẩy các đỉnh vào hàng đợi. 
# Khi hàng đợi chỉ còn 1 phần tử thì đó là các phần tử mà tất cả các shortest paths đều đi qua.

# Độ phức tạp thuật toán O(M * N)

from Queue import PriorityQueue

N, M = map(int, raw_input().split())
Graph = [[] for i in range(N)]
for i in range(M):
	u, v, w = map(int, raw_input().split())
	Graph[u].append((v, w))
	# G[v].append((u,w))
s, t = map(int, raw_input().split())

D = [float('inf') for i in range(N)]
# D[v] = p
# The lowest price must take to reach v from KTH. is p.

Q = PriorityQueue()
# Queue implement Dijkstra

P = [[] for i in range(N)] 
# P[v0] = [(v1, w1), (v2, w2)]
# Shortest paths from start to v0 will have the last vertex is v1, v2, ....
# w1 = Graph[v1][v0]

# Construct graph of shortest paths
D[s] = 0
Q.put((0, s))
while not Q.empty():
	price, curStation = Q.get()
	for to, w in Graph[curStation]:
		if (price + w < D[to]):
			D[to] = price + w
			Q.put((price + w, to))
			P[to] = [(curStation, w)]
		elif price + w == D[to]:
			P[to].append((curStation, w))

Q.put((0, t))
res = []
mark = [0] * N
while not Q.empty():
	price, curStation = Q.get()
	if Q.empty():
		res.append(curStation)
	for prevStation, w in P[curStation]:
		if (mark[prevStation] == 0):
			mark[prevStation] = 1
			Q.put((price + w, prevStation))
for r in sorted(res):
	print(r),