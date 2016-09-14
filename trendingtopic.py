import sys

dic = {}
days = [{}] * 7
current_day = 0

def readData():
	text = raw_input()
	day = {}
	global current_day
	while (text != '</text>'):
		# print "%s:%d" % (text, len(text))
		words = text.split()
		for w in words:
			if (len(w) >= 4):
				if (w in day):
					# dic[w] = dic[w] + 1
					day[w] = day[w] + 1
				else:
					day[w] = 1
		days[current_day % 7] = day
		text = raw_input()
	current_day = current_day + 1

def query(count):
	print "<top %d>" % count
	arr = []
	dic = {}
	for i in range(7):
		day = days[i]
		for word in day:
			if (word in dic):
				dic[word] = dic[word] + day[word]
			else:
				dic[word] = day[word]
	for i in dic:
		arr.append({'word': i, 'appear': dic[i]})
	arr.sort(key=lambda element: (-element['appear'], element['word']))
	min_appear = arr[0]['appear']
	for i in range(1, count):
		min_appear = arr[i]['appear'] if (min_appear > arr[i]['appear']) else min_appear
	for i in range(len(arr)):
		if (arr[i]['appear'] >= min_appear):
			print "%s %d" % (arr[i]['word'], arr[i]['appear'])
	print '</top>'

text = raw_input()
while (True):
	# print "%s:%d" % (text, len(text))
	if (text == '<text>'):
		readData()
	elif (len(text) < 2):
		try:
			text = raw_input()
			continue
		except EOFError:
			break
	elif (text.split()[0] == '<top'):
		query(int(text.split()[1]))
	try:
		text = raw_input()
	except EOFError:
		break
	# print "%s:%d" % (text, len(text))