#ESERCIZIO -- Viaggio di una bicicletta
import numpy as np
import matplotlib.pyplot as plt

v_km1 = 18
v1 = v_km1 / 3.6

v_km2 = 12
v2 = v_km1 / 3.6

t1 = 30
t2 = 40

t_tot = t1 + t2

t = np.linspace(0, t_tot, 200)
x = np.zeros_like(t)

#Primo tratto 
masck1 = t <= t1
x[masck1] = v1 * t[masck1]

#secondo tratto
masck2 = t > t1
x1 = v1*t1
x[masck2] = x1 + v2 * (t[masck2] - t2)

x_total = x1 + v2 * t2

v_media = x_total / t_tot

print("La velocità media è =", v_media, "m/s")

plt.figure()

plt.plot(t, x)
plt.xlabel("tempo [s]")
plt.ylabel("posizione [m]")
plt.title("Moto della bicicletta")
plt.grid()

plt.show()




