#ESERCIZIO 4 LEZIONE 3 -- UN'AUTO CHE DECELLERA
import numpy as np
import matplotlib.pyplot as plt

v0_km = 90
v0 = v0_km / 3.6

a = -5
x0 = 0.0

print("Velocità iniziale =", v0, "m/s")

#Tempo di arresto
t_stop = -v0 / a

print("Tempo di arresto =", t_stop, "s")

t = np.linspace(0,t_stop, 200)

#Velocità
vt = v0 + a * t

#Posizione 
xt = x0 + v0*t + 0.5 * a * t**2

#Distanza percorsa durante la frenata
x_stop = v0*t_stop + 0.5 * a * t_stop**2
#oppure x_stop = xt[-1]

print("Distanza di arresto =", x_stop, "m")

#GRAFICI
plt.figure(figsize=(10, 4))

#Velocità
plt.subplot(1,2,1)
plt.plot(t, vt)
plt.xlabel("tempo [s]")
plt.ylabel("velocità [m/s]")
plt.title("Grafico della velocità")
plt.grid()

#Posizione
plt.subplot(1,2,2)
plt.plot(t, xt)
plt.xlabel("tempo [s]")
plt.ylabel("posizione [m]")
plt.title("Grafico della posizione")
plt.grid()

plt.tight_layout()
plt.show()