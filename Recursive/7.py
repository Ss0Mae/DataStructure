def recursiveCharacterSearchCount(s, c, i):
    if i == len(s):
        return 0
    if s[i] == c:
        return 1 + recursiveCharacterSearchCount(s, c, i + 1)
    return recursiveCharacterSearchCount(s, c, i + 1)


str = input()
char = input()
print(recursiveCharacterSearchCount(str, char, 0))
