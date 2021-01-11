n, m = list(map(int, input().split(' ')))
data = list(map(int, input().split(' ')))

res = 0
length = len(data)

for i in range(0, length):
    for j in range(i + 1, length):
        for k in range(j + 1, length):
            sumvalue = data[i] + data[j] + data[k]
            if sumvalue <= m:
                res = max(res, sumvalue)
print(res)
