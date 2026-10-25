#ESERCIZIO 1 MOTO RETTILINEO UNIFORME
import numpy as np
import matplotlib.pyplot as plt

#Per trovare x(t) = x0 + v*t -> x(t) = 5t
#Convertire 18 km/h in m/s, in risultato sarà 5 m/s


v_kmh = 18
v_ms = v_kmh / 3.6
t = np.arange(0, 21, 1)

x = 0 + v_ms*t

plt.plot(t, x, marker="o")
plt.xlabel("tempo (s)")
plt.ylabel("posizione (m)")
plt.grid()
plt.title("Posizione in funzione del tempo")
plt.show()
