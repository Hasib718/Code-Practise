import queue
import threading
import turtle

def tes1():
    for _ in range(360):
        graphics.put(turtle1.forward)
        graphics.put(turtle1.left)

def tes2():
    for _ in range(360):
        graphics.put(turtle2.forward)
        graphics.put(turtle2.right)

def process_queue():
    while not graphics.empty():
        (graphics.get())(1)

    if threading.active_count() > 1:
        turtle.ontimer(process_queue, 100)

graphics = queue.Queue(1)  # size = number of hardware threads you have - 1

turtle1 = turtle.Turtle('turtle')
turtle1.speed('fastest')
thread1 = threading.Thread(target=tes1)
thread1.daemon = True  # thread dies when main thread (only non-daemon thread) exits.
thread1.start()

turtle2 = turtle.Turtle('turtle')
turtle2.speed('fastest')
thread2 = threading.Thread(target=tes2)
thread2.daemon = True  # thread dies when main thread (only non-daemon thread) exits.
thread2.start()

process_queue()

turtle.exitonclick()