import sys
for _ in range(int(input())):
    a=input()
    b=input()
    la=len(a)
    lb=len(b)
    if la-lb>0:
        i=0
        while i<la-lb:
            b='0'+b
            i+=1
    else:
        i=0
        while i<lb-la:
            a='0'+a
            i+=1
    #print(a,b)
    i=len(a)-1
    ans=-sys.maxsize
    f=0
    count=0
    while i>=0:
        if f==1:
            if a[i]=='1' and b[i]=='1':
                f=0
                if ans<count:
                    ans=count
                if i==-1:
                    if ans<count:
                        ans=count
            elif a[i]=='1' and b[i]=='0':
                count+=1
                i-=1
                if i==-1:
                    if ans<count:
                        ans=count
            elif a[i]=='0' and b[i]=='1':
                count+=1
                i-=1
                if i==-1:
                    if ans<count:
                        ans=count
            elif a[i]=='0' and b[i]=='0':
                f=0
                if ans<count:
                    ans=count
        else:
            if a[i]=='1' and b[i]=='1':
                f=1
                count=1
                i-=1
                if i==-1:
                    if count>ans:
                        ans=count
            else:
                i-=1
    if ans==-sys.maxsize:
        if '1' in b:
            print(1)
        else:
            print(0)
    else:
        print(ans+1)                                    


