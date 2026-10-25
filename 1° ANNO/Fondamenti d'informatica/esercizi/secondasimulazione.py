def duplicato(lst):
    cont=0
    max_cont=0
    num=lst[0]
    
    if not lst:
        return None
        
    for i in range(len(lst)):
        for j in range(i+1,len(lst)):
            if lst[i]==lst[j]:
                cont+=1
                num=lst[j]
            
            if cont>max_cont:
                max_cont=cont
                num=lst[j]
    return num
    
###########################################################à
def ordina_prenotazioni(lst):
    new_lista=[]
    for (id_prenotazione, id_utente, titolo_libro, priorita) in lst:
        if priorita > 2:
            new_lista.append((id_prenotazione, id_utente, titolo_libro, priorita))
    
    for cont in range(len(new_lista)):
        for j in range(len(new_lista)-1):
            a=new_lista[j]
            b=new_lista[j+1]
            
            if (a[1]>b[1]) or \
                (a[1]==b[1] and a[3]<b[3]) or \
                (a[1]==b[1] and a[3]==b[3] and a[2]>b[2]) or \
                (a[1]==b[1] and a[3]==b[3] and a[2]==b[2] and a[0]>b[0]):
                
                tmp=new_lista[j]
                new_lista[j]=new_lista[j+1]
                new_lista[j+1]=tmp
                
    return new_lista
########################################################################
def files(filesystem, c, string):

    presente = False
    for (cont1, cont2) in filesystem:
        if cont1 == c:
            presente = True
            break

    if not presente:
        return []

    risultato = []

    for (cont1, cont2) in filesystem:
        if cont1 == c:

            is_cartella = False
            for (x, y) in filesystem:
                if x == cont2:
                    is_cartella = True
                    break

            if not is_cartella:
                if string in cont2:
                    risultato.append(cont2)

            else:
                risultato.extend(files(filesystem, cont2, string))

    return risultato
############################################
def latina(matrice):
    n = len(matrice)
    
    for r in range(n):
        if len(matrice[r])!=n:
            return False
            
    for r in range(n):
        riga=matrice[r]
        for x in riga:
            if x<1 and x>n:
                return False
                
        for i in range(n):
            for j in range(i+1,n):
                if riga[i]==riga[j]:
                    return False
                    
        for k in range(1,n+1):
            trovato=False
            for x in riga:
                if x==k:
                    trovato=True
                    break
            if not trovato:
                return False
    return True