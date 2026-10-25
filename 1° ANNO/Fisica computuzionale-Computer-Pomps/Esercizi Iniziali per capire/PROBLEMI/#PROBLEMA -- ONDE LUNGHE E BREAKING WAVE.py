#PROBLEMA -- ONDE LUNGHE E BREAKING WAVES

import numpy as np
import matplotlib.pyplot as plt

#Dati
g = 9.81

#Dati chiesti all'untente 
L = float(input("Dichiara distanza dalla costa (in metri):"))
H_min = float(input("Dichiara la profondità minima (in metri):"))
H_max = float(input("Dichiara la profondità massima (in metri):"))

#controllo degli input
if L <=0:
    raise ValueError("La distanza dalla costa deve essere maggiore di 0")

if H_min <=0:
    raise ValueError("La profondità minima deve essere maggiore di 0")

if H_max <=0:
    raise ValueError("La prondità massima deve essere maggiore di 0")

#Generiamo un array con valori equispaziati 
H = np.linspace(H_min, H_max, 500)

#Calcoli 
v = np.sqrt(g * H) #Velocità dell'onda 

t = L / v #Tempo di arrivo

#Stampiamo a schermo 
print("Valore minimo di v: ", np.min(v), "m/s")
print("Valore massimo di V:", np.max(v), "m/s")

print("Valore minimo di t:", np.min(t), "m/s")
print("Valore massimo di t:", np.max(t), "m/s")

#Grafico
#--------------Primo grafico------------
fig , ax = plt.subplots(2, 1, figsize=(7,8), sharex=True)

ax[0].plot(H, v)
ax[0].set_ylabel("Velocità v(H) [m/s]")
ax[0].set_title("Valocità dell'onda in funzione della profondità")
ax[0].grid(True)

#-----------------Secondo grafico-----------------------
ax[1].plot(H, t)
ax[1].set_xlabel("Profondità H [m]")
ax[1].set_ylabel("Tempo di arrivo t(H) [s]")
ax[1].set_title("Tempo di arrivo in funzione della profondità")
ax[1].grid(True)

plt.tight_layout()
plt.show()



