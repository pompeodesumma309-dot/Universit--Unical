num=1
print("i numeri divisibili da 1 a 100 per 2,3,5 sono:")
while num<=100:
    if num%2==0 and num%3==0 and num%5==0:
        print(num)
    num+=1

