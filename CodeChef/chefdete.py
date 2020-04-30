n=int(input())
z=list(map(int,input().split()))
l=range(0,n+1)
e=''
for i in l:
    if i not in z:
        e=e+str(i)+' '
print(e)        
