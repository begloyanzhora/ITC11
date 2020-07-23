import re

""" Check line type """
def parser_line_type (line):
	parts = line.split(' ')
	if parts[1].isnumeric() and parts[2].isnumeric():
		return 'numeric'

	return 'text'


""" Create arrays for numeric and text lines """
def allocate_lines_by_type (lines_arr, text_arr, numb_arr):
	for line in lines_arr:
		if parser_line_type(line) == 'numeric':
			numb_arr.append(line)
		else:
			text_arr.append(line)

""" Compare numeric part of line (without key)"""
def compare_int_line (l1, l2):
	parts1 = l1.split(' ')
	parts2 = l2.split(' ')

	i = 1
	for i in range(3):
		if parts1[i] > parts2[i] or (parts1[i] == parts2[i] and parts1[i + 1] > parts2[i + 1]):
			return True
		elif parts1[i] == parts2[i] and parts1[i + 1] > parts2[i + 1]:
			return 'equal'
		return False

""" Compare text part of line (without key)"""
def compare_text_line (l1, l2):
	parts1 = l1.split(' ')
	parts2 = l2.split(' ')

	i = 1
	for i in range(3):
		if (len(parts1[i]) > len(parts2[i]) or (len(parts1[i]) == len(parts2[i]) and len(parts1[i + 1]) > len(parts2[i + 1]))) or (len(parts1[i]) == len(parts2[i]) and len(parts1[i + 1]) == len(parts2[i +1])) and (parts1[i] > parts2[i] or (parts1[i] == parts2[i] and parts1[i + 1] > parts2[i + 1])):
			return True
		elif parts1[i] == parts2[i] and parts1[i + 1] == parts2[i + 1]:
			return 'equal'
		else:
			return False

""" Compare keys """
def compare_keys (k1, k2):
	key1_num = (re.findall(r'(\w+?)(\d+)',k1))[0][1]
	key1_text = (re.findall(r'(\w+?)(\d+)',k1))[0][0]

	key2_num = (re.findall(r'(\w+?)(\d+)',k2))[0][1]
	key2_text = (re.findall(r'(\w+?)(\d+)',k2))[0][0]

	if compare_text_keys(key1_text, key2_text) == True or (compare_text_keys(key1_text, key2_text) == 'equal' and compare_int_keys(key1_num, key2_num) == True):
		return True
	elif compare_text_keys(key1_text, key2_text) == 'equal' and compare_int_keys(key1_num, key2_num) == 'equal':
		return 'equal'
	else:
		return False

""" Compare text part of keys """
def compare_text_keys (t1, t2):
	return len(t1) > len(t2) or (len(t1) == len(t2) and t1 > t2)

""" Compare numeric part of keys """
def compare_int_keys (k1, k2):
	return int(k1) > int(k2)

""" Compare whole line (text type) """
def compare_whole_text_line(line1, line2):
	line_arr1 = line1.split(' ')
	key1 = line_arr1[0]
	text1 = ' '.join(line_arr1[1:])
	line_arr2 = line2.split(' ')
	key2 = line_arr2[0]
	text2 = ' '.join(line_arr2[1:])

	return compare_keys(key1, key2) == True or (compare_keys(key1, key2) == 'equal' and compare_text_line(text1, text2) == True)

""" Compare whole line (numeric type) """
def compare_whole_int_line(line1, line2):
	line_arr1 = line1.split(' ')
	key1 = line_arr1[0]
	text1 = ' '.join(line_arr1[1:])
	line_arr2 = line2.split(' ')
	key2 = line_arr2[0]
	text2 = ' '.join(line_arr2[1:])

	return compare_keys(key1, key2) == True or (compare_keys(key1, key2) == 'equal' and compare_int_line(text1, text2) == True)

""" Sort lines and return sorted array """
def sort_lines(lines_arr):
	text_arr = []
	numb_arr = []
	result = []
	allocate_lines_by_type(lines_arr, text_arr, numb_arr)

	for i in range(len(text_arr)):
		for j in range(len(text_arr) - 1):
			if compare_whole_text_line(text_arr[j], text_arr[j + 1]):
				text_arr[j], text_arr[j + 1] = text_arr[j + 1], text_arr[j]

	for i in range(len(numb_arr)):
		for j in range(len(numb_arr) - 1):
			if compare_whole_text_line(numb_arr[j], numb_arr[j + 1]):
				numb_arr[j], numb_arr[j + 1] = numb_arr[j + 1], numb_arr[j]

	result = text_arr + numb_arr

	return result

def main ():
	lines_arr = ['wz3 fdgf dfgd', 'mi2 jog mid', 'avvv5 alps cow',
             'x5 45 27', 'a1 alps blov', 'a1 alps bloz', 'axe5 455 27',
             'a5 25 80','a6 25 70','tx5 405 97']

	for line in sort_lines(lines_arr):
		print(line)

if __name__ == "__main__":
	main()