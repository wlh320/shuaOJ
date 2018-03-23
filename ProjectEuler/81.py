"""
Path sum: two ways
Find the minimal path sum, in matrix.txt
"""
from urllib import request
mat = request.urlopen("https://projecteuler.net/project/resources/p081_matrix.txt").read().decode("utf-8").strip().splitlines()
mat = [list(map(int, row.split(','))) for row in mat]
rows = len(mat)
cols = len(mat[0])
for i in range(1, rows):
    mat[i][0] += mat[i-1][0]
for i in range(1, cols):
    mat[0][i] += mat[0][i-1]
for i in range(1, rows):
    for j in range(1, cols):
        mat[i][j] = min(mat[i-1][j], mat[i][j-1]) + mat[i][j]
print(mat[rows - 1][cols - 1])
