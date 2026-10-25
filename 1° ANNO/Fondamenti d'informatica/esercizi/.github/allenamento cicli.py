#Scrivi un programma che stampa tutte le coppie (i, j) dove i va da 0 a 2 e j da 0 a 3.
for i in range(3):
    for j in range(4):
        print(f"i={i} j={j}")
        print()

#Stampa la tabellina del 5 da 1 a 10 usando due cicli: uno per il numero base e uno per i moltiplicatori.
for i in range(1,11):
    for j in range(1):
        print(f"5 x {i} = {5*i}")

#Chiedi all’utente larghezza e altezza, poi stampa un rettangolo di asterischi * con quelle dimensioni.
altezza=int(input("Inserisci l'altezza del rettangolo: "))
larghezza=int(input("Inserisci la larghezzza del rettangolo: "))
for i in range(altezza):
    for j in range(larghezza):
        print("*", end=" ")
    print()

#Crea una matrice 3x3 dove ogni cella contiene la somma degli indici i + j.
for i in range(0,3):
    for j in range(0,3):
        somma=i+j
        print(somma, end=" ")
    print()

#Stampa un triangolo di asterischi dove la prima riga ha 1 asterisco, la seconda 2, fino a n righe
num=int(input("inserisci la fine del triangolo: "))
for i in range(1,num+1):
 for j in range(1):
     print("*"*i)

#conatatori di caratteri
parole = str(input("inserisci una frase:"))
conteggio = {}
for parola in parole:
    for lettera in parola:
        conteggio[lettera] = conteggio.get(lettera, 0) + 1
print(conteggio)

#scacchiera 8x8
for i in range(8):
    for j in range(8):
        if (i+j)%2==0:
         print("#", end=" ")
        else:
         print(" ", end=" ")
    print()

import random
#matrice 5x5 con numeri casuali
for i in range(5):
   for j in range(5):
        numeri=random.randint(1,100)
        if (numeri%(i+1)==0):
            print(f"*{numeri},",end=" ")
        else:
         print(f"{numeri}", end=" ")
   print()
      



    

