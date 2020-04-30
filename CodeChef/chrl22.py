try:
    s = str(input())
    c=h=e=f=0
    for i in s:
        if(i=="C"):
            c+=1
        elif(i=="H" and c>h):
            h+=1
        elif(i=="E" and h>e):
            e+=1
        elif(i=="F" and e>f):
            f+=1
    print(f)
except:
    pass
