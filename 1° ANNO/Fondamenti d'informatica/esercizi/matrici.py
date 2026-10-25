def matrice_somma_pari_dispari(m):
    total_sum=0
    for i in range(len(m)):
        if m[i][i]%2==0:
            total_sum+=m[i][i]
        if m[i][len(m)-i-1]%2!=0:
            total_sum+=m[i][len(m)-i-1]
    return total_sum

m = [
    [2, 4, 7],
    [3, 1, 3],
    [2, 2, 4]
]
print(matrice_somma_pari_dispari(m))

#es2 scambia le righe con le colonne 
def scambio_righe_colonne(m):
    for c in range(len(m[0])):
        for r in range(len(m)):
            print(m[r][c], end=" ")
        print()

matrice = [
    [2, 4, 7],
    [3, 1, 3]
]
print(scambio_righe_colonne(matrice))

#es3
def valid_positions(m, position):
    i, j = position[0], position[1]
    to_check = []
    if i > 0:
        if m[i-1][j] == 0:
            to_check.append((i-1,j))
    if i < len(m)-1:
        if m[i+1][j] == 0:
            to_check.append((i+1,j))
    if j > 0:
        if m[i][j-1] == 0:
            to_check.append((i,j-1))
    if j < len(m)-1:
        if m[i][j+1] == 0:
            to_check.append((i,j+1))
    return to_check

def exists_path(m):
    visited_path = [(0,0)]
    for position in visited_path:
        to_check = valid_positions(m, position) #usa la funzione che abbiamo creato sopra per torvare le celle adiacenti libere alla posizione corrente
        for element in to_check:#cicla su tutte le celle adiacenti libere tovate 
            if element == (len(m)-1, len(m)-1):#controlla se la cella corrente è la cella finale (quella in basso a destra)
                return True #se si, ho trovato un percorso
            if element not in visited_path: #controlla se la cella non è stata gia visitata
                visited_path.append(element)#aggiunge la nuova cella alla lista, cosi verrà espolarata nel prossimo giro 
    return False  #se il ciclo finisce non ha mai raggiunto la cella finale, significa che non esiste un percorso   

matrice = [
    [0, 0, 1, 0],
    [1, 0, 1, 0],
    [0, 0, 0, 0],
    [1, 1, 0, 0]
]
print(exists_path(matrice))