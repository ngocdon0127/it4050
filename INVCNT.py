import sys

def merge_sort(a, left, right):
	if (left < right):
		mid = (left + right) / 2;
		return merge_sort(a, left, mid) + merge_sort(a, mid + 1, right) + merge(a, left, mid, right)
	return 0

def merge(a, left, mid, right):
	count = right - left + 1
	tmp = [None] * count
	i = left
	j = mid + 1
	result = 0
	for k in range(count):
		if (i > mid):
			tmp[k] = a[j]
			j = j + 1
		elif (j > right):
			tmp[k] = a[i]
			i = i + 1
		elif (a[i] < a[j]):
			tmp[k] = a[i]
			i = i + 1
		else:
			tmp[k] = a[j]
			result = result + (mid - i + 1)
			# print "i %d j %d a[i] %d a[j] %d Mid %d i %d inc %d" % (i, j, a[i], a[j], mid, i, mid - i + 1)
			j = j + 1
	for k in range(count):
		a[k + left] = tmp[k]
	return result

test_cases = int(raw_input())

for i in range(test_cases):
	a = []
	raw_input()
	n = int(raw_input())
	for j in range(n):
		a.append(int(raw_input()))
	count = 0
	print merge_sort(a, 0, n - 1)

# 0 1 2 3 4
# 2 3 8 6 1
# 2 3 8 1 6

# 6 1 : 1
# 2 1 : 2 - 0 + 1 = 3
# 8 6 : 2 - 2 + 1 = 1