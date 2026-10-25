num=int(input("Inserisci un numero intero:"))
num_segreto=45
while num!=num_segreto:
    if num<num_segreto:
     print("il numero inserito è minore del numero segreto,riprova:")
     num=int(input("Inserisci un numero intero:"))

    else:
        print("il numero inserito è maggiore del numero segreto,riprova:")
        num=int(input("Inserisci un numero intero:"))
print("Complimenti hai indovinato il numero segreto!")
