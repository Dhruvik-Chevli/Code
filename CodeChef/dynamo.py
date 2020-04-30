for _ in range(int(input())):
    n = int(input())
    a = int(input())
    print(2*(10**n)+a, flush=True)
    b = int(input())
    print(10**n-b, flush=True)
    d = int(input())
    print(10**n-d, flush=True)
    res = int(input())
    if res == -1:
        break
