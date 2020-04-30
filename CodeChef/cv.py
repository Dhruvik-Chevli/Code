x=int(input())
for _ in range(x):
    n=int(input())
    s=input()
    count=0
    i=0
    lst=['a','e','i','o','u']
    while i<n-1:
        if s[i] not in lst and s[i+1] in lst:
            count+=1
        i+=1
    print(count)     
