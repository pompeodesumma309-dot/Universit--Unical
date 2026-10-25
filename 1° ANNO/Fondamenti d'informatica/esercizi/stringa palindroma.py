stringa=input("Inserisci una frase a tuo piacimento:")
stringa = stringa.replace(" ", "").lower()
palindroma=stringa==stringa[::-1]
if palindroma:
    print("la stringa è palindroma")
else:
    print("la stringa non è palindroma") 