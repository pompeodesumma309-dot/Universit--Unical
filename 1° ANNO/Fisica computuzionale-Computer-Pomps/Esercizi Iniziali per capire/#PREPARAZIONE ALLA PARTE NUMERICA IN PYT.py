#PREPARAZIONE ALLA PARTE NUMERICA IN PYTHON

# 1.Definire un array dei tempi;
# 2.calcolare x(t) e v(t) usando le formule analitiche;
# 3.visualizzare i risulatati con grafici 

import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(0, 10 ,100)
x0 = 0.0
v0 = 2.0

x = x0 + v0 * t

plt.plot(t, x)
plt.xlabel("t [s]")
plt.ylabel("x [m]")
plt.title("Moto rettilineo uniforme")
plt.grid()
plt.show()

x0 = 0.0
v0 = 1.0
a = 0.8

x = x0 + v0 * t + 0.5 * a * t**2
v = v0 + a*t

plt.plot(t, x, label="x(t)")
plt.plot(t, v, label="v(t)")
plt.xlabel("t [s]")
plt.legend()
plt.grid()
plt.show()