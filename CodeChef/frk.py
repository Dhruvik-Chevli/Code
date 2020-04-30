n=int(input())
l=['ch','he','ef']
fr=0
for j in range(n):
    s=input()
    for i in l:
        if i in s:
            fr+=1
            break
print(fr)
