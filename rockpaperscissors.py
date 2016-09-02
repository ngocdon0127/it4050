result = {
	
}

choices = {
	'rock': {
		'paper': 1,
		'scissors': 0
	},
	'paper': {
		'scissors': 1,
		'rock': 0
	},
	'scissors': {
		'rock': 1,
		'paper': 0
	}
}

def process(text):
	# print text
	players = [int(text[0]), int(text[2])]
	choice1 = text[1]
	choice2 = text[3]
	if (not players[0] in result):
		result[players[0]] = {}
		result[players[0]]['w'] = 0
		result[players[0]]['l'] = 0

	if (not players[1] in result):
		result[players[1]] = {}
		result[players[1]]['w'] = 0
		result[players[1]]['l'] = 0
	if (choice1 != choice2):
		win = players[choices[choice1][choice2]]
		lose = players[0] if (win == players[1]) else players[1]

		result[win]['w'] = result[win]['w'] + 1
		
		result[lose]['l'] = result[lose]['l'] + 1

def output():
	# print result
	for i in result:
		if (result[i]['w'] + result[i]['l'] > 0):
			print "%.3f" % (float(result[i]['w']) / (result[i]['w'] + result[i]['l']))
		else:
			print "-"

text = raw_input().split()
n = 0
k = 0
count = 0
while (len(text) > 1):
	result = {}
	n = int(text[0])
	k = int(text[1])
	count = int(k * (n - 1) * n / 2)
	# print count
	for i in range(count):
		# print "%d: " % i
		text = raw_input().split()
		process(text)
	# print result
	output()
	text = raw_input().split()
	if (len(text) > 1):
		print ""