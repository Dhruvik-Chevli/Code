x=int(input())
for _ in range(x):
    s=input()
    if s[0]=='U':
        su=1
        sd=0
    elif s[0]=='D':
        sd=1
        su=0
    for i in range(len(s)-1):
        if s[i]=='U' and s[i+1]=='D':
            sd+=1
        elif s[i]=='D' and s[i+1]=='U':
            su+=1
    print(min(sd,su))
