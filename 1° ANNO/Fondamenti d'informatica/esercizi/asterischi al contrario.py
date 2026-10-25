def stampa(n):
    for i in range(0,n):
        for j in range(0,n-i):
         print("*", end=" ")
        print()

num=int(input("inserisci un numero: "))
if num>0:
 print(stampa(num))
else:
   print("Numero non valido")


def stamp(d):
 for i in range(d):
    for j in range(d):
        if i==j or j==(d-1)-i:
           print(1,end="")
        else:
           print(0,end="")
    print()
num=int(input("inserisci un numero: "))
print(stamp(num))





def somma_cifre(numer):
   somma=0
   while numer>0:
      cifra= numer%10
      somma+=cifra
      numer//=10
   return somma  
n=int(input("Inserisci un numero: positivo:"))
print(somma_cifre(n))


def fibonacci(n):
  if n == 1 or n == 2:
    return 1

  a = 1 # Terzultimo termine
  b = 1 # Penultimo termine
  for i in range(3, n + 1):
      c = a + b # Termine attuale (che stiamo calcolando)
      a = b     # Terzultimo termine
      b = c     # Penultimo termine

  return c

n = int(input("Inserisci un intero positivo >= 1: "))
print(fibonacci(n))







