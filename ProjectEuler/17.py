"""
Number letter counts
"""

FST = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
       "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

SEC = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]


def num2eng(num):
    if num >= 0 and num <= 19:
        return FST[num]
    elif num >= 20 and num <= 99:
        return SEC[num//10 - 2] + num2eng(num % 10)
    elif num >= 100 and num <= 999:
        return num2eng(num//100) + "hundred" + ("and" if num % 100 != 0 else "") + num2eng(num % 100)


result = 0
for i in range(1, 1000):
    result += len(num2eng(i))

result += len("onethousand")
print(result)
