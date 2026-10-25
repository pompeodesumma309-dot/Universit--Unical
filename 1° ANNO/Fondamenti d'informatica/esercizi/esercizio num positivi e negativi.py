numeri2 = int(input("Inserisci il numero di interi da sommare: "))
somma_positivi=0
somma_negativi=0
cont=0
for cont in range(numeri2):
    num = int(input("Inserisci il numero: "))
    if num<0:
        somma_negativi+=num
    else:
     somma_positivi+=num
print("La somma dei numeri postivi è:", somma_positivi)
print("La somma dei numeri negativi è:", somma_negativi)



numeri = int(input("Inserisci il numero di interi da sommare: "))
numero_cicli = numeri
somma=0
numeri=0
somma_negativi2=0
somma_positivi2=0
while numeri<numero_cicli:
    num = int(input("Inserisci il numero: "))
    if num<0:
        somma_negativi2+=num
        numeri+=1
    else:
     somma_positivi2=num+somma_positivi2
     numeri+=1
print("La somma dei nuemri positivi è:", somma_positivi2)  
print("La somma dei numeri negativi è:", somma_negativi2) 