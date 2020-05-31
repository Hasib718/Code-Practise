x = int(input("Enter a Year:= "));

if x%100 != 0 and x%4 == 0:
    print(x, "is a leap year.");
elif x%100 == 0 and x%400 == 0:
    print(x, "is a leap year.");
else:
    print(x, "isn't a leap year.");
