for i in range(10):
    print(i)
    if i == 5:
        break
else:
    print("This is inside else of for")   # This will only be executed when the loop runs normally
                                          # and donot break