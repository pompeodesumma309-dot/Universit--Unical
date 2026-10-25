#LEZIONE 4 - MOTO SU UN PIANO INCLINATO 
import numpy as np
import matplotlib.pyplot as plt

h_km = float(input("Inserisci il dislivello verticale della collina [km]: "))
gradi = float(input("Inserisci l'angolo del piano inclinato [gradi]: "))

g = 9.81

h = h_km * 1000
theta = np.deg2rad(gradi)



if gradi <= 0 or gradi >=90:
    print("Errore: l'angolo deve essere compreso tra 0 e 90 gradi.")

else:
    L = h / np.sin(theta)
    a = g * np.sin(theta)
    t_final = np.sqrt(2*L / a)
    v_final = a * t_final

    print("\nRisultati:")
    print(f"La lunghezza del tratto percorso lungo la collina e': {L}")
    print(f"L'accelerazione lungo il piano inclinato è di: {a}")
    print(f"Il tempo necessario per arrivare alla base della collina e' di: {t_final}")
    print(f"La velocita' finale dell'auto alla base della collina: {v_final}")

    t = np.linspace(0, t_final, 100)

    #Legge orarie 
    s = 0.5 * a * t**2
    v = a * t

    plt.figure()

    plt.subplot(1 ,2 ,1)
    plt.plot(t, s)
    plt.xlabel("Tempo [s]")
    plt.ylabel("Posizione lungo il piano [m]")
    plt.title("Posizione s(t)")
    plt.grid()

    plt.subplot(1 , 2, 2)
    plt.plot(t, v)
    plt.xlabel("Tempo [s]")
    plt.ylabel("Velocita' [m/s]")
    plt.title("Velocita' v(t)")
    plt.grid()

    plt.tight_layout()
    plt.show()
    