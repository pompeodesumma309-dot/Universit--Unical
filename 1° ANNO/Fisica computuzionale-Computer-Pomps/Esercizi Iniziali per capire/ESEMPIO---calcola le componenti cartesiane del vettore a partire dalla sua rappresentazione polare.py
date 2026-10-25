#ESEMPIO
#Supponiamo di avere una velocità di modulo v = 10m/s diretta con un angolo theta = 30 gradi
#Calcola le componenti cartesiane del vettore e disegnare uan schema del vettore e delle sue componenti

import numpy as np
import matplotlib.pyplot as plt

v = 10 
theta = np.deg2rad(30)

vx = v * np.cos(theta)
vy = v * np.sin(theta)

#Creazione del grafico
fig ,ax = plt.subplots()

ax.arrow(0, 0, vx, vy, head_width=0.3, length_includes_head=True) #x=0, y=0, dx=vx, dy=vy, head...= grandezza punta della freccia, 
ax.text(vx*0.6, vy*0.6, r'$\vec{v}$') # x=vx*0.6 metti il testo al 60% della componente x del vettore, stessa cosa per y. r"$\vec{v}$" disegna la v con la freccia sopra

#linee tratteggiate che rappresentato le proiezioni 
ax.plot([0, vx], [0,0], linestyle="--") # la x va da 0 a vx; la y è sempre 0
ax.plot([vx, vx], [0,vy], linestyle="--") #la x è sempre vx; la y va da 0 a vy

# etichette delle componenti
ax.text(vx/2, -0.5, r"$v_x$")
ax.text(vx + 0.2, vy/2, r"$v_y$")

# -------------------------
# DISEGNO DELL'ANGOLO
# -------------------------

# creiamo una serie di angoli tra 0 e theta
angles = np.linspace(0, theta, 100)

# disegniamo un piccolo arco che rappresenta l'angolo
ax.plot(2*np.cos(angles), 2*np.sin(angles))

# etichetta dell'angolo
ax.text(2*np.cos(theta/2), 2*np.sin(theta/2), r"$\theta$")

# -------------------------
# DISEGNO DEGLI ASSI
# -------------------------

# asse x
ax.axhline(0)

# asse y
ax.axvline(0)

# -------------------------
# IMPOSTAZIONI DEL GRAFICO
# -------------------------

# manteniamo la stessa scala sui due assi
ax.set_aspect('equal')

# limiti del grafico
ax.set_xlim(-11, 11)
ax.set_ylim(-11, 7)

# etichette degli assi
ax.set_xlabel("x")
ax.set_ylabel("y")

# titolo del grafico
ax.set_title("Rappresentazione polare e cartesiana del vettore")

# mostriamo il grafico
plt.show()