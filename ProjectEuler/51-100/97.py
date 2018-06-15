"""
Large non-Mersenne prime

28433^27830457+1
Find the last ten digits of this prime number.
"""
p = (pow(2, 7830457, 10**10) * 28433) % 10**10 + 1
print(p)
