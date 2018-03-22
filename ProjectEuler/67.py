"""
Maximum path sum II
Find the maximum total from top to bottom of the triangle below:
"""
from urllib import request
# get numbers from web
numbers = request.urlopen("https://projecteuler.net/project/resources/p067_triangle.txt").read().decode("utf-8")

numbers = [list(map(int, row.split())) for row in numbers.strip().splitlines()]
l = len(numbers)
for i in range(1, l):
    for j in range(0, i+1):
        if j == 0:
            numbers[i][j] = numbers[i][j] + numbers[i-1][j]
        elif j == i:
            numbers[i][j] = numbers[i][j] + numbers[i-1][j-1]
        else:
            numbers[i][j] = numbers[i][j] + max(numbers[i-1][j-1], numbers[i-1][j])

print(max(numbers[-1]))
