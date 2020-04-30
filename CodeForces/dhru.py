for _ in range(int(input())):
    k=int(input())
    a=input()
    b=input()
    flag=0
    count=0
    i=0
    while i<len(a):
        if(a[i]=='C' and b[i]=='G'):
            i+=1
            continue
        elif(a[i]=='G' and b[i]=='C'):
            i+=1
            continue
        elif(a[i]=='A' and b[i]=='T'):
            i+=1
            continue
        elif(a[i]=='T' and b[i]=='A'):
            i+=1
            continue
        else:
            count+=1
            i+=1
            if(count>k):
                flag=1
                break
    if(flag):
        print(-1)
    else:
        print(count)