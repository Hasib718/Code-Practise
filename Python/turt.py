import turtle

name = turtle.textinput("Name", "What is your name?")
name = name.lower()

if name.startswith("mr"):
    print("Hello sir, how are you!")

turtle.exitonclick()
turtle.done()