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