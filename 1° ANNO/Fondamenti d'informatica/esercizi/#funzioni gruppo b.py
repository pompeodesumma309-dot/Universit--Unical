#funzioni gruppo b
#es1
def somma_elem(a,b):
    somma=a+b
    return somma

a=6
b=5
print(somma_elem(a,b))

#es2
def quadrato(x):
    return x**2

num1=-5
print(quadrato(num1))

#es3
def saltua(nome):
    print(f"{nome}, ciao!")

nome="Marco"
print(saltua(nome))

#es4
def doppio(x):
    doppio=x*2
    return doppio

x=2.2
print(doppio(x))

#es5
def conta_caratteri(stringa):
    cont=len(stringa)
    return cont

stringa="ciao a tutti"
print(conta_caratteri(stringa))

#es6
def inverti(stringa):  
        return stringa[::-1]
    
stringa2="ciao a tutti"
print(inverti(stringa2))

#es7
def positvo(x):
     if x>0:
          return True
     return False

x=5
print(positvo(x))

#es8
def perimetro_rettangolo(larghezza,altezza):
     perimetro=2*(larghezza+altezza)
     return perimetro

l=6
a=5
print(perimetro_rettangolo(l,a))

#es9
def media(a,b,c):
     somma=a+b+c
     media=somma/3
     return media

a=3
b=3
c=3
print(media(a,b,c))

#es10
def pari(n):
     if n%2==0:
          return True
     return False

nu=4
print(pari(nu))

#es11
def genera(n):
 return ''.join(str(i) for i in range(1, n + 1))
      
n=6     
print(genera(n))

#es12
def fattoriale(n):
    risultato=1
    for i in range(1,n+1):
        risultato*=i
    return risultato    
     
f=5
print(fattoriale(f))

#es13
def num_caratteri_vocali(stringa):
    vocali = "aeiou"
    conteggio = 0
    for carattere in stringa:
        if carattere in vocali:
            conteggio += 1
    return conteggio

frase="ciao"
print(num_caratteri_vocali(frase))

#es14
def potenza(base,esponente):
    risultato=base**esponente
    return risultato

b=2
e=3
print(potenza(b,a))

#es15
def ripeti_stringa(stringa,n):
    rip=stringa*n
    return rip

stringa3="ciao"
n=3
print(ripeti_stringa(stringa3,n))

#ea16
def massimo(a,b,c):
    max=0
    if a>b and a>c:
        max=a
    if b>a and b>c:
            max=b
    if c>b and c>a:
            max=c
    return max
a=10
b=9
c=8
print(massimo(a,b,c))

#es18
def pari_fino_a_n(n):
 return ''.join(str(i) for i in range(2, n + 1,2))

p=2
print(pari_fino_a_n(p))

#es19
def massima_potenza(a,b,c):
    passo1=a**b
    passo2=passo1**c
    return passo2

print(massima_potenza(2, 3, 2))

#es20
def concatena_stringhe(s1,s2):
    conc=s1+s2
    return conc

print(concatena_stringhe("ciao","Marco"))

#es22
def numeri_fibonacci(n,c):
    a=0
    b=1
    lista=[]

    while len(lista) < n:
        if a%c!=0:
            lista.append(a)
        a,b= b, a+b
    return lista
n=5
c=2
print(numeri_fibonacci(n,c))

#es24
def somma_divisori(n):
    lista=[]
    divisori=0
    for i in range(1,n):
        if n%i==0:
            lista.append(i)
            divisori+=i   
    return divisori

numero=28
print(somma_divisori(numero))

#es25
def anagrammi(s1,s2):
    if len(s1) != len(s2):
        return False

    conteggio1 = {}
    conteggio2 = {}

    for c in s1:
        if c in conteggio1:
            conteggio1[c] += 1
        else:
            conteggio1[c] = 1

    for c in s2:
        if c in conteggio2:
            conteggio2[c] += 1
        else:
            conteggio2[c] = 1
    return conteggio1 == conteggio2


s1="hello"
s2="word"
print(anagrammi(s1,s2))

#es26
def conta_parole(s1):
    parole=s1.split()
    return len(parole)
   
c="ciao bastardi maledetti"
print(conta_parole(c))





   



     