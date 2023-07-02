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
    return sum

def find2scomp(str):
    strcomp = ""
    for i in range(len(str)):
        if str[i]=='0':
            strcomp = strcomp + '1'
        else: 
            strcomp = strcomp + '0'
    strcomp = add(strcomp, '1')
    return strcomp

def divRestoring(dividend, divisor):
    maxLen = len(dividend)+1
    A = '0'
    Q = dividend
    A = A.zfill(maxLen)
    divisor = divisor.zfill(maxLen)

    for i in range(len(dividend)):
        temp = ""
        for k in range(maxLen-1):
            temp = temp + A[k+1]
        for k in range(len(Q)):
            temp = temp+Q[k]
        A = temp[0:maxLen]
        Q = temp[maxLen:len(temp)]
        A = add(A, find2scomp(divisor))
        if A[0]=='1':
            Q = Q + '0'
            #RESTORE
            A = add(A, divisor)
        else:
            Q = Q + '1'
    
    return Q, A

def divNonRestoring(dividend, divisor):
    maxLen = len(dividend)+1
    A = '0'
    Q = dividend
    A = A.zfill(maxLen)
    divisor = divisor.zfill(maxLen)

    for i in range(len(dividend)):
        if A[0] == '0':
            temp = ""
            for k in range(maxLen-1):
                temp = temp + A[k+1]
            for k in range(len(Q)):
                temp = temp+Q[k]
            A = temp[0:maxLen]
            Q = temp[maxLen:len(temp)]
            A = add(A, find2scomp(divisor))
        else:
            A = add(A, divisor)
        if A[0]=='1':
            Q = Q + '0'
            #RESTORE
            A = add(A, divisor)
        else:
            Q = Q + '1'
    
    return Q, A

dividend = input("Enter the dividend: ")
divisor = input("Enter the divisor: ")

quotientRestoring, remainderRestoring = divRestoring(dividend, divisor)
quotientNonRestoring, remainderNonRestoring = divNonRestoring(dividend, divisor)
print(f"Quotient(Restoring): {quotientRestoring}\nRemainder(Restoring): {remainderRestoring}")
print(f"Quotient(NonRestoring): {quotientNonRestoring}\nRemainder(NonRestoring): {remainderNonRestoring}")