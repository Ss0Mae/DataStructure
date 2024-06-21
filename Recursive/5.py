def towersOfHanoi(n, start, end, sub):
    if n == 1:
        print("Move disk 1 from rod", start, "to rod", end)
        return
    else:
        towersOfHanoi(n-1, start, end, sub)
        print("Move disk", n, "from rod", start, "to rod", end)
        towersOfHanoi(n-1, sub, start, end)


towersOfHanoi(3, 'A', 'C', 'B')
