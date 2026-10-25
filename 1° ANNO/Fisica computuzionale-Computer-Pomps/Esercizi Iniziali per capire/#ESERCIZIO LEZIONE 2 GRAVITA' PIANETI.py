import numpy as np
import matplotlib.pyplot as plt
# La libreria tabulate è utile per una stampa più ordinata quando vogliamo printare una tabella
from tabulate import tabulate

def calcola_gravita(raggi, masse, nomi_pianeti):
    """
    Calcola l'accelerazione di gravità per una lista di pianeti.
    
    Parametri:
        raggi (array): array dei raggi dei pianeti in metri.
        masse (array): array delle masse dei pianeti in kg.
        nomi_pianeti (array): array con i nomi dei pianeti.
    """
    G = 6.67430e-11  # Costante gravitazionale in m^3/kg/s^2
    gravita = G * masse / (raggi ** 2)  # Formula per l'accelerazione di gravità
    
    # Creazione del grafico
    plt.figure(figsize=(10, 5))
    plt.bar(nomi_pianeti, gravita, color='skyblue')
    plt.xlabel("Pianeti", fontsize=14)
    plt.ylabel("Accelerazione di gravità ($m/s^2$)", fontsize=14)
    plt.title("Accelerazione di gravità sui pianeti del sistema solare")
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    plt.show()
    
    return gravita

