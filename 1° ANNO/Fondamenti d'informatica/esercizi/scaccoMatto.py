def in_matrice(r, c, mat):
    n = len(mat)
    if r < 0 or r > n -1 or c < 0 or c > n -1:
        return False
    return True


def scacco(mat):
    if not mat:
        return None
    n = len(mat)    

    r = 0
    c = 0

    #trovo il re 
    for r in range(n):
        for c in range(n):
            if mat[r][c]=="K":
                r_re = r
                c_re = c

    cont = 0            

    intorni = [(0,1), (1,0), (1,1), (-1,-1), (-1,0), (0,-1), (1,-1), (-1,1)]
    for dr, dc in intorni:
        r = r_re + dr
        c = c_re + dc

        while in_matrice(r,c,mat):
            if mat[r][c] == "R":
                cont += 1 
                break 
            elif mat[r][c] != "F":
                break 
            r += dr
            c += dc 
    
    return cont