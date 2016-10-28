
dic = {}
dic[1] = 1
dic[0] = 0

def coins(n):
	if (n not in dic):
		tmp = coins(n / 2) + coins(n / 3) + coins(n / 4)
		if (tmp > n):
			dic[n] = tmp
		else:
			dic[n] = n
	return dic[n]

while True:
	try:
		text = raw_input()
		n = int(text)
		print coins(n)
	except EOFError:
		break
