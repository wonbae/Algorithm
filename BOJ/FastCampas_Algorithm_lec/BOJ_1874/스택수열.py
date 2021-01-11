n = int(input())

cnt = 1
stack = []
result = []

for i in range(1, n+1):
    num = int(input())
    while cnt <= num:
        stack.append(cnt)
        cnt += 1
        result.append('+')
    if stack[-1] == num:
        stack.pop()
        result.append('-')
    else:
        print('NO')
        exit(0)
print('\n'.join(result))
