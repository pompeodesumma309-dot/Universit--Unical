#ESERCIZIO 5 - PRODOTTO MATRICE-VETTORE
#1. Crea una matrice diagonale 3x3 con valori (2, 3, 4).
#2. Crea un vettore v = (1, 1, 1).
#3. Calcola:
#   - il prodotto matrice-vettore D @ v
#   - il prodotto elemento per elemento D * v
#4. Confronta i risultati.


import numpy as np

#Per creare una matrice in in cui nella sua diagonale abbia i valori che vogliamo noi usiamo il comadno:
D =np.diag([2,3,4])
print("Matrice D:")
print(D)

#Creiamo il vettore: 
vettore = np.array([1,2,1])

print("\nVettore:")
print(vettore)

#prodotto matriciale:

prodotto_matriciale = D @ vettore
print("\nProdotto matrice-vettore:")
print(prodotto_matriciale)

#Prodotto elemento per elemento: 
#Usiamo l'operatore * che moltiplica ogni colonne della matrice per il vettore

prodotto_elem = D * vettore
print("\nProdotto elemento per elemento:")
print(prodotto_elem)

#Confronto delle dimensioni
print("\nShape di D:", D.shape)
print("Shape di vettore:", vettore.shape)
print("Shape di D @ vettore:", prodotto_matriciale.shape)
print("shape di D * vettore:", prodotto_elem.shape)