"""
XOR decryption

decrypt the message and find the sum of the ASCII values in the original text.
"""
import string
from urllib import request


def decrypt(cipher, key):
    plain = ''
    l = len(key)
    for i, ch in enumerate(cipher):
        p = chr(ch ^ key[i % l])
        if not str.isalnum(p) and p not in string.punctuation and p not in ' \t\n':
            break
        plain += p
    return plain


cipher = eval("[{}]".format(request.urlopen("https://projecteuler.net/project/resources/p059_cipher.txt").read().decode('utf-8')))
for i in range(ord('a'), ord('z') + 1):
    for j in range(ord('a'), ord('z') + 1):
        for k in range(ord('a'), ord('z') + 1):
            plain = decrypt(cipher, [i, j, k])
            if len(plain) == len(cipher):
                pass
                # print(str([i, j, k]), plain)
# python 59.py | grep " is "
plain = decrypt(cipher, [103, 111, 100])
print(plain)
print(sum(ord(i) for i in plain))
