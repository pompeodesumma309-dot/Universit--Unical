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
