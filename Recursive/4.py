def recursiveFindMax(arr, n):
    if n==1:
        return arr[0]
    else:
        if arr[n-1] > recursiveFindMax(arr,n-1): 
            return arr[n-1]
        else:
            return recursiveFindMax(arr,n-1)
n = int(input())
arr = list(map(int, input().split()))
print(recursiveFindMax(arr,n))