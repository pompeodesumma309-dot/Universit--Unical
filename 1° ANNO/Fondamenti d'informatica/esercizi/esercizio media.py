cont_num= int(input("Inserisci il numero di numeri con cui vuoi avere una media(interi): "))
numero_cicli=cont_num
somma=0
cont_num=0
while numero_cicli>cont_num:
    num = int(input("Inserisci i numeri: "))
    somma=num+somma
    media=somma/numero_cicli
    cont_num+=1
print("La media è:", media)

cont_num2= int(input("Inserisci il numero di numeri con cui vuoi avere una media(interi): "))
contatore=0
somma=0
for conatatore in range(cont_num2):
    num2= int(input("Inserisci i numeri: "))
    somma+=num2
    media=somma/cont_num2
print("La media è:", media)
    