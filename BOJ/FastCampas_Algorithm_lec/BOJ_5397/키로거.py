tc = int(input())

for _ in range(tc):
    lstack = []
    rstack = []
    data = input()
    for i in data:
        if i == '-':
            if lstack:
                lstack.pop()
        elif i == '<':
            if lstack:
                rstack.append(lstack.pop())
        elif i == '>':
            if rstack:
                lstack.append(rstack.pop())
        else:
            lstack.append(i)
    lstack.extend(reversed(rstack))
    print(''.join(lstack))