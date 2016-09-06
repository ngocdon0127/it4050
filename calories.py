import sys
import re

exit_flag = 1

percent_fat = 0
percent = 0
calo_fat = 0
calo_sum = 0
calo = 0
fat = 0

calories = [9, 4, 4, 4, 7]


while (True):

	text = raw_input()
	text_ = text.split()
	if (len(text_) < 2):
		exit_flag = exit_flag - 1
		if (exit_flag < 0):
			sys.exit()
		# print
		# print fat
		# print calo
		print "%d%%" % int(round(float(fat) / calo * 100))
		percent_fat = 0
		percent = 0
		calo_fat = 0
		calo_sum = 0
		calo = 0
		fat = 0
	else:
		exit_flag = 1
		percent_fat = 0
		percent = 0
		calo_fat = 0
		calo_sum = 0

		# Fat
		result = re.findall('(\d+)(C|g|%)', text)
		if (result[0][1] == 'C'):
			calo_fat = int(result[0][0])
			calo_sum = calo_sum + int(result[0][0])
		elif (result[0][1] == '%'):
			percent = percent + int(result[0][0])
			percent_fat = int(result[0][0])
		else:
			calo_fat = int(result[0][0]) * 9
			calo_sum = calo_sum + int(result[0][0]) * 9

		# Non Fat
		for i in range(1, 5):
			if (result[i][1] == 'C'):
				calo_sum = calo_sum + int(result[i][0])
			elif (result[i][1] == '%'):
				percent = percent + int(result[i][0])
			else:
				calo_sum = calo_sum + int(result[i][0]) * calories[i]

		# print "%dC %d%% %d%% %d" % (calo_fat, percent_fat, percent, calo_sum)

		calo = calo + (float(calo_sum) / (100 - percent) * 100)
		if (result[0][1] == '%'):
			calo_fat = percent_fat * (float(calo_sum) / (100 - percent) * 100) / 100.0
		fat = fat + calo_fat

		# print "%dC %dC" % (calo_fat, calo)
		# print "%dC %dC" % (fat, calo)
