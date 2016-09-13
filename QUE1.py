import sys

def order(heights, tallers, index, count):
	minIndex = 0
	for i in range(index, count):
		if (tallers[i] == 0):
			minIndex = i
			break
	for i in range(index + 1, count):
		if (tallers[i] == 0 and heights[i] < heights[minIndex]):
			minIndex = i
	# print "before swapping minIndex = %d index = %d" % (minIndex, index)
	# print heights
	# print tallers
	heights[minIndex], heights[index] = heights[index], heights[minIndex]
	tallers[minIndex], tallers[index] = tallers[index], tallers[minIndex]
	for i in range(index, count):
		if (heights[i] < heights[index]):
			tallers[i] = tallers[i] - 1
	# print "after swapping"
	# print heights
	# print tallers

def process():
	n = int(raw_input())
	heights = []
	raw_heights = raw_input().split()
	for i in range(n):
		heights.append(int(raw_heights[i]))
	tallers = []
	raw_tallers = raw_input().split()
	for i in range(n):
		tallers.append(int(raw_tallers[i]))
	for i in range(n):
		order(heights, tallers, i, n)
	print ' '.join(map(lambda x: str(x), heights))

test_cases = int(raw_input())

for i in range(test_cases):
	process()
