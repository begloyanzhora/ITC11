""" Check function is the word name or not """
def is_name (word):
	return word[0] == word[0].upper()

def delete_symbols (sentence):
	symb = (',', ':', ';')
	for s in symb:
		sentence = sentence.replace(s, '')

	return sentence

""" Counter for name-words in a sentence """
def count_names_in_sentence (sentence):
	res = {}

	words_array = sentence.split(' ')
	for word in words_array:
		if is_name(word):
			keyword = word[0] + word[1:].lower()
			sentence = sentence.replace(word, keyword)
			if keyword not in res.keys():
				res[keyword] = 1

	return res

""" Function for merge two dictionaries """
def merge_dicts(a, b):
	for b_key in b.keys():
		if b_key in a.keys():
			a[b_key] += b[b_key]
		else:
			a[b_key] = b[b_key]

""" Counter for name-words in a text """
def count_names_in_text (text):
	if text[-1] == '.':
		text = text[:-1]

	text = delete_symbols(text)

	sentences_array = text.split('. ')
	res = {}
	for sentence in sentences_array:
		merge_dicts(res, count_names_in_sentence(sentence))
		words_arr = sentence.split(' ')

		keyword = words_arr[0][0] + words_arr[0][1:].lower()
		if res[keyword] == 1:
			del res[keyword]

	return res

""" Functon for printing the result """
def print_names (text, n):
	names = count_names_in_text (text)
	names = sorted(names.items(), key=lambda x: x[1], reverse=True)

	a = names if len(names) <= n else names[:n]
	for name in a:
		print (name[0], ':', name[1])

def main ():
	print('Input the text.')
	text = input()
	print("How many names you want to print?", end = ' ')
	n = int(input())
	print_names(text, n)

if __name__ == "__main__":
	main()