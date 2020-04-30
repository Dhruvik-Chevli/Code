import math
for _ in range(int(input())):
    s=input()
    i=0
    d='#'
    count=1
    su=0
    while i<len(s):
        if s[i]==d[-1]:
            i+=1
            count+=1
        else:
            d+=s[i]
            su+=int(math.log10(count))+1+1
            #print(su)
            #print(s[i])
            count=1
            i+=1
    if su<len(s):
        print('YES')
    else:
        print('NO')            

