#ESERCIZIO 4 --- CONFRONTO TRA FUNZIONE E DATI RUMOROSI
 
"""1. Crea un array x tra -5 e 5 con 200 punti.
2. Definisci la funzione:

   y = x^2

3. Genera una versione rumorosa della funzione:

   y_noise = y + rumore

   dove il rumore è casuale.
4. Visualizza:
   - la funzione esatta come linea continua
   - i dati rumorosi come punti (scatter)"""

import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-5, 5, 200)

y = x**2

#Generiamo la versione rumorosa
rng = np.random.default_rng(3)

#generiamo un rumore con media 0 e deviazione 2
rumore = rng.normal(0, 2, size=len(x))

y_noise = y + rumore

#visualizzazione
plt.figure()

plt.plot(x, y, label="Funzione esatta y = x^2")

plt.scatter(x, y_noise, s=15, label="Dati rumorosi")

plt.xlabel("x")
plt.ylabel("y")
plt.title("Confronto tra funzione esatta e dati rumorosi")

plt.legend()

plt.show()