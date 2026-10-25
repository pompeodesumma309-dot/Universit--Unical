#ESECIZI 1 MATPLOTLIB
#RETTA, PARABOLA E SENO

#1. Crea un array x con 400 punti tra -5 e 5.
#2. Definisci:
#   - retta: y1 = 2x + 1
#   - parabola: y2 = x^2
#   - seno: y3 = sin(x)
#3. Costruisci:
#   - un grafico con le tre curve sovrapposte
#   - una figura con tre subplot separati
#
#Osserva la differenza tra grafici sovrapposti e subplot.

import numpy as np
import matplotlib.pyplot as plt

#Creiamo l'array
x = np.linspace(-5,5, 400)

#Definiamo:
y1= 2*x + 1
y2= x**2
y3 = np.sin(x)


# -------------PRIMO GRAFICO-----------------
#Costruiamo:
plt.figure()
plt.plot(x, y1, label="y=2x+1")
plt.plot(x, y2, label="y=x^2")
plt.plot(x, y3, label="y=sin(x)")

#Etichette assi
plt.xlabel("x")
plt.ylabel("y")

plt.title("Curve sovrapposte")

plt.legend()

plt.show()

#-----------------SECONDO GRAFICO------------------
#plt.subplot crea una figura con piu grafici
fig, ax = plt.subplots(3, 1, figsize=(6, 8))

#PRIMO SUBPLOT
ax[0].plot(x, y1)
ax[0].set_title("Retta: y = 2x+1")

#SECONDO
ax[1].plot(x,y2)
ax[1].set_title("Retta: y = x^2")

#TERZO 
ax[2].plot(x ,y3)
ax[2].set_title("Retta: y=sin(x)")

#Migliora la disposizione verticale
plt.tight_layout()

plt.show()