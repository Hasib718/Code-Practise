from turtle import *

color("red")
#spped()

def square(length):
    for i in range(4):
        forward(length)
        left(90)

cnt=0
while cnt < 90:
    square(100)
    right(4)
    cnt += 1

exitonclick()
done()