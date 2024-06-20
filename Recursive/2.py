n = int(input())

def recursivePrint(n):
    mod = n % 10
    if (n//10) ==0:
        print(mod)
        return
    else:
        recursivePrint(n//10)
        print(mod)
recursivePrint(n)