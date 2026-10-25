stringa=input("Inserisci una frase:")
minuscole=str.islower(stringa)
maiuscole=str.isupper(stringa)
if maiuscole:
 print("La stringa è formata da solo maiuscole:",maiuscole)
elif minuscole:
 print("La stringa è formata da solo mainuscole", minuscole)
else:
 print ("la stringa è una mista")
