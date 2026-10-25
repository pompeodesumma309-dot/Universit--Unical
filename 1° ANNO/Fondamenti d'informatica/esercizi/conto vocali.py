frase=input("inserisci una parola: ")
cont = 0
num_vocali = 0
while cont < len(frase):
    if frase[cont].lower() in "aeiou":
        num_vocali += 1
    cont += 1
print("il numero di vocali all'interno della frase e':", num_vocali)


