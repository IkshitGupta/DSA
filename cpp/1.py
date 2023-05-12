def xorN (n) :
    rem = n%4
    if rem == 0:
        return n
    elif rem == 1:
        return 1
    elif rem == 2:
        return n + 1
    return 0