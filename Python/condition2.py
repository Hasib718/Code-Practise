x = int(input("Give a Number:= "));

if x >= 80:
    if x >= 90:
        print("Golden A+")
    else:
        print("A+")
elif x>=70:
    print("A")
elif x>=60:
    print("B")
elif x>=50:
    print("C")
else:
    print("Fail")