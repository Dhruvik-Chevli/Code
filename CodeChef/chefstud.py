x=int(input())
for _ in range(x):
    s=input()
    i=0
    count=0
    for i in range(len(s)-1):
        if s[i]=='<' and s[i+1]=='>':
            count=count+1
    print(count)
