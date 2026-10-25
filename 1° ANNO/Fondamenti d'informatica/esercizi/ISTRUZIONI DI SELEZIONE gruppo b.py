#ESERCIZI SULLE ISTRUZIONI DI SELEZIONE 
#es1
num1=int(input("Inserisci un numero: "))
if num1>0:
    print("Il numero e' positivo.")
else:
    print("Il numero non e' positivo.")

#es2
num2=int(input("Inserire il primo numero:"))
num3=int(input("Inserire il secondo numero:"))
num_max=None
if num2>num3:
    num_max=num2
elif num3>num2:
    num_max=num3
else:
    print("I numeri inseriti sono uguali.")
print(f"Il numero più grande tra i due e': {num_max}")


#es3
num4=int(input("Inserire un numero:"))
if num4%2==0:
    print("Il numero inserito e' pari.")
else:
    print("Il numero inserito non e' un numero pari.")

#es4
num5=int(input("Inserire un numero:"))
intervallo=(1,2,3,4,5,6,7,8,9,10)
if num5 in intervallo:
    print("Il numero fa parte dell'intervallo.")
else:
    print("Il numero non fa parte dell'intervallo.")

#es5
stringa=str(input("Inserire una stringa:"))
if stringa=="Python":
    print("Si.")
else:
    print("No")

#es6
voto=float(input("Inserire il voto dello studente: "))
if voto>=6:
    print("Promosso.")
else:
    print("Bocciato.")    

#es8
stringa2=str(input("Inserire una stringa: "))
if len(stringa2)<5:
    print("Corto.")
else:
    print("Lungo.")

#es9
stringa3=str(input("Inserire una stringa per verificare se la prima lettera e' una vocale o consonante:"))
vocali=("a","e","i","o","u","A","E","I","O","U")
if stringa3[0] in vocali:
    print("La prima lettera e' una vocale.")
else:
    print("La prima lettera e' una consonante.")

#es10

