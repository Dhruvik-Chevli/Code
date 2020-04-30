x=int(input())
for _ in range(x):
    s=input()
    c=0
    i=0
    while i<len(s)-1:
        if s[i]=='1' and s[i+1]=='0':
            c=c+1
        elif s[i]=='0' and s[i+1]=='1':
            c=c+1
        i=i+1
        if c>2:
            break
    if c<=2:
        print('uniform')
    else:
        print('non-uniform')                
