#ESERCIZIO 6 --> OPERAZIONI TRA MATRICI, INVERSA E IDENTITA' 

#1. Crea due matrici 3x3 piene.
#2. Calcola:
#   - somma tra matrici
#   - prodotto elemento per elemento
#   - prodotto matriciale
#3. Crea un vettore v = (1, 2, 3) e calcola il prodotto matrice-vettore.
#4. Calcola l'inversa di una matrice (se invertibile) e verifica che:
#
#   A @ inv(A) ≈ I
#dove I è la matrice identità.

import numpy as np

#Creiamo le matirici:

A = np.array([[2.0, 1.0, 1.0],
              [1.0, 3.0, 2.0],
              [1.0, 0.0, 1.0]])

B = np.array([[2.0, 1.0, 3.0],
              [4.0, 0.0, 5.0],
              [6.0, 7.0, 8.0]])

print("Matrice A:")
print(A)

print("\nMatrice B:")
print(B)

#Somma tra matrici
somma = A+B

print("\nSomma:")
print(somma)

#Prodotto elem per elem
prodotto_elem = A*B

print("\nProdotto elem per elem:")
print(prodotto_elem)

#Prodotto matriciale
prodotto_matriciale= A @ B

print("prodotto matriciale:")
print(prodotto_matriciale)

#Creiamo un vettore:
vettore = np.array([1.0,2.0,3.0])

print("\nVettore:")
print(vettore)

#Calcoliamo il prodotto matrice vettore
matrice_vettore= A @ vettore

print("\nProdotto matrice vettore:")
print(matrice_vettore)

#calcoliamo l'inversa della matrice, se è invertibile
A_inv=np.linalg.inv(A)

print("\nInversa di A, inv(A):") 
print(A_inv)

#Calcoliamo A @ inv(A):
I_approx_1 = A @ A_inv

print("\nA @ inv(A) dovrebbe essere circa identità:")
print(I_approx_1)

#Calcoliamo anche inv(A) @ A, dovrebbe essere circa identità:
I_approx_2= A_inv @ A

print("\ninv_A @ A dovrebbe essere circa identita':")
print(I_approx_2)

#Costruiamo la matrice d'identita' 3x3: 
I = np.eye(3)

print("\nMatrice d'identita':")
print(I)

#Misuriamo quanto siamo lontani dall'identità (norma della differenza)
errore_1= np.linalg.norm(I_approx_1 - I)
errore_2 = np.linalg.norm(I_approx_2 - I)

print("\nErrore ||A @ inv(A) - I|| =", errore_1)
print("Errore ||inv(A) @ A -I||=", errore_2)

#Verifica automatica "quasi uguale" con una tolleranza
#np.allclose restituisce True se le due matrici sono uguali entro tolleranza numerica
print("\nA @ inv(A) è circa I?", np.allclose(I_approx_1, I))
print("\ninv(A) @ A è circa I?", np.allclose(I_approx_2, I))


#Shape delle strotture:
print("\nShape di A:", A.shape)
print("Shape di B:", B.shape)
print("Shape di v:", vettore.shape)
print("Shape di A @ B:", prodotto_matriciale.shape)
print("Shape di A @ v:", matrice_vettore.shape)