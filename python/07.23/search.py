import os
import glob
import argparse
import re

parser = argparse.ArgumentParser()
parser.add_argument('--search', help = 'Name file what you are looking for', required = True)
parser.add_argument('--path', help = 'Path of directory in what you will do search', default = '.')
parser.add_argument('--include', help = 'Name files what you want to include for search', default = '*')
parser.add_argument('--exclude', help = 'Name files what you want to exclude for search', default = False)
parser.add_argument('-f', help = 'Contains only files for search', action = 'store_true')
parser.add_argument('-d', help = 'Contains only directories for search', action = 'store_true')
args = parser.parse_args()

search = args.search
path = args.path
inc = args.include
exc = args.exclude
f = args.f
d = args.d
if '*' in inc:
	inc = '\w' + inc
if exc and '*' in exc:
	exc = '\w' + exc

search = path + '/**/*' + search + '*'
files = glob.glob(search, recursive = True)

inc_reg = re.compile(inc)
files = list(filter(lambda x: inc_reg.search(os.path.basename(x)), files))

if exc:
	exc_reg = re.compile(exc)
	files = list(filter(lambda x: not exc_reg.search(os.path.basename(x)), files))

if d and f == False:
	for i in files:
		if os.path.isdir(i):
			print(i)
elif f and d == False:
	for i in files:
		if os.path.isfile(i):
			print(i)
else:
	for i in files:
		print(i)