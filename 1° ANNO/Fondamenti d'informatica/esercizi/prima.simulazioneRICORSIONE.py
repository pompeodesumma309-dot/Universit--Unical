def analizza_stringa(my_str):
    if '[' not in my_str:
        return my_str

    fine = my_str.find(']')
    inizio = my_str.rfind('[', 0, fine)

    numero = int(my_str[inizio - 1])

    testo = my_str[inizio + 1 : fine]
    
    nuova_stringa = my_str[:inizio - 1] + (testo * numero) + my_str[fine + 1:]

    return analizza_stringa(nuova_stringa)
