#ESERCIZIO 4 - MATRICI E SLICING

#1. Crea una matrice 4x4 con interi da 1 a 16.
#2. Estrai:
#   - seconda riga
#   - terza colonna
#   - sottomatrice 2x2 centrale
#3. Calcola la trasposta.

import numpy as np

numeri = np.arange(1, 17)

#Questo comando reshape riorganizza l'array in una matrice, in questo caso, 4x4
M = numeri.reshape(4,4)

print("matrice M:")
print(M)

#Estraiamo la seconda riga:
seconda_riga= M[1, :]

print("\nSeconda riga:")
print(seconda_riga)

#Estraiamo la terza colonna
terza_colonna= M[: ,2]

print("\nTerza colonna:")
print(terza_colonna)

#Estrazione della matrice centrale:
centrale=M[1:3, 1:3]

print("\nSottomatrice centrale 2x2:")
print(centrale)

#Calcoliamo la trasposta:
#Il comando .T scambia righe e colonne

MT = M.T

print("\nTrasposta:")
print(MT)

#Stampiamo anche lo shape per capire meglio 
print("\nShape di M:", M.shape)
print("\nShape di MT:", MT.shape)