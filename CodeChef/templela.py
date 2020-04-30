x=int(input())
for _ in range(x):
    n=int(input())
    i=0
    s=''
    while i<int(n/2)+1:
        i+=1
        s=s+str(i)+' '
    while i>1:
        i-=1
        s=s+str(i)+' '
    z=input()
    s=s.strip()
    z=z.strip()
    if z==s:
        print('yes')
    else:
        print('no')
