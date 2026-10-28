# Lezione 16°

**IL PROBLEMA DELLA RICERCA DI UN ELEMENTO IN UN INSIEME**

- Riceca lineare O(n) - nessun prerequisitp
- Ricerca binaria O(log n) - prerequisito: valori ordinati, accesso diretto

>### Ricerca per chiave e accesso diretto

Una collezione di coppie *<chiave, valore>* si cerca per chiave. Le chiavi sono *uniche*: a una chiave corrisponde al massimo un valore.

*Esempio:* un programma che, data la *matricola*, restituisce tutti i dati dello studente.

- Uso la matricola direttamente come *indice* dell’array: tabella[matricola].
- Serve una sola operazione di accesso, quindi la ricerca costa *O(1)*.
- Il requisito è l’*accesso diretto*, cioè una struttura dati costruita apposta per questo (un array indicizzato dalla chiave).

*Svantaggi*

- La chiave deve essere un *numero intero* (e non troppo grande).
- Lo *spazio* è proporzionale all’intervallo dei valori possibili, non al numero di studenti effettivi. Se le matricole vanno da 0 a 999999 ma gli studenti sono 5000, quasi tutto l’array resta vuoto.

### Studenti senza matricola: il codice fiscale

Il CF identifica lo studente ma non è numerico, quindi va convertito in un numero. L’idea è una *funzione di hash: trasformo ogni lettera nel suo codice **ASCII, lo moltiplico per la sua **posizione* e sommo i risultati. La posizione serve perché, con la sola somma, due CF con le stesse lettere in ordine diverso darebbero lo stesso valore.

Ci sono due strategie estreme.

*1. Conversione completa (combinare tutte le informazioni, ad esempio interpretando il CF come un numero in una certa base)*

- Vantaggio: valori praticamente tutti diversi, quindi *nessuna collisione*.
- Svantaggio: il numero ottenuto è enorme, quindi servirebbe una tabella di dimensioni *gigantesche*.

*2. ASCII pesato per posizione (versione semplice)*

- Vantaggio: i valori restano piccoli, quindi uso *meno spazio*.
- Svantaggio: *collisioni, cioè chiavi *diverse che producono lo stesso indice. Con questa funzione non è garantito che CF diversi diano numeri diversi.

### Il modulo per controllare lo spazio

Per ridurre lo spazio si calcola l’indice con il *modulo*:


indice = h(chiave) mod m


dove m è la dimensione della tabella. Così l’indice cade sempre in [0, m-1].

- Se m è piccolo, risparmio spazio ma aumentano le collisioni.
- Se m è grande, le collisioni diminuiscono ma spreco memoria.
- Scegliere m come numero *primo* di solito distribuisce meglio le chiavi.

Le collisioni che restano vanno *gestite, per esempio con liste concatenate (*chaining) oppure con indirizzamento aperto (open addressing). Questa è l’idea alla base delle *tabelle hash*, che è il compromesso tra l’accesso diretto puro (veloce ma spreca spazio) e la ricerca in generale: in media O(1), nel caso peggiore dipende dal numero di collisioni.

---

Due note sui tuoi appunti originali: dicevi “O(1)” per la ricerca, ma con le collisioni è O(1) solo *in media*, e “gigantesco spazio” riguarda la tabella, non la chiave. Se vuoi, posso aggiungere un esempio in C++ con la funzione di hash sul CF.



# Tabelle Hash e `std::unordered_map` (C++ STL)

## 1. Concetti Fondamentali
Le **tabelle hash** sono strutture dati utilizzate per implementare i **container associativi**. In questi contenitori, l'accesso agli elementi avviene tramite una coppia:
$$\langle \text{chiave}, \text{valore} \rangle$$
A ogni valore memorizzato viene associata in modo univoco una specifica chiave.

---

## 2. La Funzione Hash
Una **funzione hash** ($f_h$) mappa gli elementi del dominio delle chiavi in numeri interi non negativi, che fungono da indici per accedere alla tabella sottostante:

$$f_h: \text{Dominio}(\text{chiave}) \to \mathbb{N}$$

### Tipologie di Funzioni Hash
Date due chiavi distinte $k_1 \neq k_2$:
* **Funzione Hash Perfetta:** Produce sempre indici distinti, ovvero:
  $$f_h(k_1) \neq f_h(k_2)$$
  Non si verificano mai collisioni e la ricerca/inserimento avvengono in tempo costante garantito $\mathcal{O}(1)$.
* **Funzione Hash Non Perfetta:** Due chiavi distinte possono produrre lo stesso valore/indice:
  $$f_h(k_1) = f_h(k_2) \implies \text{Collisione}$$
  È necessario implementare una strategia di risoluzione delle collisioni.

