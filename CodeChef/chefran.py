import sys
for _ in range(int(input())):
    n=int(input())
    li=[ 0 for i in range(1000001)]
    dis={}
    die={}
    mi=sys.maxsize
    ma=-sys.maxsize
    for i in range(n):
        lin,rin=map(int,input().split())
        dis[lin]=dis.get(lin,0)+1
        die[rin]=die.get(rin,0)+1
        li[lin]+=1
        li[rin+1]-=1
        if lin<mi:
            mi=lin
        if rin>ma:
            ma=rin    
    su=0
    #li=li[mi:ma+1]
    presum=[]
    for i in li:
        su+=i 
        presum.append(su)
    if 0 in presum[mi:ma+1]:
        print(-1)
        continue
    ans=sys.maxsize
    temp=None
    for i in sorted(die.keys()):    
        if dis.get(i+1,-1)==-1:
            continue
        temp=presum[i]-max(die[i],dis[i+1])
        if temp<ans:
            ans=temp
    if ans==sys.maxsize:
        print(-1)
        continue        
    print(ans)        
        

