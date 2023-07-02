def OR(a, b):
    return 0 if a==b==0 else 1
def AND(a, b):
    return 1 if a==b==1 else 0
def XOR(a, b):
    return 0 if a==b else 1

def add(num1, num2):
    maxLen = max(len(num1), len(num2))
    num1 = num1.zfill(maxLen)
    num2 = num2.zfill(maxLen)

    sum = ""
    carry = 0
    for i in range(maxLen-1, -1, -1):
        sum = str(XOR(XOR(int(num1[i]),int(num2[i])), carry)) + sum
        carry = OR(OR(AND(int(num1[i]), int(num2[i])), AND(int(num2[i]), carry)), AND(int(num1[i]), carry))
    sum = '1' + sum if carry == 1 else sum
    return sum

def mult(multiplicand, multiplier):
    n = len(multiplier)
    prod = ""
    for i in range(n-1, -1, -1):
        if multiplier[i]=='1':
            prod = add(prod, multiplicand)
        multiplicand = multiplicand + '0' #left shift multiplicand
    return prod

multiplicand = input("Enter the multipicand: ")
multiplier = input("Enter the multiplier: ")

result = mult(multiplicand, multiplier)
print(f"Product: {result}")