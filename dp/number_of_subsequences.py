# count abc
count = 0
def subs(a, i, s) :
    global count
    if s == 'abc' :
        count += 1
        return
    if i >= len(a) :
        return
    if a[i] == 'a' and s == '':
        subs(a, i + 1, 'a')
        subs(a, i + 1, s)
    elif a[i] == 'b' and s == 'a':
        subs(a, i + 1, 'ab')
        subs(a, i + 1, s)
    elif a[i] == 'c' and s == 'ab':
        subs(a, i + 1, 'abc')
        subs(a, i + 1, s)
    elif a[i] == '?' :
        subs(a[:i] + 'a' + a[i + 1:], i, s)
        subs(a[:i] + 'b' + a[i + 1:], i, s)
        subs(a[:i] + 'c' + a[i + 1:], i, s)
    else :
        subs(a, i + 1, s)
# better
count2 = 0
def m2(a, count_a, count_ab, i) :
    if i >= len(a) :
        return
    global count2
    count_a[i] = count_a[i - 1]
    count_ab[i] = count_ab[i - 1]
    if a[i] == 'a' :
        count_a[i] += 1
        m2(a, count_a, count_ab, i + 1)
    elif a[i] == 'b' :
        count_ab[i] += count_a[i]
        m2(a, count_a, count_ab, i + 1)
    elif a[i] == 'c' :
        count2 += count_ab[i]
        m2(a, count_a, count_ab, i + 1)
    elif a[i] == '?':
        count2 += count_ab[i]
        m2(a, count_a, count_ab, i + 1)
        count_ab[i] += count_a[i]
        m2(a, count_a, count_ab, i + 1)
        count_ab[i] -= count_a[i]
        count_a[i] += 1
        m2(a, count_a, count_ab, i + 1)
        count_a[i] -= 1
    else :
        m2(a, count_a, count_ab, i + 1)
a = 'ac?bs?c??aayuyaaaabb?'
subs(a, 0, '')
print(count)
count_a = [0]*len(a)
count_ab = [0]*len(a)
m2(a, count_a, count_ab, 0)
print(count2)