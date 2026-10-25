def in_matrice(x,y,n,m):
    if x>= n or x<0 or y>= m or y<0:
        return False 
    return True

def somma_matrice(x,y,l,mat):
    somma=0
    for i in range(l):
        for j in range(l):
            somma+=mat[x+i][y+j]
    return somma

def conta_sottomatrici(mat, t):
    n=len(mat)
    m=len(mat[0])

    l=min(n,m)

    cont=0

    while (l>=2):
        for r in range(n):
            for c in range(m):
                if in_matrice(r+l-1, c+l-1, n, m):
                    if somma_matrice(r,c,l,mat)<t:
                        cont+=1
        
        l-=1
    return cont
    #########################################################à

def calcola_somma_cumulativa(lst):
    lista=[]
    somma=0
    for i in range(len(lst)):
        lista.append(lst[0])
        somma+=lst[i]
        if somma:
            lista.append(lst[i])
            
    return lista


           