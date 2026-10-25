def sottolista_massima(lst):
    if not lst:
        return None
    somma=0   
    for i in range(len(lst)):
        for j in range(i+1, len(lst)):
            if lst[i]==lst[j]:
                somma+=lst[j]

    return somma

lst=[3, 10, 2, 5, 2, 8, 8, 8, 7, 4]
print(sottolista_massima(lst))
