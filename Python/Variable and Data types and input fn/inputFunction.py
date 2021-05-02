#Input function always take input as a string type 
# We need to change type by typecasting it

# a = input("Enter you name: ")
# a = int(a)
# print(a)
# print(type(a))

a = input("Enter your name: ")
b = "Good Afternoon, "
b += a
print(b)