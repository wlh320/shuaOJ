"""
Coded triangle numbers

how many are triangle words?
"""

from urllib import request

tri = [False] * 10000
n = 1
while True:
    t = n * (n + 1) // 2
    if t > 10000:
        break
    tri[t] = True
    n += 1


def check(word):
    s = sum(ord(ch) - ord('A') + 1 for ch in word)
    return tri[s]


words = eval("[{}]".format(request.urlopen("https://projecteuler.net/project/resources/p042_words.txt").read().decode("utf-8")))

cnt = 0
for word in words:
    if check(word):
        cnt += 1
print(cnt)
