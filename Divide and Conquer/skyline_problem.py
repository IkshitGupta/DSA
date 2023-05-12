def getSkyline(buildings) :
    if len(buildings) == 0 :
        return []
    if len(buildings) == 1:
        return [[buildings[0][0], buildings[0][2]], [buildings[0][1], 0]]
    mid = len(buildings)//2
    left = getSkyline(buildings[:mid])
    right = getSkyline(buildings[mid:])
    return merge(left, right)
def merge (left, right) :
    i = 0
    j = 0
    result = []
    h1 = 0
    h2 = 0
    while i < len(left) and j < len(right) :
        if left[i][0] < right[j][0] :
            h1 = left[i][1]
            newh = max(h1, h2)
            if len(result) == 0 or result[-1][1] != newh :
                result.append([left[i][0], newh])
            i += 1
        elif left[i][0] > right[j][0] :
            h2 = right[j][1]
            newh = max(h1, h2)
            if len(result) == 0 or result[-1][1] != newh :
                result.append([right[j][0], newh])
            j += 1
        else :
            h1 = left[i][1]
            h2 = right[j][1]
            newh = max(h1, h2)
            if len(result) == 0 or result[-1][1] != newh :
                result.append([right[j][0], newh])
            j += 1
            i += 1
    while i < len(left) :
        if len(result) == 0 or result[-1][1] != left[i][1] :
            result.append(left[i])
        i += 1
    while j < len(right) :
        if len(result) == 0 or result[-1][1] != right[j][1] :
            result.append(right[j])
        j += 1
    return result