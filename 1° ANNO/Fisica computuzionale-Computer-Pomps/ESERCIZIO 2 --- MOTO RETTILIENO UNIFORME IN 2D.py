#ESERCIZIO 2 --- MOTO RETTILIENO UNIFORME IN 2D
import numpy as np
import matplotlib.pyplot as plt

x0, y0 = 5, 2
vx, vy = 4, -1

t = np.linspace(0, 8, 200)

x = x0 + vx * t 
y = y0 + vy * t

#Grafici
plt.figure(figsize=(12, 4))

plt.subplot(1, 3, 1)
plt.plot(t, x)
plt.xlabel("Tempo [s]")
plt.ylabel("x [m]")
plt.title("Grafico x(t)")
plt.grid()

plt.subplot(1, 3, 2)
plt.plot(t, y)
plt.xlabel("Tempo [s]")
plt.ylabel("y [m]")
plt.title("Grafico y(t)")
plt.grid()

plt.subplot(1, 3, 3)
plt.plot(x, y)
plt.xlabel("X [m]")
plt.ylabel("Y [m]")
plt.title("Traiettoria di xy")
plt.axis("equal")
plt.grid()

plt.tight_layout()
plt.show()

