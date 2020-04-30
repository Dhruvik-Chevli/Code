for _ in range(int(input())):
    n,k=map(int,input().split())
    li=list(map(str,input().split()))
    #li=li[::-1]
    counth=li.count('H')
    countt=li.count('T')
    for i in range(k):
        t=li.pop()
        if(t=='H'):
            for j in range(len(li)):
                if(li[j]=='H'):
                    li[j]='T'
                else:
                    li[j]='H'
    print(li.count('H'))