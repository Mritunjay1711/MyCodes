myDict = {
    "adarsh": "Nonsense",
    "mj": "A Coder",
    "marks": [1, 7, 5],
    "anotherDict": {"mj": "Gamer"},
    1 : 2
    }


print(list(myDict.keys()))  #prints the keys and also type cast
print(myDict.values()) # Prints the values of the dictionary
print(myDict.items()) # Prints the items(key, values) of the dictionary
print(myDict)
updateDict = {
    "Guinea": "Pigs",
    "Littlebacha": "Friend"
}
myDict.update(updateDict)  # Updated the dictionary with supplied key-values pairs
print (myDict)

print(myDict.get('mj'))  # This will not throw any error even it does not find the element istead
                         # returns NONE
print(myDict['mj'])   # This will throw error if it doesnot find the element 

