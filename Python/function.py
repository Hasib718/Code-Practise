def average(List):
    a = List
    res = 0
    for x in a:
        res+=x
    return res/len(List)

def namta(x=1):
    for i in range(1, 11):
        print(i, " * ", x, " = ", i*x)

List = [23, 465, 345, 35, 345, 345, 35, 656]

#print(average(List))
namta()