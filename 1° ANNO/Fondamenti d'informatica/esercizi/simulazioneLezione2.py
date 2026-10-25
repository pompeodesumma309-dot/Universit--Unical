def in_matrice(r,c,mat):
    n = len(mat)
    
    if r>n-1 or r<0 or c>n-1 or c<0:
        return False
    return True 

def cerca_zone_positive(matrice, t_pos):
    n = len(matrice)
    
    visitati=[]
    da_visitare=[]
    somma_massima=0
    
    intorno=[(-1,0),(+1,0),(0,-1),(0,+1)]
    
    for r in range(n):
        for c in range(n):
            
            
            somma_corrente=0
            if matrice[r][c]>t_pos:
                da_visitare=[(r,c)]
                
                while da_visitare:
                    x,y = da_visitare.pop()
                    somma_corrente+=matrice[x][y]
                    visitati.append((x,y))
                    
                    for idx_riga,idx_colonna in intorno:
                        new_x, new_y= x + idx_riga, y + idx_colonna
                        if in_matrice[new_x, new_y, matrice] and (new_x, new_y) not in visitati and matrice[new_x][new_y] > t_pos: 
                            da_visitare.append((new_x,new_y))
                if somma_corrente > somma_massima:
                    somma_massima = somma_corrente
    return somma_massima

def cerca_zone_negative(matrice, t_neg):
    n = len(matrice)
    da_visitare=[]
    visitati=[]

    dimensione_massima=0
    intorno=[(-1,0),(+1,0),(0,-1),(0,+1)]
    
    for r in range(n):
        for c in range(n): 
            dimensione_corrente=0
            if matrice[r][c]<t_neg and (r,c) not in visitati:
                da_visitare= [(r,c)]
                while da_visitare:
                    x,y = da_visitare.pop()
                    dimensione_corrente+=1
                    visitati.append((x,y))
                    for idx_riga, idx_colonna in intorno:
                        new_x, new_y = x + idx_riga, y + idx_colonna
                        if in_matrice(new_x, new_y, matrice) and (new_x, new_y) not in visitati and matrice[new_x][new_y] < t_neg:
                            da_visitare.append((new_x, new_y))
                if dimensione_corrente > dimensione_massima:
                    dimensione_massima = dimensione_corrente
    return dimensione_massima


def cerca_zone(t_pos, t_neg, matrice):
    return (cerca_zone_positive(matrice, t_pos), cerca_zone_negative(matrice, t_neg))