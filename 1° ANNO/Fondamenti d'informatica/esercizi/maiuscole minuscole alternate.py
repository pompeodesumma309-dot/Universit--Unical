stringa=input("Inserisci una frase a tuo piacere: ")
posizioni_pari=stringa[0::2]
posizioni_dispari=stringa[1::2]
if posizioni_pari.isupper() and posizioni_dispari.islower():
    print("la stringa rispetta la condizione")
elif posizioni_pari.islower() and posizioni_dispari.isupper():
    print("la stringa rispetta la condizione")
else:
    print("la stringa non rispetta la condizione")
    stringa.isalpha()
    print("la stringa contiene caratteri non alfabetici")
    
    