def is_primo(n):
    if n <= 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def is_speciale(n):
    if n <= 1 or is_primo(n):
        return True
    
    for d in range(2, n):
        if n % d == 0 and not is_primo(d):
            return False
    return True

def calcola_speciali(lst):
    return sum(num for num in lst if is_speciale(num))
    
                 

lst=[8, 5, 12, 16, 3, 1, 16, 9]
print(calcola_speciali(lst))


def sottolista_massima(lst):
    somma=0
    somma2=0
    for i in range(len(lst)):
        for j in range(len(lst)):
            
            if not lst:
                return None
            
            if len(lst)==1:
                return lst[i]
            
            if lst[i]==lst[i+1]:
                somma+=lst[i]
                if lst[j+1]==lst[j+2]:
                    somma2+=lst[j]
                    if somma>somma2:
                        return somma
                    else:
                        return somma2
      

lst1=[1, 2, 2, 3, 3, 1, 1, 2, 4, 4]
print(sottolista_massima(lst1))