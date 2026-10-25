numeri = int(input("Inserisci il numero di interi da sommare: "))
numero_cicli = numeri
somma=0
numeri=0

while numeri<numero_cicli:
    num = int(input("Inserisci il numero: "))
    somma=num+somma
    numeri+=1
print("La somma è:", somma)    



numeri2 = int(input("Inserisci il numero di interi da sommare: "))
somma=0
cont=0
for cont in range(numeri2):
    num = int(input("Inserisci il numero: "))
    somma=num+somma
print("La somma è:", somma)

