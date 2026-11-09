# Contenitori Non Sequenziali: Gli Alberi

Gli **alberi** sono strutture dati gerarchiche non lineari.

## 1. Terminologia e Componenti Fondamentali

* **Nodo:** Componente fondamentale della struttura dati. Contiene:
  * Una **componente informativa** (il dato o *payload*).
  * **Riferimenti (puntatori)** ad altri nodi per descrivere la struttura dell'albero (es. puntatori ai figli e opzionalmente al padre).
* **Radice (*Root*):** L'unico nodo dell'albero che **non ha un padre**. Si trova al livello $0$.
* **Relazioni Padre-Figli:**
  * Ogni nodo (esclusa la radice) ha **esattamente un nodo padre**.
  * Ogni nodo può avere **zero, uno o più nodi figli**.
* **Foglie (*Leaves*):** Nodi che non hanno figli (grado di uscita $0$).
* **Nodi Interni:** Nodi che hanno almeno un figlio (tutti i nodi tranne le foglie).
* **Fratelli (*Siblings*):** Nodi che condividono lo stesso nodo padre.
* **Sottoalbero (*Subtree*):** Ogni nodo di un albero è a sua volta radice di un sottoalbero, formato dal nodo stesso e da tutti i suoi discendenti.

---

## 2. Livello, Profondità e Altezza

* **Livello di un nodo:** Definito ricorsivamente come la distanza (numero di archi) dalla radice:
  * $\text{Livello}(\text{radice}) = 0$
  * $\text{Livello}(\text{nodo}) = \text{Livello}(\text{padre}) + 1$
* **Altezza / Profondità dell'albero ($p$):** È data dal **livello massimo** raggiunto dalle sue foglie (es. se il livello massimo dei nodi è $4$, la profondità complessiva dell'albero è $4$).

---

## 3. Tipi di Alberi (Classificazione per Arità $d$)

L'**arità** (o grado d'uscita, $d$) indica il numero massimo di figli che un singolo nodo può avere:

* **Alberi binari ($d = 2$):** Ogni nodo ha al massimo $2$ figli (distinti in *figlio sinistro* e *figlio destro*).
* **Alberi $d$-ari (o $k$-ari):** Ogni nodo ha al massimo $d$ figli.
* **Alberi generici (o $n$-ari):** Nessun limite prefissato al numero di figli per nodo.

---

## 4. Relazione tra Numero di Nodi ($n$) e Profondità ($p$) negli Alberi Binari

> **Nota sulle convenzioni:** Le formule esatte variano leggermente a seconda che la radice sia contata a livello $0$ (standard informatico: profondità = numero di archi) oppure a livello $1$ (profondità = numero di livelli di nodi).

