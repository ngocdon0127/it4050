#!/usr/bin/env python
# -*- coding: utf-8 -*-

def process():
	# social = 1
	dic = {}
	data = {}
	# arr.append(dic)
	index = 0
	friendships = int(raw_input())
	for i in range(friendships):
		# check = False
		text = raw_input().split()
		position = 0

		# for j in range(len(arr)):
		if ((text[0] in dic) and (text[1] in dic)):
			# print 'hehe1hehe'
			if (dic[text[0]] != dic[text[1]]):
				data[dic[text[0]]] += data[dic[text[1]]]
				pos = dic[text[1]]
				for t in data[pos]:
					dic[t] = dic[text[0]]
				del data[pos]
				# dic[text[1]] = dic[text[0]]
			position = dic[text[0]]
		elif ((text[0] in dic) or (text[1] in dic)):
			# print 'hehe2hehe'
			f1 = text[0] if (text[0] in dic) else text[1]
			f2 = text[1] if (text[0] in dic) else text[0]
			# value = text[0] if (text[1] in dic) else text[1]
			data[dic[f1]].append(f2)
			dic[f2] = dic[f1]
			position = dic[f1]
		else:
			# print 'hehe3hehe'
			data[index] = [text[0], text[1]]
			position = index
			dic[text[0]] = position
			dic[text[1]] = position
			index += 1
		# print dic
		# print data
		print len(data[position])
		



test_cases = int(raw_input())

for i in range(test_cases):
	process()