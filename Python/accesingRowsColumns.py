m = 2
n = 3
indices = [[0,1],[1,1]]

ans = [[0 for i in range (n)] for j in range(m)]
count = 0

b = 0    
while(b < len(indices)):
    for j in range(n):
        ans[indices[b][0]][j] = ans[indices[b][0]][j] + 1
    b = b + 1
            
    
a = 0
while(a < len(indices)):
    for i in range(m):
        ans[i][indices[a][1]] = ans[i][indices[a][1]] + 1
            
    a = a + 1
    
for i in range(m):
    for j in range(n):
        if(ans[i][j] % 2 == 1):
            count = count + 1
                
print(count)





