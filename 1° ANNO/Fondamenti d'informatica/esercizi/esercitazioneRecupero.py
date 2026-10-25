def sottolista_massima(lst):
    if not lst:
        return None
    
    new_lista=[]
    trovato=False
    for i in range(len(lst)):
        numero_max=max(lst)

        if lst[i]==lst[i+1]:
            trovato=True

        if trovato==True:
            numero_max-=1
            if lst[i]>=numero_max:
                new_lista.append(lst[i])

        elif trovato==False:
            return numero_max

lst=[1, 2, 3, 3, 1, 2, 4]
print(sottolista_massima(lst))

