#ESERCIZIO 3 --- LANCIO ORIZONTALE
import numpy as np
import matplotlib.pyplot as plt

v0x , v0y = 6, 0
x0 , y0= 0.0, 20.0
g = 9.81

t_cad = np.sqrt(2*y0 / g)

t = np.linspace(0, t_cad, 200)

x = x0 + v0x * t
y = y0 + v0y * t - 0.5 * g * t**2

vx = np.full_like(t, v0x)
vy = v0y - g * t

#Grafici
plt.figure(figsize=(12, 4))

plt.subplot(1, 3, 1)
plt.plot(t,x)
plt.plot(t, y)
plt.xlabel("tempo [s]")
plt.ylabel("posizione [m]")
plt.title("Grafico di x(t)")
plt.legend()
plt.grid()

plt.subplot(1, 3, 2)
plt.plot(t, vx)
plt.plot(t, vy)
plt.xlabel("tempo [s]")
plt.ylabel("velocità [m/s]")
plt.title("Grafico di y(t)")
plt.legend()
plt.grid()

plt.subplot(1 ,3 ,3)
plt.plot(x, y)
plt.xlabel("x [m]")
plt.ylabel("y [m]")
plt.title("Grafico di xy")
plt.axis("equal")
plt.grid()

plt.tight_layout()
plt.show()
