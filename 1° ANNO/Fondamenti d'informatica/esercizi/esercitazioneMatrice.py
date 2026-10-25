def stampa_solo_riga0(m):
    n= len(m)

    for c in range(n):
        print(m[0][c], end="")
    print()


##############################################################
def stampa_ultima_riga(m):
    n = len(m)
    for c in range(n):
        print(m[-1][c], end=" ")
    print()

##############################################################
def prima_colonna(m):
    n = len(m)
    for r in range(n):
        print(m[r][0], end= " ")
    print()

############################################################à
def ultima_colonna(m):
    n = len(m)
    for r in range(n):
        print(m[r][-1], end=" ")
    print()
#######################################################
def solo_bordi(m):
    n = len(m)

    for c in range(n):
        print(m[0][c], end=" ")

    for r in range(1, n):
        print(m[r][n-1], end=" ")
    
    for c in range(n-2, -1, -1):
        print(m[n-1][c], end=" ")
        
    for r in range(n-2, 0, -1):
        print(m[r][0], end=" ")
    print()

####################################################
def indici_strato0(m):
    n = len(m)

    for c in range(n):
        print((0,c), end=" ")

    for r in range(1, n):
        print((r,n-1), end=" ")
    
    for c in range(n-2, -1, -1):
        print((n-1,c), end=" ")
        
    for r in range(n-2, 0, -1):
        print((r,0), end=" ")
    print()

#########################################################
def indici_strato1(m):
    n=len(m)
    for s in range(n//2):
        for c in range(s,n-s):
            print((s,c), end=" ")

        for r in range(s+1,n-s):
            print((r,n-s-1),end="")

        for c in range(n-s-2, s-1, -1):
            print((n-s-1,c), end=" ")

        for r in range(n-s-1, s, -1):
            print((r,s), end=" ")
        print()

#########################################################à
def spirale(m):
    n = len(m)

    for s in range(n // 2):

        for c in range(s, n - s):
            print(m[s][c], end=" ")

        for r in range(s + 1, n - s):
            print(m[r][n - s - 1], end=" ")

        for c in range(n - s - 2, s - 1, -1):
            print(m[n - s - 1][c], end=" ")

        for r in range(n - s - 2, s, -1):
            print(m[r][s], end=" ")

    print()
########################################################
#prendi una lista e riscrivila nella matrcie seguendo una spirale
def lista_Spirale(m,lst):
    n = len(m)
    k=0 #sarebbe l'indice nella lista 
    for s in range(n//2):
        for c in range(s,n-s):
            m[s][c] = lst[k]
            k+=1
        for r in range(s+1,n-s):
            m[r][n-s-1] = lst[k]
            k+=1
        for c in range(n-s-2,s-1,-1):
            m[n-s-1][c]=lst[k]
            k+=1
        for r in range(n-s-2,s,-1):
            m[r][s]=lst[k]
            k+=1
        print()
##############################################################








    
