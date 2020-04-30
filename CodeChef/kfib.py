n,k=map(int,input().split())
lst=[1]*k
for i in range(n-k):
    lst.append(sum(lst))
    lst.pop(lst[0])
print(lst[k-1])    
