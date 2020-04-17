x = False

while not x:
    a = int(input("first:= "))
    b = int(input("Seceond:= "))

    while True:
        operation = input("operation:= ")

        if operation == "quit":
            x = True
            break
        elif operation not in ["add", "multiplication", "division", "substraction"]:
            print("Invalid operation")
        elif operation == "add":
            print(a + b)
        elif operation == "multiplication":
            print(a * b)
        elif operation == "division":
            print(a/b)
        elif operation == "substraction":
            print(abs(a-b))