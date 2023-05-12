# to input array as [a,b,c,....] of integers and then convert it to new as a real array
nums = input()
new = []
sec = []
c = list(nums)
c.remove('[')
for p in c :
    if p == ',' or p == ']' :
        ye = ''.join(sec)
        new.append(int(ye))
        sec = []
    else:
        sec.append(p)