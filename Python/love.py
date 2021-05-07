import turtle

turtle.bgcolor('black')
window = turtle.Screen()
window.screensize()
window.setup(width = 1.0, height = 1.0)

t = turtle.clone()
l = turtle.clone()
turtle.hideturtle()
t.pen(pencolor="orange", pensize=10)
t.hideturtle()

#Draw love
l.pen(pencolor="pink", pensize=1)
l.speed(10)
l.penup()
l.color("pink")
l.hideturtle()
l.goto(-20, -350)
l.pendown()
l.begin_fill()
l.left(50)
l.forward(475)
l.circle(200, 180)
l.left(260)
l.circle(200, 180)
l.forward(475)
l.end_fill()

f = t.clone()
f.penup()
f.speed(0)
f.goto(-920, 0)
f.hideturtle()

#printing 'S's
t.penup()
t.speed(0)
t.goto(-800, 0)
t.speed(3)
t.circle(90, 90)
t.pendown()
t.circle(90, 180)
t.left(46)
t.forward(240)
t.right(45)
t.circle(-90, 180)

t.penup()
t.goto(-650, 180)
t.pendown()

#Drawing 'H'
h = t.clone()
h.penup()
h.goto(-470, -170)
h.pendown()
t.left(179)
t.forward(350)
h.right(1)
h.forward(350)
h.hideturtle()

t.penup()
t.goto(-300, 180)
t.pendown()

#Drawing 'A'
a = t.clone()
t.right(20)
a.left(20)
t.forward(380)
a.forward(380)
a.hideturtle()

t.penup()
t.goto(-120, 180)
t.pendown()
t.left(20)

#Drawing 'H'
h = t.clone()
h.penup()
h.goto(60, -170)
h.pendown()
t.forward(350)
h.right(180)
h.forward(350)
h.hideturtle()

t.penup()
t.goto(110, 180)

#Drawing 'R'
t.pendown()
h = t.clone()
h.forward(350)
h.hideturtle()
t.left(90)
t.forward(50)
t.circle(-90, 180)
t.forward(50)
t.left(125)
t.forward(215)

t.penup()
t.goto(280, 180)
t.left(55)
t.pendown()

#Drawing 'I'
h = t.clone()
h.penup()
h.goto(280, -170)
h.pendown()
t.forward(180)
h.forward(180)
h.penup()
h.goto(370, -170)
h.left(90)
h.pendown()
h.forward(350)
h.hideturtle()

t.penup()
t.forward(50)

#Drawing 'N'
t.right(90)
h = t.clone()
h.pendown()
h.forward(350)
h.penup()
h.left(90)
h.forward(180)
h.left(90)
h.pendown()
h.forward(350)
h.hideturtle()
t.left(27)
t.pendown()
t.forward(395)
t.hideturtle()

#Main line
f.showturtle()
f.speed(3)
f.pendown()
f.forward(1700)


turtle.exitonclick()
turtle.done()