#ESERCIZIO 1 --- Moto rettilineo uniforme in 2D
import numpy as np
import matplotlib.pyplot as plt

Vx = 3
Vy = 2

x0 = 0
y0 = 0

t = np.linspace(0 , 10, 200)

xt = x0 + Vx * t
yt = y0 + Vy * t

plt.figure(figsize=(10, 4))

#Grafico x(t)
plt.subplot(1 ,3 ,1)
plt.plot(t, xt)
plt.xlabel("Tempo [s]")
plt.ylabel("x [m]")
plt.title("Grafico x(t)")
plt.grid()

#Grafico y(t)
plt.subplot(1 ,3 ,2)
plt.plot(t, yt)
plt.xlabel("Tempo [s]")
plt.ylabel("y [m]")
plt.title("Grafico y(t)")
plt.grid()

#grafico xy
plt.subplot(1 ,3 ,3)
plt.plot(xt, yt)
plt.xlabel("x [m]")
plt.ylabel("y [m]")
plt.title("Grafico xy(t)")
plt.grid()
plt.axis("equal")

plt.tight_layout()
plt.show()