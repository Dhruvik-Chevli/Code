product=1
fact=[1]*10
for i in range(1,10):
    fact[i]=fact[i-1]*i
n=input()
l=len(n)
dis={1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,0:0}
for i in n:
    dis[int(i)]+=1
lst=[]    
for i in sorted(dis.keys()):
    if dis[i]>0:
        lst.append(i)
ans=0
#print(fact)
for i in n:
    ind=lst.index(int(i))
    #print(ind)
    ans+=(fact[l-1]*(l-ind-1))
    
    #print(l,ind,ans)
    l-=1
    lst.pop(ind)
print(ans)



