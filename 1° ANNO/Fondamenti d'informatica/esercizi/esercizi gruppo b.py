#Esercizi su variabili, tipi e lettura da input

#es1
a=10
b=20
print(f"{a},{b}")

#es2
num1=int(input("Inserisci il primo numero:"))
num2=int(input("Inserisci il secondo numero: "))
somma=0
somma=num1+num2
print(f"La somma dei due numeri e': {somma}")

#es3
s1="Ciao"
s2="Mondo"
stringa_completa=s1+s2
print(stringa_completa)

#es4
num5=100
print(type(num5))
str=(str(num5))
print(type(str))

#es5
stringa1=(input("inserisci una frase: "))
conta=0
conta=len(stringa1)
print(conta)

#es6
stringa2=(input("inserisci una frase:"))
if len(stringa2)>0:
    prima_parola=stringa2[0]
    ultima_lettera=stringa2[-1]
print(f"{prima_parola}{ultima_lettera}")

#es7
""""
numero8=input("Inserisci un numero: ")
stringa_numero1=str(numero8)
print(type(stringa_numero1))
"""

#es8
string="Python e' divertente"
print(string[10:])

#es9
nome=input("inserisci nome utente:")
cognome=input("Inserisci cognome utente:")
print(f"{nome}"," ",cognome)

#es10
stringa12=input("Inserisci una parola: ")
ripetuta=stringa12*3
print(ripetuta)

#es11
frase="I linguaggi di programmazione sono utili"
frase.find("utili")
print("I linguaggi di programmazione sono potenti")

#es12
print("P","y","t","h","o","n")

#es14
n=1
for i in range(1,11):
    potenza=n**2
    n=n+1
    print(potenza)

#es15
for i in range(1, 51):
    if i % 5 != 0:
        print(i)

#es16
n3=int(input("Inserisci un numero: "))
for j in range(0,11):
    tabellin=j*n3
    print(f"{n3} x {j}: {tabellin}")

#es17
num6=1
cont=100
while cont>0:
    if num6%4==0:
        print(num6)
    num6=num6+1
    cont=cont-1




        
  
    
    

    

