#es1
def ricerca_con_tolleranza(x, lst, epsilon):
    for i in range(len(lst)):
        if lst[i]-epsilon<=x and x<=lst[i]+epsilon:
            return True

    return False
        
x = 3.125
lst = [0.016, 7.933, 5.479, 3.113, 6.787, 9.081]
epsilon = 0.1
print(ricerca_con_tolleranza(x,lst,epsilon))

#es2
def ricerca_con_tolleranza2(sub,lst,epsilon):
    risultato=True
    for i in range(len(sub)):
        risultato = risultato and ricerca_con_tolleranza(sub[i], lst, epsilon)
    return risultato
    
sub = [3.125, 6.781]
lst = [0.016, 7.933, 5.479, 3.113, 6.787, 9.081]
epsilon = 0.01

print(ricerca_con_tolleranza2(sub,lst,epsilon))

#es3
def stampa_matrice(M):
    [print(r) for r in M]

def scambia_funzione(c1,c2,M):
    for riga in M:
        riga[c1], riga[c2] = riga[c2],riga[c1]
        
    
c1 = 1
c2 = 3
M = [[11, 32, 93, 74],
     [25, 46, 97, 58],
     [89, 10, 11, 12]]
print(scambia_funzione(c1,c2,M))
print(stampa_matrice(M))

#es4
def stampa_matrice(M):
    [print(r) for r in M]

def is_submatrix(sub, mat):
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            if mat[i][j] == sub[0][0]:
                submatrix = True
                
                for k in range(len(sub)):
                    for l in range(len(sub[0])):
                        if mat[i+k][j+l] != sub[k][l]:
                            submatrix = False
                            break
                    if not submatrix:
                        break
                if submatrix: 
                    return True
    return False

A = [[46, 97],
     [10, 11]]

M = [[11, 32, 93, 74],
     [25, 46, 97, 58],
     [89, 10, 11, 12]]

print("A = ")
stampa_matrice(A)
print("M = ")
stampa_matrice(M)
print()
print(f"È una sottomatrice: {is_submatrix(A, M)}")
A = [[25, 26],
     [31, 73]]
print(f"È una sottomatrice: {is_submatrix(A, M)}")


