#!/usr/bin/python

chars = ''

for i in range(0x00, 0xff+1):
	res = format(i, 'X')
	
	if len(res) == 1:
		res = '0' + res

	chars += "\\x" + res

print chars
