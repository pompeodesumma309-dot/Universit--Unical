#ESERCIZIO 2 -- SCATTER PLOT E MAPPA DI COLORI 

""""1. Genera 500 punti casuali nel piano (x, y).
2. Definisci un valore scalare per ogni punto:

   z = x^2 + y^2

3. Costruisci:
   - uno scatter plot semplice
   - uno scatter plot colorato in base al valore z
4. Aggiungi una colorbar."""

import numpy as np
import matplotlib.pyplot as plt

rng = np.random.default_rng(2)

x = rng.uniform(-2, 2, 500)
y = rng.uniform(-2, 2, 500)

z = x**2 + y**2

#-------------PRIMO GRAFICO--------------
plt.figure()
plt.scatter(x,y)

plt.xlabel("x")
plt.ylabel("y")
plt.title("Scatter plot semplice")

plt.gca().set_aspect("equal") #Mantiene proporzioni corrette

plt.show()

#-------------SECONDO GRAFICO---------------
plt.figure()

#c=z assegna un colore a ogni punto in base al valore z
scatter = plt.scatter(x,y,c=z)

plt.xlabel("x")
plt.ylabel("y")
plt.title("Scatter colorato in base a z = x^2 + y^2")

plt.gca().set_aspect("equal")

plt.colorbar(scatter)

plt.show()