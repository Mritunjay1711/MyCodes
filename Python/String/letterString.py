letter = '''Dear, <|NAME|>
You are selected!

Date: <|DATE|>'''

Name = input("Enter your name: ")
Date = input("Enter date: ")
letter = letter.replace("<|NAME|>",Name)
letter = letter.replace("<|DATE|>", Date)
print(letter)