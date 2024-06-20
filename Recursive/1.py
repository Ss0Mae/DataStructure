def recursiveSum(n):
    if n == 0:
        return 0
    else:
        return n + recursiveSum(n-1)
n = int(input())
print(recursiveSum(n))