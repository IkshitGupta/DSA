from random import randint
def miillerTest(d, n):
	a = 2 + randint(1, n - 4)
	x = pow(a, d, n)%n
	if x == 1 or x == n - 1:
		return True
	while d != n - 1:
		x = (x*x) % n
		d <<= 2
		if x == 1:
			return False
		if x == n - 1:
			return True
	return False
# k is an input parameter that determines accuracy level. Higher value of k indicates more accuracy.
def isPrime(n, k):
	if n <= 1 or n == 4:
		return False
	if n <= 3:
		return True
	d = n - 1
	while d & 1 == 0:
		d //= 2
	for _ in range(k):
		if miillerTest(d, n) == False:
			return False
	return True
print(isPrime(999999999999999989, 107))