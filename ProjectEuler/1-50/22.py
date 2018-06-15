"""
Names scores

working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
"""

from urllib import request

names = eval("[{}]".format(request.urlopen("https://projecteuler.net/project/resources/p022_names.txt").read().decode('utf-8')))
names.sort()
result = 0
for i, name in enumerate(names):
    score = sum([ord(ch)-ord('A')+1 for ch in name]) * (i+1)
    result += score
print(result)
