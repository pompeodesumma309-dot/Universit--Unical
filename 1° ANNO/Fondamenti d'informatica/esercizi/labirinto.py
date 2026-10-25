import random
num1=int(input("Inserisci un numero positivo: "))
num2=int(input("inserisci un numero positivo:"))
for i in range(0,num1):
    for j in range(0,num2):
        if i==0 or i==num1-1 or j==0 or j==num2-1:
            print("&", end ="")
        else:
            num3= random.randint(1,10)
            if num3<=3:
                print("&",end="")
            else:
                print("@",end="")
    print()

    


