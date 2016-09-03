from datetime import *

def process():
	text = raw_input().split()
	num_bookings = int(text[0])
	sec_clean = int(text[1]) * 60
	bookings = []

	for i in range(num_bookings):
		raw_booking = raw_input().split()
		start_booking = ' '.join(raw_booking[1:3])
		finish_booking = ' '.join(raw_booking[3:])
		booking = {}
		booking['start'] = datetime.strptime(start_booking, "%Y-%m-%d %H:%M")
		booking['finish'] = datetime.strptime(finish_booking, "%Y-%m-%d %H:%M")
		bookings.append(booking)

	# print bookings

	# bookings = sorted(bookings, key=lambda booking: (booking['start'], booking['finish']))
	# bookings.sort(key=lambda booking: (booking['start'], booking['finish']))
	# min_index = 0
	# for i in range(num_bookings):
	# 	if (bookings[i]['start'] < bookings[min_index]['start']):
	# 		min_index = i

	# for i in range(num_bookings):
	# 	if ((bookings[i]['start'] == bookings[min_index]['start']) and (bookings[i]['finish'] < bookings[min_index]['finish'])):
	# 		min_index = i

	# mark = [1] + [0] * (num_bookings - 1)
	mark = [0] * num_bookings
	# mark[min_index] = 1

	can_reduce = 0

	for i in range(num_bookings):
		for j in range(num_bookings):
			if (i != j):
				if ((mark[j] == 0) and (bookings[i]['finish'] <= bookings[j]['start'])):
					diff = bookings[j]['start'] - bookings[i]['finish']
					if (diff.days * 86400 + diff.seconds >= sec_clean):
						can_reduce = can_reduce + 1
						mark[j] = 1

	print num_bookings - can_reduce

n = int(raw_input())
for i in range(n):
	process()
