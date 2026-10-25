righe = 3
colonne = 3
matrice = []

for i in range(righe):
    riga = []
    for j in range(colonne):
        valore = int(input(f"Inserisci il valore per la posizione [{i}][{j}]: "))
        riga.append(valore)
    matrice.append(riga)

# Stampa la matrice
print("Matrice inserita:")
for riga in matrice:
    print(*riga)
