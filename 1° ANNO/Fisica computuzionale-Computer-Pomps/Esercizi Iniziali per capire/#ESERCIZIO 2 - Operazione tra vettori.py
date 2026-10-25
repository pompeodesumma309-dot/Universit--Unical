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