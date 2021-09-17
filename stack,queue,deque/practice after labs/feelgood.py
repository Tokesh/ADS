n = int(input())
arr=list(map(int, input().split()))
l=0
r=n-1
sumi=sum(arr[l:r+1])
mini=min(arr[l:r])
total = sumi*mini
cnt = 0
while(r > l and cnt < 200000):
    #Удаляю правую сторону, проверяя минимальное число
    if(arr[r] == mini): mini = min(arr[l:r-1])

    temp_1 = sumi - arr[r] # сумма без правой стороны
    var1 = temp_1 * mini #Общее число без правой стороны
    if(var1 > total):
        r -= 1  
        sumi = temp_1
        total = var1  
        print(arr[r], end='\n')  
    
    
    #Удаляю левую сторону, проверяя минимальное число
    if(arr[l] == mini): mini = min(arr[l+1:r])
    temp_2 = sumi - arr[l] # сумма без левой стороны
    var2 = temp_2 * mini #Общее число без левой стороны
    if(var2 > total):
        print(arr[l], end='\n')  
        l += 1  
        sumi = temp_2
        total = var2
    cnt += 1
print(total)
print(l,r,mini,sumi)
print(sum(arr[l:r+1])*min(arr[l:r]))


