"""
Number spiral diagonals
What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

"""
result = 1
for i in range((1001-1)//2):
    d = 2 * (i + 1)
    s = d * (d - 1) + 1
    result += (4 * s + 6 * d)

print(result)
