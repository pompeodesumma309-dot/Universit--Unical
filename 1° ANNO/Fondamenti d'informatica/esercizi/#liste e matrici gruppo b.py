#liste e matrici gruppo b
#es5
lista=[1,2,3,4,5,6,7,8,9,10]
somma=0
""""
for elem in lista:
    somma+=elem"""
somma=sum(lista)

print(somma)

#es6
lista2=["marco","luigi","Laura"]
print(len(lista2))

#es9
lista3=["marco","luigi","Laura"]
print(lista3[::-1])

#
lista4=[0]*10
print(lista4)

#es
lista5=["marco","luigi","Laura"]
lista5.append("ciao")
print(lista5)

#es13
lista6=[1,2,3,4]
for elem in lista6:
    potenza=elem**2
    print(potenza)

#es15
lista7=[1,2,3,5]
for x in lista7:
    doppio=(x*2)
    print(doppio)

#es17
lista8=["mela","banana","arancia","kiwi"]
for str in lista8:
    print(str)

#es18
def somma_elementi(lista):
    somma=0
    for elem in lista:
        somma+=elem
    return somma

lst=[1,2,3,4,5]
print(somma_elementi(lst))

#es19
matrice=[
        [1,2],
        [3,4],
        [5,6],
]
print(matrice[1][1])

#es20
matrice2=[
        [1,2,3],
        [4,5,6],
]
[print(r) for r in matrice2]

#es21
def max_lista(lista):
    return max(lista)

                     
lista11=[1,2,3]
print(max_lista(lista11))

#es26
def rimuovi_elemento(lista, elemento):
    if elemento in lista:
        lista.remove(elemento)
    return lista

# Esempio d'uso
numeri = [1, 2, 3, 2, 4]
nuova_lista = rimuovi_elemento(numeri, 2)
print(nuova_lista)

#es

matrice3=[
        [1,2,3],
        [4,5,6]
]
somma1=0
for elem in matrice3:
    if sum(elem)%2==0:
        print(elem)
    
#es28
def conta_occorrenze(lista,elemento):
    return lista.count(elemento)
print(conta_occorrenze([1, 2, 3, 2, 4, 2], 2))

def media_numeri_casuali(lista):
    somma=0
    for elem in lista:
        somma+=elem
        media=somma/len(lista)
    return media

lista15=[]
n=int(input("Quanti numeri vuoi inserire all'interno della lista?"))
for i8 in range(1,n+1):
    num=int(input(f"inserisci il numero {i8}: "))
    lista15.append(num)
print(f"La media dei numeri all'interno della tua lista e': {media_numeri_casuali(lista15)} ")


#es







