def gcd(a, b):
    if a > b:
        if b == 0:
            return a
        else:
            gcd(b, a % b)
    else:
        if a == 0:
            return b
        else:
            gcd(a, b % a)
