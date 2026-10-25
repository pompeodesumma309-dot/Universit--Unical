#ESERCIZIO 3 : CADUTA LIBERA (LEZIONE 3)
import numpy as np
import matplotlib.pyplot as plt

y0 = 80
v0 = 0
g_piedi = 32
g_convertita = g_piedi * 0.3048


#tempo di caduta
t_caduta = np.sqrt(2*y0/g_convertita)
print("Tempo di caduta=", t_caduta, "s")

#tempo per i grafici
t = np.linspace(0, t_caduta, 200)


#posizione
yt = y0 - 0.5 * g_convertita * t**2


#velocità nel tempo 
vt = -g_convertita * t

#-------GRAFICI--------
plt.figure(figsize=(10, 4))

#posizione
plt.subplot(1, 2, 1)
plt.plot(t, yt)
plt.xlabel("tempo [s]")
plt.ylabel("altezza [m]")
plt.grid("Caduta libera: posizione")
plt.grid()

#velocità
plt.subplot(1, 2, 2)
plt.plot(t, vt)
plt.xlabel("tempo [s]")
plt.ylabel("velocita [m/s]")
plt.grid()

plt.tight_layout()
plt.show()