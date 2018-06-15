"""
1000-digit Fibonacci number
What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
F1=1 F2=1
"""
a, b = 1, 1
i = 1
while len(str(a)) < 1000:
    a, b = b, a+b
    i += 1
print(i)
