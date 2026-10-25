def is_primo(n):
    if n<=1:
        return False
    for i in range(2,n):
        if n%i==0:
            return False
    return True

def percorso_salti(M):
    n=len(M)
    m=len(M[0])

    cont=0
    somma=0

    i=0
    j=0

    while True:

        valore=M[i][j]
        somma+=valore
        cont+=1

        if is_primo(valore):
            unita=valore%10
            passo = unita if unita!=0 else 1
            prossimo_i=i
            prossimo_j=j+passo

        elif valore%5==0:
            prossimo_i=i+2
            prossimo_j=j
        else:
            prossimo_i=i+1
            prossimo_j=j

        if 0<=prossimo_i<n and 0<=prossimo_j<m:
            break

        i=prossimo_i
        j=prossimo_j

    return somma/cont
###########################################################################
def somma_serpente(M):
    n=len(M)
    
    somma_totale=0
    somma_riga_precedente=0

    for r in range(n):
        somma_tiga_attuale=0
        for c in range(n):
            somma_tiga_attuale+=M[r][c]
        if r%2==0:
            for c in range(n):
                if M[r][c]>somma_riga_precedente:
                    somma_totale+=M[r][c]
        else:
            for c in range(n-1,-1,-1):
                if c%2!=0:
                    somma_totale+=M[r][c]

        somma_riga_precedente= somma_tiga_attuale

    return somma_totale

#################################################################
def trova_percorso_massimo(M):
    n=len(M)
    lista=[]
    r,c=0,0
    
    while True:
        val_destra=-1
        val_basso=-1
        val_diag=-1

        if c + 1 < n:
            val_destra = M[r][c+1]
        if r+ 1 < n:
            val_basso = M[r+1][c]
        if r + 1 < n and c + 1 < n:
            val_diag = M[r+1][c+1]

        if val_diag >= val_destra and val_diag >= val_basso and val_diag != -1:
            r = r + 1
            c = c + 1
            lista.append(M[r][c])
        elif val_destra >= val_basso and val_destra != -1:
            c = c + 1
            lista.append(M[r][c])
        elif val_basso != -1:
            r = r + 1
            lista.append(M[r][c])
        else:
            break 

    return lista

##########################################################################################
def radar_matrice(M, soglia):
    n = len(M)
    m=len(M[0])
    somma=0

    for r in range(n):
        for c in range(m):
            valori=[]
            valore=M[r][c]

            if r-1>=0:
                valori.append(M[r-1][c])
            if r+1<n:
                valori.append(M[r+1][c])
            if  c-1>=0:
                valori.append(M[r][c-1])
            if c+1<n:
                valori.append(M[r][c+1])
            
            if sum(valori)>soglia:
                somma+=valore
    return somma

#STESSO ESERCIZIO USANDO I DELTA
def radar_matrice(mat, soglia):
    righe = len(mat)
    colonne = len(mat[0])
    totale = 0

    # Delta per i 4 vicini: Su, Giù, Sinistra, Destra
    delta = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    for r in range(righe):
        for c in range(colonne):
            somma_vicini = 0

            for dr, dc in delta:
                nr = r + dr
                nc = c + dc

                # Controllo che il vicino esista
                if 0 <= nr < righe and 0 <= nc < colonne:
                    somma_vicini += mat[nr][nc]

            if somma_vicini > soglia:
                totale += mat[r][c]

    return totale
###########################################################################
def percorso_alternato(M):
    n=len(M)
    m=len(M[0])

    r,c=0,0
    totale=0

    interuttore=True

    while True:

        if not (0<=r<n and 0<=c<m):
            break

        valore=M[r][c]

        if interuttore==True:
            totale+=valore
            r=r+1
            interuttore=False

        elif interuttore==False:
            if valore==0:
                c=c+1
                interuttore=True
            else:
                c=c+valore
                interuttore=True
        
    return totale 
####################################################################################
def cornice_massima(M):
    n=len(M)
    m=len(M[0])
    somma_max=-10000000

    for r in range(n-1):
        for c in range(m-1):
            somma = M[r][c] + M[r][c+1] + M[r+1][c] + M[r+1][c+1]

            if somma_max<somma:
                somma_max=somma

    return somma_max
