def conto_alla_rovescia(n):
    if n == 0:
        print("Decollo! 🚀")
    else:
        print(n)
        conto_alla_rovescia(n - 1)

print(conto_alla_rovescia(8))

def fattoriale_ricorsivo(n):
    if n==1 or n==0:
        return 1
    else:
        return n * fattoriale_ricorsivo(n-1)

n=5
print(fattoriale_ricorsivo(n))

def fibonacci(n):
    if n==0:
        return 0
    if n==1:
        return 1
    else: 
        return fibonacci(n-1)+fibonacci(n-2)
    
print(fibonacci(3))

def somma_ricorsione(lista):
    if (len(lista)==0):
        return 0
    else:
        return lista[0]+somma_ricorsione(lista[1:])
    
lst=[10,20,30]
print(somma_ricorsione(lst))

def palindroma_ricorsiva(parola):
        if len(parola)==0 or len(parola)==1:
            return True
        if parola[0]!=parola[-1]:
            return False
        else:
            return palindroma_ricorsiva(parola[1:-1])
            
print(palindroma_ricorsiva("ciao"))


def inverti(parola):
    if len(parola)<=1:
        return parola
    if len(parola)>1:
        return inverti(parola[1:]) + parola[0]
    
parola2="ciao"    
print(inverti(parola2))


def piccolo_divisore(n, lst):
    divisori = []
    divisore_piccolo = None

    for i in range(1, n):
        if n % i == 0:
            divisori.append(i)

    if not lst:
        return None

    max_lst = max(lst)

    for d in divisori:
        if d > max_lst:
            divisore_piccolo = d
            break

    return divisore_piccolo

        

n=4
lst=[1,1,2]
print(piccolo_divisore(n,lst))


def trova_feste(lst1, lst2):
    lista1_pulita=list(set(lst1))
    lista2_pulita=list(set(lst2))
    festa=0
    for elem in lista1_pulita:
        for elem2 in lista2_pulita:
            if elem not in lista2_pulita and elem2 in lista1_pulita:
                festa+=1
    return festa




lst1=[2,1,3]
lst2=[2,2,2]
print(trova_feste(lst1,lst2))


def conto_alla_rovescia(n):
    if n==0:
        print("partenza!")
        return
    print(n)
    conto_alla_rovescia(n-1)
print(conto_alla_rovescia(5))

