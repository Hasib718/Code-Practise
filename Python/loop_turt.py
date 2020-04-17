from turtle import *

color("red")
speed(5)

'''
counter = 0;
while counter < 36:
    for i in range(4):
        forward(100)
        right(90)
    right(10)
    counter += 1
'''

penup()

for x in range(10):
    for y in range(10):
        dot()
        forward(20)
    if x%2==0:
        backward(20)
        right(90)
        forward(20)
        right(90)
    else:
        backward(20)
        left(90)
        forward(20)
        left(90)


exitonclick()
done()