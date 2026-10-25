#ESERCIZIO 3 - Prodotto scalare, norma e angolo tra vettori 

#1. Genera due vettori casuali 3D `v` e `w`.
#2. Calcola:
#   - prodotto scalare `v · w`
#   - norma di `v` e di `w`
#   - angolo `theta` tra i due vettori usando:###

#   \[
#   \cos(\theta) = \frac{v \cdot w}{||v||\,||w||}
#   \]#

#3. Stampa `dot`, `||v||`, `||w||`, `theta` (in radianti).

import numpy as np
rng = np.random.default_rng(1)

v = rng.normal(size=3)
w= rng.normal(size=3)

prodotto_scalare = v @ w

#Calcoliamo il norma euclidea: 
norma_v = np.linalg.norm(v)
norma_w = np.linalg.norm(w)

#Coseno dell'angolo:
cos_theta = prodotto_scalare / (norma_v * norma_w)

#trasformiamo in radianti:
theta= np.arccos(cos_theta)

print("v = ",v)
print("w= ",w)
print("Prodotto scalare: ", prodotto_scalare)
print("norma di v= ", norma_v)
print("Norma di w= ", norma_w)

#Convertiamo l'angolo da radianti a gradi
theta_deg = np.degrees(theta) 

print("Angolo tra v e w (radianti)=", theta)
print("Angolo tra v e w (gradi)=", theta_deg)