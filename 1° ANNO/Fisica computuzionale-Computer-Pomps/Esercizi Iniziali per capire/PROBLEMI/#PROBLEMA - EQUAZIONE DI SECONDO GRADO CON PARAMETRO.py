#PROBLEMA - EQUAZIONE DI SECONDO GRADO CON PARAMETRO 
## Problema — Equazione di secondo grado con parametro

""""Consideriamo l'equazione:

    a x^2 + b x + c = 0

con:

    a = 1
    c = -1
    b variabile

Obiettivo:

Calcolare le soluzioni reali al variare di b e visualizzarle.

---

Pseudocodice:

1. Definire i coefficienti a e c.
2. Creare un array di valori per b.
3. Calcolare il discriminante:

       Delta = b^2 - 4*a*c

4. Creare una maschera booleana che seleziona solo i casi in cui:

       Delta >= 0

5. Creare due array x1 e x2 inizializzati con valori non validi (ad esempio NaN).

6. Per i soli valori in cui Delta >= 0:

       x1 = (-b + sqrt(Delta)) / (2*a)
       x2 = (-b - sqrt(Delta)) / (2*a)

7. Visualizzare x1 e x2 in funzione di b.

---

Osservazioni importanti:

- Non usiamo cicli `for`.
- Tutte le operazioni sono vettoriali.
- Usiamo una maschera booleana per evitare radici di numeri negativi."""

import numpy as np
import matplotlib.pyplot as plt

a = 1
c = -1

b = np.linspace(-5,5,400)

#Calcoliamo il descriminante 
Delta = b**2 - 4*a*c

#Creiamo una maschera booleana
maschera = Delta>=0

#Creiamo array
x1 = np.full_like(b, np.nan)
x2 = np.full_like(b, np.nan)

#Per i solo valori in cui il delta è >=0:
x1[maschera] = (-b[maschera] + np.sqrt(Delta[maschera])) / (2*a)
x2[maschera] = (-b[maschera] - np.sqrt(Delta[maschera])) / (2*a)

#plot
plt.figure()
plt.plot(b, x1, label="x1")
plt.plot(b, x2, label="x2")
plt.xlabel("b")
plt.ylabel("soluzioni")
plt.title("soluzioni dell'equazione al variare di b")
plt.legend()
plt.show()