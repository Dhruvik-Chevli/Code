t=int(input())
while t!=0:
    s=input()
    a=str(int(s[0])-1)
    str1='9'*(len(s)-1)
    j=0
    zero=0
    for i in s:
        if i=='0':
            zero+=1
    if len(s)==1:
        print(s)
    elif zero==len(s)-1 and a=='0':
        print('9'*(len(s)-1))
    elif a!='0':
        for i in range(1,len(s)):
            if s[i]!='9':
                j=1
        if j==1:
            print((a+str1))
        else:
            print(s)
    else:
        s2=''
        k=0
        i=0
        l=0
        for i in range(len(s)-1,1,-1):
            if s[i]=='9':
                s2=s2+'9'
            else:
                k=1
                m=0
                break
        if k==0:
            print(s)
        else:
            for j in range(i-1,0,-1):
                if s[j]!='0':
                    l=1
                    m=j
            if l==1:
                for k in range(i,m,-1):
                    s2=s2+'9'
                s2=s2+str(int(s[m])-1)
                for k in range(m-1,0,-1):
                    s2=s2+s[k]
                s2=s2+'1'
                print(s2[::-1])
            else:
                print(s)
    t-=1

    
