a = list(map(int, input().split(' ')))
asc = True
desc = True
for i in range(0, 7):
	if a[i] > a[i+1]:
		asc = False
	elif a[i] < a[i+1]:
		desc = False

if asc:
	print('asending')
elif desc:
	print('descding')
else:
	print('mixed')