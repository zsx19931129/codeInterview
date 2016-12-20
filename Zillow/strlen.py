# Problem Description, calculate strlen, do not use length library function directly
def strlen(s, idx):
	try:
		s[idx]
		return 1 + strlen(s, idx+1)
	except IndexError:
		return 0

if __name__ == '__main__':
    s = 'best wishes!'
    assert strlen(s, 0) == len(s)