import math

for _ in range(int(input())):
    x, n, m = map(int, input().split())

    p = x
    for j in range(1, n+1):
        x = math.floor(x/2) + 10
        if x < 0:
            break
        elif x > p:
            x = p
            break
        p = x
            
    while (x > 0 and m > 0):
        x -= 10
        m -= 1

    if (x < 1):
        print("YES")
    else:
        print("NO")