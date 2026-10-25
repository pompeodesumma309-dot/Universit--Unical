#ESERCIZIO 5 LEZIONE 3 --- Velocità media di un corridore 
import numpy as np
import matplotlib.pyplot as plt

x1 = 0.1 *1000
t1 = 10 

x2 = 100
t2 = 8

#Primo intervallo
v1 = x1 / t1

#secondo intervallo
v2 = x2 / t2

x_tot = x1 + x2

t_tot = t1 + t2

v_media = x_tot / t_tot

print("Velocità media del primo intervallo =", v1, "m/s")
print("Velocità media del secondo intervallo =", v2, "m/s")
print("Velocità media totale =", v_media, "m/s")

#Costruzione grafico posizione

t = np.linspace(0, t_tot, 200)
x = np.zeros_like(t)

#primo intervallo
mask1 = t <= t1
x[mask1] = v1 * t[mask1]

#secondo intervallo
mask2 = t > t1
x[mask2] = x1 + v2 * (t[mask2] - t1)

plt.plot(t, x)
plt.scatter([0, t1, t_tot], [0, x1, x_tot])
plt.xticks(range(0, 19, 2))
plt.xlabel("tempo [s]")
plt.ylabel("posizione [m]")
plt.title("Posizione del corridore nel tempo")
plt.grid()

plt.show()
