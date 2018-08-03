'''
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
'''

#word = str(1234)

def sumStr(str):
    sum = 0
    #print('str',str)
    for i in range(0,len(str)):
        #print(str[i])
        sum += int(str[i])
    print(sum)


def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)


#sumStr(word)
sumStr(str( factorial(100) )) #648

#print(str(1234)[1:4])

