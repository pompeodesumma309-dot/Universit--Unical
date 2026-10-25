def calcolo(lst):
    numero_max=None
    cont_max=-1
    
    for num in lst:
        cont=0
        n = num
        
        while n > 0:
            if n%2==1:
                cont+=1
            
        if cont>cont_max:
            cont_max=cont
            numero_max=num 
    return numero_max
                
            

if __name__ == "__main__":
    import random
    seed = int(input())
    random.seed(seed)
    n = int(input())
    if n < 0:
        n = -n
        value = 3**n
    else:
        value = n+2
    n+=2
    lst = []
    for i in range(n):
        lst.append(random.randint(1,value))
    
    print(f"Input: {lst} - Risultato: {calcolo(lst.copy())}")