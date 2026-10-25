def explore(filesystem, current):
    trovato=False
    somma_totale=0
    for file, dimensione in filesystem:
        if file==current and isinstance(dimensione, int):
            trovato=True
            if current.endswith(".pdf"):
                return dimensione
            else:
                return 0
        elif file==current and isinstance(dimensione, str):
            trovato=True 
            ricorsiva=explore(filesystem, dimensione)
            
            if isinstance(ricorsiva, int):
                somma_totale+=ricorsiva
    if trovato==False:
        return []
        
    return somma_totale

###############################################################
def calcola_budget(nodo):
    somma=0
    for dipartimento in nodo:
        contenuto = nodo[dipartimento]
        if "X_" in dipartimento:
            continue
        
        if isinstance(contenuto, list):
            for impiegato in contenuto:
                stipendio=impiegato[1]
                ruolo=impiegato[2]

                if ruolo=="Manager":
                    stipendio_nuovo= stipendio *1.1
                    somma+=stipendio_nuovo
                elif ruolo=="Stagista":
                    if dipartimento == "Formazione":
                        somma+=stipendio
                    else:
                        somma+=0
                else:
                    somma+=stipendio 
        elif isinstance(contenuto, dict):
            somma+=calcola_budget(contenuto)
    return somma     
########################################################################à
def posso_uscire(labirinto, stanza, metri, passi):
    if stanza=="EXIT":
        return True
    
    stanze_raggiungibili=[]
    for (stanza_a, stanza_b, distanza) in labirinto:
        if stanza_a == stanza and distanza<=metri:
            stanze_raggiungibili.append(stanza_b, distanza)
        if stanza_b == stanza and distanza<= metri:
            stanze_raggiungibili.append(stanza_a, distanza)
    
    if passi==0 or stanze_raggiungibili==[]:
        return False 
    
    for stanza_raggiungibile, distanza in stanze_raggiungibili:
        if posso_uscire(labirinto, stanza_raggiungibile, metri-distanza, passi-1):
            return True 
            
    return False
#######################################àà
def genera_triple(lst, n=3):
    # Caso base: quando n è 0, restituisco la sequenza vuota
    if n == 0:
        return [()]

    risultato = []

    # Per ogni elemento della lista
    for x in lst:
        # Genero tutte le sequenze di lunghezza n-1
        sottoseq = genera_triple(lst, n - 1)
        # Prepend x a ciascuna sottosequenza
        for seq in sottoseq:
            risultato.append((x,) + seq)

    return risultato
###################################################