---

## 3. Gestione delle Collisioni: Chaining (Liste di Collisione)
Quando la funzione hash non è perfetta, la tabella viene strutturata associando a ogni cella una lista collegata:

* **Lista di collisione:** Ciascun bucket/indice $i$ contiene una lista di tutti gli elementi la cui chiave produce l'indice $i$.
* **Lunghezza della lista:**
  * **Minima:** $0$ (il bucket è vuoto).
  * **Massima:** $n$ (nel caso pessimo in cui tutti gli $n$ elementi inseriti collidano sullo stesso identico bucket).

---

## 4. Riduzione dello Spazio (Parametrizzazione con Modulo)
Poiché l'output della funzione hash $f_h$ può essere arbitrariamente grande, lo spazio dei valori viene ridotto alle dimensioni fisiche della tabella $k$ tramite l'operatore modulo:

$$f'_h(x) = f_h(x) \pmod k$$

$$f'_h : \text{Dominio}(\text{chiave}) \to \{0, 1, \dots, k - 1\}$$

Dove:
* $k$ è la dimensione della tabella hash (numero di bucket).

---

## 5. Fattori che Influenzano le Collisioni
La probabilità di avere collisioni dipende principalmente da due fattori:
1. **La bontà della funzione hash:** Una buona funzione distribuisce uniformemente le chiavi sull'intero intervallo $[0, k - 1]$.
2. **La dimensione della tabella ($k$):** Valori di $k$ più grandi riducono la probabilità di collisione, ma aumentano l'occupazione di memoria (bilanciamento spazio/tempo).


**FUNZIONI HASH STANDARD**
- metodo del quadratpo centrale
- metodo dell'avvolgimento


>COSTO MEDIO DELLA RICERCA NELLA TABELLA HASH

fc = n / n_celle (n = n.elementi effettivamente caricati)

# Tabelle Hash: Fattore di Carico e Complessità Computazionale

---

## 1. Il Fattore di Carico ($\alpha$ o $fc$)

Il **fattore di carico** (load factor) misura il grado di riempimento della tabella hash ed è definito come il rapporto tra il numero di elementi inseriti e la dimensione complessiva della tabella:

$$fc = \frac{n}{m}$$

Dove:
* $n$ = numero totale di elementi (chiavi) effettivamente memorizzati.
* $m$ ($n_{\text{celle}}$ o bucket) = numero totale di celle/posizioni disponibili nella tabella.

Rappresenta la **lunghezza media di una lista di collisione** nell'ipotesi di *hashing uniforme semplice*.

---

## 2. Costo Medio della Ricerca con Chaining

All'aumentare di $fc$, aumenta la lunghezza media delle liste di trabocco e, di conseguenza, il numero medio di accessi (confronti) necessari per trovare una chiave o accertarne l'assenza:

| Fattore di Carico ($fc$) | Numero Medio di Accessi (Ricerca con successo) |
| :---: | :---: |
| **0.5** | $\approx 1.25$ |
| **0.7** | $\approx 1.35$ |
| **1.0** | $\approx 1.50$ |
| **2.0** | $\approx 2.00$ |

> **Nota Teorica:**  
> In una tabella con risoluzione per concatenamento (*chaining*):
> * **Ricerca con insuccesso:** richiede in media $\Theta(1 + fc)$ accessi.
> * **Ricerca con successo:** richiede in media $1 + \frac{fc}{2}$ accessi (assumendo distribuzioni uniformi e inserimento in testa).

---

## 3. Analisi della Complessità Operazioni

### 1) Organizzazione / Inserimento Iniziale di $n$ Elementi
Dati $n$ elementi in input (es. da tastiera o da file):

```cpp
// Inserimento del singolo elemento in testa alla lista di collisione
T[f_h(key)].push_front({key, val});
```

>Esempio di template

```cpp
template <class keyType, class valType>
class TabellaHash{
    vector<list<pair<keyType, valType>>> T;

public:
    costruttori...
    bool insert(keyType, valType);
    valType find(keyType); // e se non esiste?  

}


```

### Esempio: rifare la "compatta" array con le tabelle hash

```cpp
template <class T>
vector<T> compatta(const vector<T>& v){

    unordered_map<T, bool> seen;
    vector<T> result;

    for(int i = 0; i<v.size(); ++i){

        if (!seen(v[i])) {
            result.push_back(v[i]);
            seen[v[i]] = true;
        }
    }
    return result;
}
```

PER CASE -> RENDERE PIU ROBUSTO QUESTO PROGRAMMA, RISCRIVENDOLO CON LE TABELLE HASH