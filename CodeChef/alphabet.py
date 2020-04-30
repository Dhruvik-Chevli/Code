s=input()
n=int(input())
for _ in range(n):
    w=input()
    f=1
    for i in w:
        if i not in s:
            f=0
            break
    if f==1:
        print('Yes')
    elif f==0:
        print('No')
        
