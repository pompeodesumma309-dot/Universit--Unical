#ESERCIZI SULLE ITERZIONI
#es1
for i in range(1,11):
    print(i)

#es2
for j in range(10,0,-1):
    print(j)

#es3
num1=int(input("Inserisci un numero per fare il conto alla rovescia:"))
for i2 in range(num1,0,-1):
    print(i2)

#es4
for i3 in range(2,22,2):
    print(i3)

#es5
print("es5")
for i4 in range(1,20,2):
    print(i4)

#es7
stringa=str(input("Inserisci una parola:"))
n=stringa*len(stringa)
print(n)

#es8
numeri = list(range(1, 11))
print("I primi 10 numeri interi positivi sono:")
for numero in numeri:
    print(numero)
somma = sum(numeri)
print("La loro somma è:", somma)

#es9
for i7 in range(0,21):
    if i7%3==0:
     print(i7)

#es10
num2=int(input("Inserisci ik primo numero:"))
num3=int(input("Inserisci il secondo numero:"))
somma2=num2+num3
for i8 in range(1,101):
    if i8!=somma2:
        print(i8)
    else:
        i8==somma2
        print("ciclo terminato.")
        break

#es11
num4=int(input("Inserisci il primo numero:"))
num5=int(input("Inserisci il secondo numero:"))
for j3 in range(1,num4):
    if j3!=num5:
        print(j3)
    else:
        j3==num5
        break

#es12
stringa2="Python"
for lettera in stringa2:
    print(lettera)

#es14
for j4 in range(1,11):
    quadrato=j4**2
    print(f"il quadrato del numero {j4} e': {quadrato}")

#es15
for j5 in range(1,51):
    if j5%5!=0:
        print(j5)

#es16
num6=int(input("Inserisci il numero di cui vuoi la tabellina del quadrato:"))
quadrato3=num6**2
for j8 in range(1,11):
    risultato=quadrato3*j8
    print(f"{quadrato3} x {j8}= {risultato}")

#es17
for i10 in range(101,1,-1):
    if i10%4==0:
        print(i10)

#es18
num7=int(input("Inserisci un numero per la somma:"))
for i11 in range(0,num7):
    num7+=i11
print("La somma e':",num7)

#es19
num8=int(input("insersci in numero per avere il suo fattoriale:"))
fattoriale=1
for i12 in range(1,num8+1):
    fattoriale*=i12
print(f"Il fattoriale del numero inserito e': {fattoriale}")

#es20
num9=int(input("Inserire un numero da 1 a 10:"))
for i20 in range(1,101):
    if i20%num9!=0:
        print(i20)
    elif i20!=num9 and i20%num9==0:
        print("multiplo trovato")
        break

#es21
for i22 in range(100,0,-1):
    if i22%3!=0:
        print(i22)

#es22
stringa3=str(input("Inserire una stringa: "))
print(stringa3[0::2])

#es23
cifre=0
for i24 in range(1,101):
        if i24%5==0:
            cifre+=1
print(cifre)

#es24
contaggio=0
potenza=2
num10=2
while contaggio>=0:
    risulatato10=num10**potenza
    contaggio+=1
    potenza+=1
    print(risulatato10)
    if risulatato10==1024:
        break

#es26
cont13=0
stringa4=str(input("inserisci una stringa, conto nella parola quante a ci sono all'interno:"))
for lettera11 in stringa4:
 if lettera11=="a":
     cont13+=1
print(cont13)

#27
for i27 in range(1,21):
    if i27%2==0 and i27%3==0:
        print(i27)
        
#28
num18=(input("Inserisci un numero, verrà stampato una cifra alla volta:"))
for cifre10 in num18:
    print(cifre10)

#29
n=int(input("Inserisci un numero, darò tutti i suoi divisori:"))
cont_div=0
div=1
for i30 in range(n):
 if n%div==0:
     print(div)
     div+=1
 else:
     n%div!=0
     div+=1

#30
esponente=2
somma=0
for base in range(1,11):
    somma+=base**2
print(somma)

#33
num12=int(input("Inserisci il primo numero:"))
num13=int(input("Inserisci il secondo numero:"))
num14=int(input("Inserisci il terzo numero:"))
while num14 != 0:
    # print("b:", b, "    ", end="")
    r = num12%num13%num14
    num12 = num13
    num13=num14
    num14 = r
    # print("r:", r, "a:", a, "b:", b)

print(f"Il MCD è {num14}")

#34
def fibonacci(n):
    a=0
    b=1
    for i40 in range(20):
        print(a, end=", ")
        a, b =b, a+b
print(fibonacci(20))

#35
stringa10=str(input("Inserisci una frase contero' quante vocali ci sono all'interno:"))
vocali=("a","e","i","o","u")
for i40 in range(len(stringa10)):
    cont=stringa10.count(vocali)
print(f"le vocali all'interno della stringa sono: {cont}")





        





         



