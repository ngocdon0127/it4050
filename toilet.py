# 
# Thực hiện tuần tự các thao tác
#
# Độ phức tạp thuật toán: O(n)


def process1(states):
	current_state = initial
	policy = 0
	for i in states:
		if (i != current_state):
			policy = policy + 1
		if (i != 'U'):
			policy = policy + 1
		current_state = 'U'

	return policy

def process2(states):
	current_state = initial
	policy = 0
	for i in states:
		if (i != current_state):
			policy = policy + 1
		if (i != 'D'):
			policy = policy + 1
		current_state = 'D'

	return policy

def process3(states):
	current_state = initial
	policy = 0
	for i in states:
		if (i != current_state):
			policy = policy + 1
			current_state = i

	return policy

x = raw_input()
initial = x[0]
x = x[1:]
# print initial
print process1(x)
print process2(x)
print process3(x)