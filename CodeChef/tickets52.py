# cook your dish here
t=int(input())
for z in range(t):
    s=input()
    l=len(s)
    m=2
    i=0
    while i<l:
        if s[0]!=s[i]:
            m=0
        i+=2
    i=1
    while i<l:
        if s[1]!=s[i]:
            m=0
        i+=2
    if s[0]==s[1]:
        m=0
    if m==2:
        print("YES")
    else:
        print("NO")
