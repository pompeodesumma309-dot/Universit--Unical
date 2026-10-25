#ESERCIZIO 2: MOTO RETTILINEO UNIFORMEMENTE ACCELERATO
import numpy as np
import matplotlib.pyplot as plt

a_khm2 = 7.2
t = np.arange(0, 10, 1)

a = a_khm2 * 1000 / (3600**2)
print("Accelerazione in m/s^2 =", a)

#Parametri iniziali 
v0 = 0.0
x0 = 0.0

v = v0 + a*t
x = x0 + v0*t + 0.5*a*t**2

#Grafici
plt.figure(figsize=(10,4))

#posizione
plt.subplot(1,2,1)
plt.plot(t, x)
plt.xlabel("tempo [s]")
plt.ylabel("posizione [m]")
plt.grid()

#velocità
plt.subplot(1,2,2)
plt.plot(t, v)
plt.xlabel("tempo [s]")
plt.ylabel("velocità nel tempo")
plt.grid()

plt.tight_layout()
plt.show()