#x=int(input())
for _ in range(1):
    s=input()
    a=0
    b=0
    i=0
    dots=0
    precur=0
    cur=0
    while i<len(s):
        if s[i]=='X':
            ic='A'
            if cur=='.' and precur=='B':
                dots=0
            if cur=='.' and precur=='A':
                a+=dots+1
                dots=0
                cur='A'
            elif cur=='A' or ic=='A':
                a+=1
                cur='A'
        elif s[i]=='B':
            ic='B'
            if cur=='.' and precur=='A':
                dots=0
            if cur=='.' and precur=='B':
                b+=dots+1
                dots=0
                cur='B'
            elif cur=='B' or ic=='B':
                b+=1
                cur='B'
        elif s[i]=='.':
            try:
                if cur=='A':
                    cur='.'
                    precur='A'
                    dots+=1
                elif cur=='B':
                    cur='.'
                    precur='B'
                    dots+=1
                elif cur=='.':
                    dots+=1
            except:
                cur='.'
                i+=1
                continue
        i+=1
    print(a,b)

