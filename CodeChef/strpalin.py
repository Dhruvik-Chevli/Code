x=int(input())
for _ in range(x):
    a=input()
    b=input()
    for i in range(len(a)+1):
        for j in range(i+1,len(a)+1):
            sub=a[i:j]
            ssub=sub[::-1]
            f=0
            if ssub in b:
                f=1
                break
    if f==1:
        print('Yes')
    else:
        print('No')
