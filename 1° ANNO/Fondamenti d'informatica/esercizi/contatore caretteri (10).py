#Scrivere un programma che riceva in input una stringa dall'utente e verifichi se la lunghezza della stringa è maggiore, minore o uguale a 10 caratteri.
stringa = input("Inserisci una stringa: ")
lunghezza = len(stringa)
if lunghezza >10:    
    print("La stringa è maggiore di 10 caretteri")
elif lunghezza <10:
    print("La stringa è minore a 10 caretteri")
else:
    print("la stringa è uguale a 10 caratteri")
