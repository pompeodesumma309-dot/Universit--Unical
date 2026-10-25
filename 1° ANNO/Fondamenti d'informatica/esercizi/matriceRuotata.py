def ruota_tutti_gli_strati(m):
    n = len(m)

    # per ogni strato s
    for s in range(n // 2):
        L = []

        # 1) ESTRAI LO STRATO s IN UNA LISTA L

        # lato alto
        for c in range(s, n - s):
            L.append(m[s][c])

        # lato destro
        for r in range(s + 1, n - s):
            L.append(m[r][n - s - 1])

        # lato basso
        for c in range(n - s - 2, s - 1, -1):
            L.append(m[n - s - 1][c])

        # lato sinistro
        for r in range(n - s - 2, s, -1):
            L.append(m[r][s])

        # 2) RUOTA LA LISTA DI UN PASSO (a destra)
        L = [L[-1]] + L[:-1]

        # 3) RISCRIVI LO STRATO s CON I VALORI RUOTATI

        k = 0

        # lato alto
        for c in range(s, n - s):
            m[s][c] = L[k]
            k += 1

        # lato destro
        for r in range(s + 1, n - s):
            m[r][n - s - 1] = L[k]
            k += 1

        # lato basso
        for c in range(n - s - 2, s - 1, -1):
            m[n - s - 1][c] = L[k]
            k += 1

        # lato sinistro
        for r in range(n - s - 2, s, -1):
            m[r][s] = L[k]
            k += 1
       
matrice_esempio = [
    [1,  2,  3,  4],
    [12, 13, 14, 5],
    [11, 16, 15, 6],
    [10, 9,  8,  7]
]

print("Prima della rotazione:")
for riga in matrice_esempio:
    print(riga)

ruota_tutti_gli_strati(matrice_esempio)

print("\nDopo la rotazione:")
for riga in matrice_esempio:
    print(riga)