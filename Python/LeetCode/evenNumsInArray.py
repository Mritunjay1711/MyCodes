nums = [555, 901, 482, 1771]
ans = 0
for num in nums:
    i = 0
    print(num)
    while(num):
        num = int(num / 10)
        i += 1
    print(i)  
    if(i % 2 == 0):
        ans += 1

print(ans)

