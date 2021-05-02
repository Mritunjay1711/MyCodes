# Similar to structures
# Dictionary stores two value pairs

myDict = {
    "Adarsh": "Nonsense",
    "Mj": "A Coder",
    "Marks": [1, 7, 5],
    "anotherDict": {"mj": "Gamer"}
    }

print(myDict['Adarsh'])
print(myDict['Mj'])
print(myDict['Marks'])
print(myDict['anotherDict'])
print(myDict['anotherDict']['mj'])

# Mutable i.e We can change the content
myDict['Marks'] = [8, 4, 2]

print(myDict['Marks'])