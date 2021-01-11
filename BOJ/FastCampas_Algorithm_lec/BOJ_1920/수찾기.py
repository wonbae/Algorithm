n = int(input())
setnums = set(map(int, input().split(' ')))
m = int(input())
num = list(map(int, input().split(' ')))

for i in num:
    if i in setnums:
        print('1')
    else:
        print('0')
