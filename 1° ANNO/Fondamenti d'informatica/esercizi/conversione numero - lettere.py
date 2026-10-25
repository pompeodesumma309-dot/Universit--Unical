print("inserisci un numero da 30 a 99:")
num=int(input())
num_convertito=str(num)

prima_cifra = {3: "trenta", 4: "quaranta", 5: "cinquanta", 6: "sessanta", 7: "settanta", 8: "ottanta", 9: "novanta"} 
seconda_cifra = {1: "uno", 2: "due", 3: "tre", 4: "quattro", 5: "cinque", 6: "sei", 7: "sette", 8: "otto", 9: "nove"}
prima_cifra = prima_cifra.get(int(num_convertito[0]))
seconda_cifra = seconda_cifra.get(int(num_convertito[1]))
if prima_cifra and seconda_cifra:
    if seconda_cifra in ["uno", "otto"]:
        prima_cifra = prima_cifra[:-1]
    print("il numero in lettere è:", prima_cifra, seconda_cifra, sep="")
else:
    print("il numero non è compreso tra 30 e 99")