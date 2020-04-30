x=int(input())
for _ in range(x):
    s=input()
    i=0
    count=0
    while i<len(s)-3:
        dc={'c':0,'h':0,'e':0,'f':0}
        fl=0
        if s[i] in dc:
            dc[s[i]]+=1
            j=i+1
            while j<=i+3:
                if s[j] in dc:
                    fl=1
                    dc[s[j]]+=1
                    j+=1
                else:
                    fl=0
                    break
            if fl==1:
                if dc['c']==1 and dc['h']==1 and dc['e']==1 and dc['f']==1:
                    count+=1
            i+=1
        else:
            i+=1
            continue
    if count>0:
        print('lovely',count)
    elif count==0:
        print('normal')    
