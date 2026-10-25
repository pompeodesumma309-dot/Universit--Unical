lista_numeri = [1, 18, 22, 44, 33, 22, 44, 55, 44]
print(lista_numeri)

if 44 in lista_numeri:
    lista_numeri.remove(44)
    print(lista_numeri)

lista_numeri.extend([10, 20, 30])
print(lista_numeri)

lista_numeri.extend("ciao")
print(lista_numeri)


