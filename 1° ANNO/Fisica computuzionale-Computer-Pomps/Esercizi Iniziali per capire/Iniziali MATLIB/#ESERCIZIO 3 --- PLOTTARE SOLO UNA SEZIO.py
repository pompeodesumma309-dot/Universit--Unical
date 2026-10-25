#ESERCIZIO 3 --- PLOTTARE SOLO UNA SEZIONE DELLA PAROBOLA

"""1. Crea un array x tra -10 e 10 con 1000 punti.
2. Definisci la parabola:

   y = x^2

3. Mostra:
   - il grafico completo
   - solo la parte compresa tra x = 3 e x = 5

Usa una maschera booleana per selezionare l'intervallo."""

import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10, 10, 1000)

y = x**2

#----------PRIMO GRAFICO----------
plt.figure()

plt.plot(x,y)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Parabola completa: y = x^2")

plt.show()

#-----------SECONDO GRAFICO----------
maschera = (x>=3) & (x<=5)
x_selection = x[maschera]
y_selection= y[maschera]

plt.figure()

plt.plot(x_selection, y_selection)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Grafico comn condizioni x=3 e x=5")

plt.show()