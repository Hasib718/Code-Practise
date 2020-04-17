result = 0

for i in range(1, 51, 2):
    result += i

print(result)

for i in range(1, 101, 2):
    if i%5==0:
        result+=i

print(result)