### A. Fissato il numero di nodi $n$, qual è la profondità $p$?
* **Profondità massima (Albero degenere / lista):** Si verifica quando ogni nodo interno (eccetto l'unica foglia) ha **esattamente un solo figlio**.
  * Valore esatto: $p = n - 1$ (oppure $p = n$ contando i livelli da $1$) $\implies O(n)$
* **Profondità minima (Albero completo):** Si verifica quando tutti i livelli sono completamente riempiti.
  * Valore esatto: $p = \lfloor \log_2 n \rfloor \implies O(\log n)$

### B. Fissata la profondità $p$, quanti nodi $n$ può avere l'albero?
* **Numero minimo di nodi:**
  * $n_{\min} = p + 1$ (se la radice è a livello $0$) oppure $n_{\min} = p$ (se la radice è a livello $1$).
* **Numero massimo di nodi:**
  * $n_{\max} = 2^{p+1} - 1$ (se la radice è a livello $0$) oppure $n_{\max} = 2^p - 1$ (se la radice è a livello $1$).
  * Asintoticamente: $O(2^p)$.

---

## 5. Alberi Bilanciati

Un albero binario si dice **bilanciato in altezza** (proprietà di **AVL**) se, **per ogni nodo**, l'altezza del sottoalbero sinistro e l'altezza del sottoalbero destro differiscono al massimo di $1$:

$$|\text{altezza}(\text{sinistro}) - \text{altezza}(\text{destro})| \le 1$$

* **Proprietà fondamentale:** In un albero bilanciato con $n$ nodi, la profondità $p$ è garantita essere logaritmica:
  $$p = O(\log n)$$


# Rappresentazione in Memoria degli Alberi

Qualsiasi tipo di albero può essere rappresentato in memoria attraverso due approcci principali:

1. **Rappresentazioni Indicizzate (basate su Array / Vettori):**
   I nodi sono memorizzati all'interno di celle di un array e le relazioni gerarchiche sono espresse tramite gli indici. Si dividono in:
   * **Vettore dei padri**
   * **Vettore posizionale**[cite: 1]
2. **Rappresentazioni Collegate (basate su Puntatori):**[cite: 2]
   I nodi sono allocati dinamicamente in memoria e collegati tra loro tramite puntatori espliciti (es. puntatori ai figli e/o al padre)[cite: 2].

---

## 1. Rappresentazioni Indicizzate

Per entrambi i metodi indicizzati, prendiamo come riferimento il seguente **albero binario di esempio**[cite: 1]:
* **Radice:** `A`[cite: 1]
* **Figli di `A`:** `B` (sinistro), `C` (destro)[cite: 1]
* **Figli di `B`:** `D` (sinistro), *nessun figlio destro*[cite: 1]
* **Figli di `C`:** *nessun figlio sinistro*, `E` (destro)[cite: 1]

```text
      A
     / \
    B   C
   /     \
  D       E
```

### A. Vettore dei Padri

Si utilizza un array di dimensione $n$ in cui **ogni cella contiene una coppia di informazioni**: `(info, padre)`, ovvero il contenuto informativo del nodo e l'indice dell'array in cui si trova il suo nodo padre[cite: 1]. I nodi possono trovarsi in qualsiasi posizione dell'array[cite: 1].

* Per convenzione, il campo `padre` della **radice** vale **`-1`** (o `null`), poiché non ha padre[cite: 1].

#### Esempio

| Indice ($v$) | $\dots$ | $3$ | $4$ | $\dots$ | $7$ | $\dots$ | $9$ | $10$ |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Nodo (`info`)** | $\dots$ | `B` | `E` | $\dots$ | `A` | $\dots$ | `C` | `D` |
| **Indice del `padre`** | $\dots$ | `7` | `9` | $\dots$ | `-1` | $\dots$ | `7` | `3` |

* **`A` (indice 7):** ha padre `-1` $\implies$ è la radice[cite: 1].
* **`B` (indice 3) e `C` (indice 9):** hanno come padre `7` $\implies$ sono figli di `A`[cite: 1].
* **`D` (indice 10):** ha come padre `3` $\implies$ è figlio di `B`[cite: 1].
* **`E` (indice 4):** ha come padre `9` $\implies$ è figlio di `C`[cite: 1].

#### Complessità delle operazioni
* **Accesso a un nodo (noto l'indice):** $O(1)$ (accesso diretto all'array)[cite: 1].
* **Accesso al padre di un nodo:** $O(1)$ (lettura diretta del campo `padre` nella cella del nodo)[cite: 1].
* **Accesso a un figlio di un nodo:** $O(n)$ (nel caso pessimo bisogna scorrere l'intero vettore per trovare le celle che hanno l'indice del nodo corrente come `padre`)[cite: 1].

---

### B. Vettore Posizionale

I nodi vengono memorizzati nell'array $A$ **livello per livello** (da sinistra a destra)[cite: 1]. La posizione di ogni nodo è fissata da una **regola matematica**, che permette di calcolare direttamente gli indici dei figli e del padre senza salvare puntatori o indici aggiuntivi[cite: 1].

* **Vincolo strutturale:** Se a un nodo manca un figlio, la cella corrispondente nel vettore **deve comunque rimanere allocata ma vuota** (indicata con `?`) per mantenere valida la formula matematica per i nodi successivi[cite: 1].

#### Esempio sull'albero binario ($d = 2$, radice in indice $1$, cella $0$ non usata)

| Indice ($v$) | $0$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Contenuto** | *(non usato)* | `A` | `B` | `C` | `D` | `?` | `?` | `E` |

* **Calcolo delle posizioni dei figli ($d \cdot v + i$):**[cite: 1]
  * Figli di `A` ($v=1$): sinistro ($i=0$) in $1 \cdot 2 + 0 = 2$ (`B`); destro ($i=1$) in $1 \cdot 2 + 1 = 3$ (`C`)[cite: 1].
  * Figli di `B` ($v=2$): sinistro ($i=0$) in $2 \cdot 2 + 0 = 4$ (`D`); destro ($i=1$) in $2 \cdot 2 + 1 = 5$ (`?` - vuoto)[cite: 1].
  * Figli di `C` ($v=3$): sinistro ($i=0$) in $3 \cdot 2 + 0 = 6$ (`?` - vuoto); destro ($i=1$) in $3 \cdot 2 + 1 = 7$ (`E`)[cite: 1].

#### Regola Matematica Generale (Alberi $d$-ari)
Dato un nodo all'indice $v$ in un albero di arità $d$, indicando con $i \in \{0, 1, 2, \dots, d-1\}$ i suoi figli ($i=0$ primo figlio, $i=1$ secondo figlio, ecc.)[cite: 1, 2]:

* **Posizione dell'$i$-esimo figlio di $v$:**
  $$\text{figlio}_i(v) = A[d \cdot v + i]$$
[cite: 1, 2]
* **Posizione del padre di $v$:**
  $$\text{padre}(v) = A\left[\text{int}\left(\frac{v}{d}\right)\right] = A\left[\left\lfloor \frac{v}{d} \right\rfloor\right]$$
[cite: 1, 2]

#### Complessità e Occupazione di Memoria
* **Accesso a un nodo:** $O(1)$[cite: 1]
* **Accesso al padre:** $O(1)$ (calcolo matematico diretto: $\lfloor v/d \rfloor$)[cite: 1]
* **Accesso a un figlio:** $O(1)$ (calcolo matematico diretto: $d \cdot v + i$)[cite: 1]
* **Dimensione del vettore (per un albero binario di profondità $p$):**
  $$n_{\text{celle}} = O(2^p)$$
[cite: 1]
  * **Pro e Contro:** Ottimo per alberi completi o quasi completi (nessuna cella sprecata), ma pessimo per alberi sbilanciati o degeneri (forte spreco di memoria perché se la profondità $p$ è alta il vettore ha comunque dimensione $O(2^p)$ piena di celle vuote `?`).

---

## 2. Rappresentazioni Collegate (basate su Puntatori)

Nelle rappresentazioni collegate i nodi sono allocati dinamicamente in memoria e connessi tramite riferimenti espliciti (puntatori)[cite: 2].

### Con Puntatori ai Figli

Ogni nodo mantiene al suo interno il valore informativo (`info`), un puntatore opzionale al nodo `padre` (utile per risalire l'albero in $O(1)$) e i puntatori diretti ai propri figli[cite: 2]. La struttura del nodo varia in base al tipo di albero[cite: 2]:

#### A. Albero Binario ($d = 2$)
Ogni nodo ha una struttura a dimensione fissa contenente[cite: 2]:
* **`info`**: il dato conservato nel nodo[cite: 2].
* **`left` (figlio sinistro)** e **`right` (figlio destro)**: due puntatori ai rispettivi sottoalberi (se un figlio non esiste, il puntatore vale `NULL` / $\perp$)[cite: 2].
* **`parent` (padre)** *(opzionale)*: puntatore al nodo genitore[cite: 2].

```text
       +-------------------+
       |       info        |
       +---------+---------+
       |  left   |  right  |
       +----+----+----+----+
            |         |
            v         v
```

#### B. Albero $d$-ario (con arità massima $d$ fissata)
Poiché ogni nodo può avere al massimo $d$ figli, il nodo contiene[cite: 2]:
* **`info`**: il dato del nodo[cite: 2].
* **Un vettore statico di $d$ puntatori** (`figli[0 ... d-1]`): $d$ celle contigue, ognuna contenente il puntatore a uno specifico figlio[cite: 2].
* **Pro e Contro:** L'accesso all'$i$-esimo figlio è immediato ($O(1)$), ma se molti nodi hanno meno di $d$ figli si spreca memoria per via dei puntatori lasciati a `NULL`.

```text
       +-----------------------------------+
       |               info                |
       +-----+-----+-----+-----+-----+-----+
       | f_1 | f_2 | ... | ... | ... | f_d |
       +--+--+-----+-----+-----+--+--+-----+
          |                       |
          v                       v
```

#### C. Albero Generico (nessun limite al numero di figli)
Poiché il numero massimo di figli non è noto a priori, non è possibile usare un array di dimensione fissa nel nodo[cite: 2].
* Ogni nodo contiene il campo **`info`** e un **unico puntatore alla testa di una lista concatenata** (*lista di puntatori ai figli*)[cite: 2].
* Ogni elemento di questa lista ausiliaria contiene[cite: 2]:
  1. Il puntatore al nodo figlio effettivo[cite: 2].
  2. Il puntatore al prossimo elemento della lista (il fratello successivo)[cite: 2].
* **Pro e Contro:** Nessuno spreco di memoria (si allocano solo i nodi della lista per i figli realmente esistenti), ma per accedere all'$i$-esimo figlio bisogna scorrere la lista concatenata in tempo lineare rispetto al numero di figli del nodo.

```text
       +--------------+
       |     info     |
       +------+-------+
              | (puntatore alla lista dei figli)
              v
            +---+---+    +---+---+    +---+---+
            | * | --+--->| * | --+--->| * | / |
            +---+---+    +---+---+    +---+---+
              |            |            |
              v            |            v
           (Figlio 1)      v         (Figlio 3)
                        (Figlio 2)
```



## RAPPRESENTAZIONE PRIMO FIGLIO - FRATELLO


fare

enum Direzione {SIN = 0, DES = 0};

enum -> mi permette di definire un tipo enumerativo, un associazione di valore interi a delle parole, a dei simboli. Associa a ogni simboli un indice.

```cpp
template<class T>
class AlberoB{

template<class U>
struct SNodo{
    U vinfo;
    SNodo * padre; 
    SNodo * pfiglio[2];

    SNodo() : {padre=nullptr; pfiglio[SIN]=nullptr; pfiglio[DES]=nulptr;} // costruttore di defult

    SNodo(const U& inf) : vinfo(inf) {padre = pfiglio[SIN] = pfiglio[DES]=0;}

    ~SNodo(){delete pfiglio[SIN];delete pfiglio[DES];}
    

}

protected: 
    SNodo<T> * pradice;

public:
    

}

```