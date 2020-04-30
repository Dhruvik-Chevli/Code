pro=1
fact=[1]
for i in range(1,10):
    pro*=i
    fact.append(pro)
    #print(i)
print(fact)
for _ in range(int(input())):
    n=int(input())
    a=input()
    b=input()
    a1=0
    a0=0
    b1=0
    b0=0
    for i in range(n):
        if a[i]=='1':
            a1+=1
        else:
            a0+=1
        if b[i]=='1':
            b1+=1
        else:
            b0+=1
    ans1=(fact[n]//fact[a1])//fact[a0]
    ans2=(fact[n]//fact[b1])//fact[b0]
    ans=(((ans1)%1000000007*(ans2)%1000000007)//2)%1000000007
    print(ans)

