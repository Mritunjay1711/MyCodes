str1 = ["ab", "c"]
str2 = ["a", "bc"]
ans1 = ""
ans2 = ""
for s in str1:
    ans1 += s

for s in str2:
    ans2 += s

print(ans1 == ans2)