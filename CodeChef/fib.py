li=[1,1]
t=int(input())
for i in range(2,t+1):
    li.append(li[-1]+li[-2])
print(li[t])    
