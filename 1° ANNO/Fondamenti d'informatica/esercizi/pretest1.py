def ordina(lst):
    lista_dispari = []
    lista_finale = []
    k = 0
    for i in range(len(lst)):
      if lst[i]%2==1:
            lista_dispari.append(lst[i])
          
    for ciclo in range(len(lista_dispari)):
        for j in range(len(lista_dispari)- 1):
            if lista_dispari[j]> lista_dispari[j + 1]:
                temp = lista_dispari[j]
                lista_dispari[j] = lista_dispari[j + 1]
                lista_dispari[j + 1] = temp
                
    for z in range(len(lst)):
        if lst[z] % 2 == 0:
            lista_finale.append(lst[z])
        else:
            lista_finale.append(lista_dispari[k])
            k += 1
    return lista_finale

############################################################
def filtra(lst):
    new_lista=[]
    for i in range(1,len(lst)-1):
        if num_primi(lst[i]):
            if lst[i-1]%2==0 and lst[i+1]%2==1:
             new_lista.append(lst[i])
    return  new_lista    
    
def num_primi(num):
    if num<=1:
        return False
    for i in range(2,num):
        if num%i==0 :
            return False
    return True 
