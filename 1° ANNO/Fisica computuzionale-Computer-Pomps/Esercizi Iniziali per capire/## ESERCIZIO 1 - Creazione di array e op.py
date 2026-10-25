## ESERCIZIO 1 - Creazione di array e operazioni base

# 1. Crea un array `x` con 500 punti equispaziati tra -5 e 5.
# 2. Calcola:
#   - `y = x**2`
#   - `z = 3*x - 1`
#   - `w = sin(x)`
# 3. Stampa:
#  - `shape` di `x`
#   - i primi 5 valori di `y`

import numpy as np

x = np.linspace(-5,5,500)

y= x**2
z= 3*x - 1
w= np.sin(x)

print("Shape di x: ", x.shape)

print("I primi 5 valori di y: ", y[:5])


#ESERCIZIO 2 - Operazione tra vettori 
#1. Genera due vettori casuali `a` e `b` di lunghezza 1000.
#2. Calcola:
#   - somma `a + b`
#   - differenza `a - b`
#   - prodotto elemento per elemento `a * b`
#   - quadrato `a**2`
#3. Stampa le prime 3 componenti della somma.
import numpy as np

rng= np.random.default_rng(0)

vettore_a = rng.normal(size=1000)
vettore_b = rng.uniform(size=1000)

somma= vettore_a + vettore_b

differenza= vettore_a - vettore_b

profotto= vettore_a * vettore_b

quadrato= vettore_a**2

print("Le prime 3 componenti della somma: ", somma[:3])



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
print("Angolo trra v e w (gradi)=", theta_deg)
