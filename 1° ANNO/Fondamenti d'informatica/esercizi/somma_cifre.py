def somma_cifre(numero):
   somma=0
   while numero>0:
      cifra= numero%10
      somma+=cifra
      numero//10
      
   
   n=int(input("Inserisci un numero: positivo:"))
   print(somma_cifre(n))