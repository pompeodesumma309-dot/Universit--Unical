def rimozione_rumore(M):

    n,m= len(M), len(M[0])
    matrice=[[0]*m for i in range(n)]

    for i in range(n):
        for j in range(m):
            
            
            delta_i=[-1,-1,-1,0,0,1,1,1]
            delta_j=[-1,0,1,-1,1,-1,0,1]
            new_lista=[]
            new_lista.append(M[i][j])

            for k in range(8):
                vicini_i= i + delta_i[k]
                vicini_j= j + delta_j[k]

                if 0<=vicini_i<n and 0<=vicini_j<m:
                    new_lista.append(M[vicini_i][vicini_j])
            
            for cont in range(len(new_lista)): 
                for z in range(len(new_lista)-1):
                    if new_lista[z]>new_lista[z+1]:
                        tmp=new_lista[z]
                        new_lista[z]=new_lista[z+1]
                        new_lista[z+1]=tmp
            mediano= new_lista[len(new_lista)//2]

            matrice[i][j]=mediano

    return matrice


M = [
    [10, 12, 11, 100],  # Il 100 è rumore (angolo)
    [11, 200, 10, 12],  # Il 200 è rumore (centro)
    [10, 12, 11, 10]    # Riga pulita
]
#####################################################################
def trova_intruso(grande,piccola):
    n=len(grande)
    m=len(piccola)

    for i in range(n-m+1):
        for j in range(n-m+1):

            is_sottoMatrice=True
            for r in range(m):
                for c in range(m):

                    if piccola[r][c]!=grande[i+r][j+c]:
                        is_sottoMatrice=False
                        break

                if is_sottoMatrice==False:
                    break
            if is_sottoMatrice==True:
                return (i,j)
    return(-1,-1)

grande = [
    [10, 12, 11, 100],  # Il 100 è rumore (angolo)
    [11, 9, 9, 12],  # Il 200 è rumore (centro)
    [10, 9, 9, 10]
]

piccola=[
    [9,9],
    [9,9]
]
##############################################################
def simula_biliardo(tavolo):

    n=len(tavolo)
    m=len(tavolo[0])

    i=0
    j=0

    somma=0
    count=0

    orizontale=1
    verticale=1

    while True:

        valore=tavolo[i][j]

        somma+=valore
        

        if valore==-1:
            break

        count+=1
        if count>=50:
            break
        
        prossimo_i= i + verticale
        prossimo_j= j + orizontale

        if prossimo_i>=n or 0>prossimo_i:
            verticale*=-1
            prossimo_i= i + verticale #ricalcolo la mossa corretta

        if prossimo_j>=m or 0>prossimo_j:
            orizontale*=-1
            prossimo_j=j + orizontale
        
        i = prossimo_i
        j=prossimo_j


    return somma

        
            




