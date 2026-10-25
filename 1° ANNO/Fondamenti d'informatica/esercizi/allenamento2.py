
for i in range(1, 11):
    for j in range(1, 11):
        print(f"{i*j}", end=' ')
    print()

#Consegna: Stampa una matrice 7x7 con asterisco sulle due diagonali.
n=7
for i in range(n):
    for j in range(n):
        if i==j or j==(n-1)-i:
            print("*", end=" ")
        else:
            print(" ",end=" ")
    print()

#Consegna: Stamparne pattern scacchiera di NxN con # e .
n=8
risultato=0
for i in range(n):
    for j in range(n):
        risultato=i+j
        if risultato%2==0:
            print("#",end=" ")
        else:
            print(" ",end=" ")
    print()

#Consegna: Data una matrice di interi, stampa la somma di ogni riga
matrice=[
    [1,2,3],
    [4,5,6],
    [7,8,9],
]
for riga_id, riga in enumerate(matrice):
    somma=0
    for valore in riga:
        somma+=valore
    print(somma)

#stampa la diagonale principale di NxN con il loro indici
matrice = [
    [5, 8, 3],
    [4, 7, 2],
    [9, 6, 1]
]
for row_idx, riga in enumerate(matrice):
    for col_idx, elemento in enumerate(riga):
        if col_idx > row_idx:
            print(f"Elemento in posizione ({row_idx}, {col_idx}): {elemento}")



    


