x=int(input())
for _ in range(x):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    lst=[]
    for i in range(len(a)+1):
        for j in range(i+1,len(a)+1):
            lst.append(a[i:j])
    count=0
    for i in lst:
        print(i)
        fl=0
        for j in i:
            if j%m!=0:
                fl=1
                break
        if fl==0:
            count+=1
    print(count)
