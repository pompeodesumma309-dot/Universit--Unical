def matrice_tutti_pari(mat):
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            valore=mat[i][j]
            if valore%2!=0:
                return False

    return True


mat=[
    [2,2,2],
    [2,2,2],
    [2,2,2]
]

#######################################
def verifica_croce(M):
    n=len(M)
    m=len(M[0])

    for i in range(n):
        for j in range(m):
            
            diagonale_prin= i==j
            diagonale_sec= j==(n-1)-i

            if diagonale_prin or diagonale_sec:
                valore=M[i][j]
                if valore<=0:
                    return False
    return True


mat=[
    [2,2,2],
    [2,2,2],
    [0,2,0]
]
#################################################################
def conta_picchi(M):
    n=len(M)
    m=len(M[0])
    cont=0

    for i in range(n):
        for j in range(m):

            delta_i=[-1,-1,-1,0,0,1,1,1]
            delta_j=[-1,0,1,-1,1,-1,0,1]
            
            valore=M[i][j]
            picco=False

            for k in range(8):
                vicino_i= i + delta_i[k]
                vicino_j= j + delta_j[k]

                if 0<=vicino_i<n and 0<=vicino_j<m:
                    valore_vicino=M[vicino_i][vicino_j]

                    if valore<=valore_vicino:
                        picco=True
                        break
            if picco:
                cont+=1

    return cont
##############################################################
def smooth_matriX(M):
    n=len(M)
    m=len(M[0])

    nuova_matrice=[[0]*n for i in range(m)]

    for i in range(n):
        for j in range(m):

            delta_i = [-1,-1,-1,0,0,1,1,1]
            delta_j= [-1,0,1,-1,1,-1,0,1]

            somma=M[i][j]
            cont=1
            
            for k in range(8):
                vicino_i = i + delta_i[k]
                vicino_j= j + delta_j[k]

                if 0<=vicino_i<n and 0<=vicino_j<m:
                    valore_vicino=M[vicino_i][vicino_j]
                    cont+=1
                    somma+=valore_vicino

            media= somma//cont

            nuova_matrice[i][j]=media

    return nuova_matrice

mat=[
    [2,2,2],
    [2,2,2],
    [0,2,0]
]
#################################################################
def mappa_predatori(M):
    n=len(M)
    m=len(M[0])

    nuova_matrice=[[False]*m for i in range(n)]

    for i in range(n):
        for j in range(m):

            somma=0
            delta_i=[-1,-1,-1,0,0,1,1,1]
            delta_j=[-1,0,1,-1,1,-1,0,1]

            for k in range(8):
                vicini_i=i + delta_i[k]
                vicino_j=j + delta_j[k]
                
                if 0<=vicini_i<n and 0<=vicino_j<m:
                    valore_vicino=M[vicini_i][vicino_j]
                    somma=+valore_vicino
                
            if (i==0) or (i==n-1) or (j==0) or (j==m-1):
                soglia=20
            else:
                soglia=50

            if somma>soglia:
                nuova_matrice[i][j]=True
            else:
                nuova_matrice[i][j]=False

    return nuova_matrice
#################################################################
def evoluzione(M):
    n=len(M)
    m=len(M[0])

    nuova_matrice=[[0]*m for i in range(n)]

    for i in range(n):
        for j in range(m):

            delta_i=[-1,-1,-1,0,0,1,1,1]
            delta_j=[-1,0,1,-1,1,-1,0,1]
            valore=M[i][j] 
            vicini_vivi=0

            for k in range(8):
                vicini_i= i + delta_i[k]
                vicini_j= j +delta_j[k]

                if 0<=vicini_i<n and 0<=vicini_j<m:
                    if M[vicini_i][vicini_j]==1:
                        vicini_vivi+=1

            if valore==1:
                    if (vicini_vivi<2 or vicini_vivi>3):
                        nuova_matrice[i][j]=0
                    else:
                        nuova_matrice[i][j]=1

            elif valore==0:
                if (vicini_vivi==3):
                        nuova_matrice[i][j]=1
                else:
                    nuova_matrice[i][j]=0
    return nuova_matrice

