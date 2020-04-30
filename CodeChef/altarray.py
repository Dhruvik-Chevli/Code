x=int(input())
for _ in range(x):
    n=int(input())
    fc=''
    a=list(map(int,input().split()))
    i=0
    while i<n:
        count=0
        try:
            if a[i]<0 and a[i+1]>0:
                count=count+1
                j=i+1
                while True:
                    if a[j]<0 and a[j+1]>0:
                        count+=1
                    elif a[j]>0 and a[j+1]<0:
                        count+=1
                    elif (a[j]>0 and a[j+1]>0) or (a[j]<0 and a[j+1]<0):
                        count+=1
                        break
                    j+=1
            elif a[i]>0 and a[i+1]<0:
                count=count+1
                j=i+1
                while True:
                    if a[j]<0 and a[j+1]>0:
                        count+=1
                    elif a[j]>0 and a[j+1]<0:
                        count+=1
                    elif (a[j]>0 and a[j+1]>0) or (a[j]<0 and a[j+1]<0):
                        count+=1
                        break
                    j+=1
            else:
                count=count+1
            i+=1
        except:
            count+=1
            i+=1
        fc=fc+str(count)+' '
    print(fc)
