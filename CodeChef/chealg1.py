for _ in range(int(input())):
    s=input()
    d=''
    count=1
    i=1
    cur=s[0]
    s+='#'
    while(i<len(s)):
        if s[i]!=cur:
            d=d+cur+str(count)
            count=1
            cur=s[i]
            i+=1
        else:
            count+=1
            i+=1
    #print(d,s);        
    if(len(d)<len(s[1:])):
        print('YES')
    else:
        print('NO')                