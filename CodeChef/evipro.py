for _ in range(int(input())):
    s=input()
    sf=''
    for i in s:
        if i=='0':
            sf+='1'
        else:
            sf+='0'
    sf='0b'+sf 
    #print(sf)
    print(int(sf,2))           