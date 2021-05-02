num = int(input("Enter the num: "))

for i in range(1, 11):
    print(str(num) + "X" + str(i) + "=" + str(i*num))


for i in range(1, 11):
    print(f"{num}X{i}={num*i}")                  # f string