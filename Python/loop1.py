from turtle import *
import math

shape("turtle")

'''
for i in range(21):
    forward(10)
    penup()
    forward(3)
    pendown()
'''

for i in range(50, 100, 10):
    for j in range(4):
        forward(i)
        left(90)

'''
for i in range(4):
    forward(100)
    left(90)


right(45)
#forward(math.sqrt(2)*50)
#pendown()
circle(math.sqrt(2)*50)
'''

exitonclick()
done()