# representing a number as 1/x + 1/y + 1/z and so on
# consider 6/14, we first find ceiling of 14/6, i.e., 3. So the first unit fraction becomes 1/3, then recur for (6/14 – 1/3) i.e., 4/42. 
import math
def egyptianFraction(nr, dr):
	print("The Egyptian Fraction " +"Representation of {0}/{1} is".format(nr, dr), end="\n")
	ef = []
	while nr != 0:
		x = math.ceil(dr / nr)
		ef.append(x)
		nr = x * nr - dr
		dr = dr * x
	for i in range(len(ef)):
		if i != len(ef) - 1:
			print(" 1/{0} +" .format(ef[i]), end = " ")
		else:
			print(" 1/{0}" .format(ef[i]), end = " ")
egyptianFraction(6, 14)