mat=[
    [1,1,1],
    [0,1,0],
    [1,1,1]
]
################################################################à
def apocalisse_zombi(M):
    n=len(M)
    m=len(M[0])
    nuova_matrice=[[0]*m for i in range(n)]

    for i in range(n):
        for j in range(m):

            delta_i=[-1,-1,-1,0,0,1,1,1]
            delta_j=[-1,0,1,-1,1,-1,0,1]
            valore_attuale=M[i][j]

            vicini_umani=0
            vicini_zombi=0
            vicini_boss=0

            for k in range(8):
                vicini_i= i + delta_i[k]
                vicini_j= j + delta_j[k]

                if 0<=vicini_i<n and 0<=vicini_j<m:
                    valore_vicino=M[vicini_i][vicini_j]
            

                    if valore_vicino==1:
                        vicini_umani+=1

                    if valore_vicino==2:
                        vicini_zombi+=1
                            
                    if valore_vicino==3:
                        vicini_boss+=1

            somma_mostri= vicini_boss + vicini_zombi

            if valore_attuale==1:
                if vicini_zombi>=2 or vicini_boss>=1:
                    nuova_matrice[i][j]=2
                else:
                    nuova_matrice[i][j]=1
            
            elif valore_attuale==2:
                if vicini_umani==0:
                    nuova_matrice[i][j]=0
                elif somma_mostri>4:
                    nuova_matrice[i][j]=3
                else:
                    nuova_matrice[i][j]=2

            elif valore_attuale==3:
                nuova_matrice[i][j]=3
            
            elif valore_attuale==0:
                if vicini_umani==2:
                    nuova_matrice[i][j]=1
                else:
                    nuova_matrice[i][j]=0
    return nuova_matrice

                    
M = [
    [0, 1, 1, 0],
    [1, 2, 3, 0],
    [2, 2, 2, 2],
    [2, 2, 2, 1]
]
#########################################à
def calcola_mat(M):
    n=len(mat)

    i=0
    j=0
    somma=0

    while True: 

        valore=M[i][j]
        somma+=valore

        prossimo_i=i
        prossimo_j=j

        if valore%2==0:
            prossimo_i=i+1
            prossimo_j=j
        elif valore%3==0:
            prossimo_i=i
            prossimo_j=j+1
        else:
            prossimo_i=i+1
            prossimo_j=j+1
        
        if 0<=prossimo_i<n and 0<=prossimo_j<n:
            i = prossimo_i
            j = prossimo_j
        else:
            break

    return somma
####################################################################à
def risolvi_cavallo(scacchiera,x,y):
    N = len(scacchiera)

    delta_r=[-2, -1,  1,  2, 2, 1, -1, -2]
    delta_c=[-1, -2, -2, -1, 1, 2,  2,  1]

    visti=[[False]*N for i in range(N)] #creiamo una tabella con tutti valori False, cosi poi quando saremmo passati da quel valore diventerà True

    visti[x][y] = True
    passi=0

    r=x
    c=y

    while True:
        indice_mossa=scacchiera[r][c]

        prossimo_r= r + delta_r[indice_mossa]
        prossimo_c= c + delta_c[indice_mossa]

        fuori_riga= (prossimo_r<0) or (prossimo_r>=N)
        fuori_colonna=(prossimo_c<0) or (prossimo_c >= N)

        if fuori_riga or fuori_colonna:
            return passi

        if visti[prossimo_r][prossimo_c]==True:
            return passi
        
        passi+=1
        visti[prossimo_r][prossimo_c]=True
        r=prossimo_r
        c=prossimo_c
#############################################################################
def pulisci_stanza(stanza):
    n = len(stanza)
    m=len(stanza[0])

    i=0
    j=0
    caselle=0
    
    # 1=destra -1=sinistra
    direzione=1

    while True:
        caselle+=1

        prossimo_j=j+direzione

        bloccato=False
        if 0<=prossimo_j<m:
            bloccato=True
        elif stanza[i][prossimo_j]==1:
            bloccato=True
        
        if not bloccato:
            j = prossimo_j
        else:
            i= i+1
            direzione*=-1

            if i>=n:
                break
            if stanza[i][j]==1:
                break

    return caselle

        











