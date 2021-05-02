list = [["phone", "gold", "xyz"], ["phone2", "yellow", "yz"] ]
key = "gold"
for i in range(0, len(list)):
    for j in list[i]:
        if(j == key):
            print("There is one key.")