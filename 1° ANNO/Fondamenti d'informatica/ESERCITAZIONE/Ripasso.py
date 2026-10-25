####SOMMA DI N NUMERI INTERI LETTI DA OUTPUT####
"""num=int(input("Inserisci quanti numeri vuoi sommare: "))
cont=0
somma1=0

while cont<num:
    if num!=1:
        num1=int(input("Inserisci il numero: "))
        somma1+=num1
        cont+=1

print("la somma dei numeri e': ",somma1)"""

####MEDIA DEI NUMERI N LETTI DA OUTPUT######
"""cont_giri=int(input("Inserisci il totale di num di cui vuoi la media: "))
cont=0
somma=0
while cont<cont_giri:
    num3=int(input("Inserisci il numero: "))
    somma+=num3
    media= somma/cont_giri
    cont+=1
print("La media dei numeri e': ", media)"""

###SOMMA SEPARAMENTE I NEGATVI E I POSITIVI####

"""cont = 0
while cont <= 1:
    cont = int(input("Inserisci quanti numeri vuoi sommare (almeno 2): "))
    if cont <= 1:
        print("Errore: devi inserire almeno due numeri per effettuare una somma.\n")
lista_pos=[]
lista_neg=[]

for i in range(cont):
    num=int(input("Inserisci il numero: "))
    if num>=1:
        lista_pos.append(num)
    if num<=0:
        lista_neg.append(num)
print(sum(lista_pos))
print(sum(lista_neg))"""

"""cont_giri = int(input("Inserisci quanti numeri vuoi sommare: "))
cont=0
somma_neg=0
somma_pos=0
while cont<cont_giri:
    num=int(input("Inserisci il numero: "))
    if num>=0:
        somma_pos+=num
        cont+=1
    else:
        somma_neg+=num
        cont+=1
print("la somma dei numeri positivi e': ",somma_pos)
print("la somma dei numeri negativi e': ",somma_neg)"""


##Scriviamo un programma che, letto da input un numero intero positivo x, stampa un quadrato di lato X di simboli @.
"""num=int(input("Inserisci il numero:"))
for i in range(num):
    for j in range(num):
        print ("#",end=" ")
    print()"""

##SCRIVIAMO LE TABELLINE FINO AL NUMERO 10
"""for i in range(1,11):
    for j in range(1,11):
        print(f"{i} x {j} = {i*j}")
    print()"""

#CHIEDERE DUE NUM, STAMPARE DA 1 FINO A NUM1, MA INTERROMPERE SE SI INCONTRA NUM2
"""num1=int(input("Inserisci il primo numero: "))
num2=int(input("Idnserisci il secondo numero: "))
for i in range(num1):
    if i==num2:
        break
    print(i)"""

#   ES.46
"""num=int(input("Inserisci un numero per vedere se è perfetto: "))
somma=0
for i in range(1,num):
    if num%i==0:
        somma+=i

if somma==num:
    print("il numero e' perfetto.")
else: 
    print("il numero non e' perfetto.")"""


"""def perfetto(numero):
    somma=0
    for i in range(1,numero):
        if numero%i==0:
            somma+=i

    if somma==numero:
        return True
    else:
        return False

num=int(input("Inserisci un numero: "))
if perfetto(num):
    print(num, "e' un numero perfetto.")
else:
    print(num, "non e' perfetto.")"""

##PRENDE ARGOMENTO E RESTITUISCE IL QUADRATO 
"""def quadrato(numero):
    return numero**2

num=int(input("Inserisci il numero di cui vuoi il quadrato: "))
print(quadrato(num))"""

#SOMMA DIVISORI
"""def divisori(num):
    somma=0
    for i in range(1, num):
        if num%i==0:
            somma+=i
    return somma

print(divisori(6))"""

##ALTERNAZIONE DEI CARATTERI
"""def combina_stringhe(s1,s2):
    risultato=[]
    if len(s1)<len(s2):
        limite= len(s1)
    else:
        limite=len(s2)

    for i in range(limite):
        risultato.append(s1[i])
        risultato.append(s2[i])

    risultato.append(s1[limite:])
    risultato.append(s2[limite:])

    return "".join(risultato)

print(combina_stringhe("casa","uomo"))"""

###
"""def inverti_stringa(stringa, num1, num2):
    massimo=None
    minimo=None

    if num1>num2:
        massimo=num1
        minimo=num2
    else:
        massimo=num2
        minimo=num1

    parte_invertita=""
    for i in range(massimo, minimo-1, -1):
        parte_invertita+=stringa[i]


    return stringa[0:minimo]+ parte_invertita + stringa[massimo+1:]      

print(inverti_stringa("trappola",1,3))"""

####CONTA PAROLE 
"""def conta_aprole(frase):

    if not frase or frase.isspace():
        return 0
    
    somma=1
    for i in range(len(frase)-1):
        if frase[i]==" " and frase[i+1]!=" ":
            somma+=1

    return somma

print(conta_aprole("ciao a tutti, come vi chiamate io pompeo"))"""



            
        
    
        
