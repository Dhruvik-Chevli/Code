for _ in range(int(input())):
    n=int(input())
    ans=(((2**(n-1))%1000000007)-2)%1000000007
    print(ans)    