def OR(a, b):
    return 0 if a==b==0 else 1

def AND(a, b):
    return 1 if a==b==1 else 0

def XOR(a, b):
    return 0 if a==b else 1

def strReverse(str):
    strRev = ""
    for i in range(len(str)-1, -1, -1):
        strRev = strRev + str[i]
    return strRev

def adder(num1, num2):
    maxLen = 8
    num1 = num1.zfill(maxLen)
    num2 = num2.zfill(maxLen)

    sum = ""
    carry = 0
    num1Rev = strReverse(num1)
    num2Rev = strReverse(num2)

    for i in range (maxLen):
        sum = sum + str(XOR(XOR(int(num1Rev[i]),int(num2Rev[i])), carry))
        carry = OR(OR(AND(int(num1Rev[i]), int(num2Rev[i])), AND(int(num2Rev[i]), carry)), AND(int(num1Rev[i]), carry))

    sum = strReverse(sum)
    return sum, carry

def find2scomp(str):
    strcomp = ""
    for i in range(len(str)):
        if str[i]=='0':
            strcomp = strcomp + '1'
        else: 
            strcomp = strcomp + '0'
    strcomp, carry = adder(strcomp, '1')
    return strcomp

def subtractor(num1, num2):
    num2 = num2.zfill(8)
    num2comp = find2scomp(num2)
    diff, carry = adder(num1, num2comp)
    burrow = 1 if carry==0 else 0
    return diff, burrow

number1 = input("Enter a binary number: ")
number2 = input("Enter another binary number: ")

sum, carry = adder(number1, number2)
print(f"Sum: {sum} and Carry:{carry}")

diff, burrow = subtractor(number1, number2)
print(f"Diff: {diff} and Burrow:{burrow} \n2s Complement: -{find2scomp(diff)}")