##################################################################################
def simulazione_valanga(M):
    n=len(M)
    m=len(M[0])

    r,c=0,0
    somma=M[0][0]

    while True:
        if not(0<=r<n and 0<=c<m):
            break 
        
        valori=[]
        valore=M[r][c]

        if r-1>=0:
            valori.append([M[r-1][c], r-1, c])
        if r+1<n:
            valori.append([M[r+1][c], r+1, c])
        if  c-1>=0:
            valori.append([M[r][c-1], r, c-1])
        if c+1<m:
            valori.append([M[r][c+1], r ,c+1])
        
        if not valori:
            break
        
        candidati=[] 
        for v in valori:
            if v[0]<valore:
                candidati.append(v)

        if not candidati:
            break
        
        minimo_valore=candidati[0][0]
        for v in candidati:
            if v[0]<minimo_valore:
                minimo_valore=v[0]
        
        vincitori=[]
        for v in candidati:
            if v[0]==minimo_valore:
                vincitori.append(v)

        for v in vincitori:
            somma+=v[0]

        riga_piu_grande=vincitori[0]
        for v in vincitori:
            if v[1]>riga_piu_grande[1]:
                riga_piu_grande=v

        r=riga_piu_grande[1]
        c=riga_piu_grande[2]

    return somma

################################################################
def verifica_specchio(M):
    n=len(M)
    m=len(M[0])

    for r in range(n):
        for c in range(m//2):
            if M[r][c]+M[r][m-1-c]!=10:
                return False
    for r in range(n//2):
        for c in range(m):
            if M[r][c]+M[n-1-r][c]!=10:
                return False
            
    return True
#################################################################à
def perimetro_massimo(M,k):
    n=len(M)
    m=len(M[0])
    massimo=-100000
    for i in range(n-k+1):
        for j in range(m-k+1):
            somma=0
            for c in range(j,j+k):
                somma+=M[i][c]

            for c in range(j,j+k):
                somma+=M[i+k-1][c]

            for r in range(i+1, i+k-1):
                somma+=M[r][j]

            for r in range(i+1, i+k-1):
                somma+=[r][j+k-1]
            
            if somma>massimo:
                massimo=somma
    return massimo
                    
###########################################################################################à
def forzetta_invisibile(M):
    n=len(M)
    m=len(M[0])

    cont=0
    direzioni = [(-1,0), (1,0), (0,-1), (0,1)]

    for r in range(n):
        for c in range(m):

            valore = M[r][c]
            visibile = False

            for dr, dc in direzioni:
                rr = r + dr
                cc = c + dc
                ok = True

                # scorro la direzione con la tua logica
                while 0 <= rr < n and 0 <= cc < m:
                    if M[rr][cc] < valore:
                        rr += dr
                        cc += dc
                        continue
                    else:
                        ok = False
                        break

                if ok:
                    visibile = True
                    break   # non serve controllare altre direzioni

            if visibile:
                cont += 1

    return cont

################################################################
def labirinto_portali(M):
    n=len(M)
    m=len(M[0])

    distanza=0
    r,c=0
    visitati=set()
    portali={}

    for i in range(n):
        for j in range(m):
            cella=M[i][j]
            if cella.isalpha():
                if cella not in portali:
                    portali[cella]=[]
                portali[cella].append((i,j))

    while True:
        valore=M[r][c]
        distanza+=1

        if (r,c)==(n-1,m-1):
            return distanza
        
        mosse_disponibili=[]
        if r-1>=0:
            mosse_disponibili.append((r-1,c))
        if r+1<n:
            mosse_disponibili.append((r+1,c))
        if  c-1>=0:
            mosse_disponibili.append((r,c-1))
        if c+1<m:
            mosse_disponibili.append((r,c+1))
        
        if not mosse_disponibili:
            return -1
        
        if valore.isalpha():
            pos1, pos2 = portali[valore]
            if (r,c) ==pos1:
                r,c=pos2
            else:
                r,c=pos1


            

        

        


        

                
        
        

