# TECNICHE DI PROGRAMMAZIONE
**1. TECNICA DIVIDE ET IMPERA**  
**2. BRUTE FORCE**   
**3. TECNICA GOLOSA** -> Adatta ai problemi di ottimizzazione 

**Scenario tipico (della tecnica golosa):** n oggetti (o variabili) disponibili in quantità limitata, ciascun oggetto (combinazione di oggetti) può essere asscoiato ad un certo e ad un valore.

Vogliamo massimizzare un cerca funzione f, che vuole essere descritta in questo modo:

ciascun oggetto (combinazione di oggetti) può essere associato ad un costo e ad un valore

**Problema di Massimizzazione:**
$$ \max F = \sum_{i=1}^{m} x_i \times V_i(x_1 \dots x_m) $$

$$ \text{vincoli} \begin{cases} 
C(x_1 \dots x_m) \le C_{max} \\ 
0 < x_i \le q_i \quad i = 1 \dots m 
\end{cases} $$

---

**Problema di Minimizzazione:**
$$ \min F = \sum_{i=1}^{m} x_i \cdot C(x_1 \dots x_m) $$

$$ \begin{cases} 
V(x_1 \dots x_m) \ge V_{min} \\ 
0 \le x_i \le q_i 
\end{cases} $$


### TROVARE UN ORDINAMENTO DEGLI OGGETTI DA VALUTARE:
ordinare per valore specifico decrescente (vi/ci) - valore/costo = valore specifico 

Schema tipico algoritmo goloso:  

Per ogni stadio della scelta golosa:
- scelta golosa
- aggiungi la scelta alla soluzione 

Complessità tipica:
- O(n log n) per ordinamento 
- O(n) per la soluzione 

### Problema di ottimalità della tecnica golosa
Garanzia di avere l'ottimo condizionata al problema ed alla soluzione.  
IN GENERALE LA TECNICA GOLOSO è UNA TECNICA EURISTICA: non da garanzie di risolvere il problema in modo esatto.



ESEMPIO 1: problema del cambio dell'assegno, cambiare il valore usando il minor numero di banconote/monete.  
valore = valore banconota  
costo = 1

**scelta golosa**  
dato:   
- residuo (valoreAssegnato - cambiato)
- valore della moneta dello stadio attuale -> residuo/valore

```cpp
struct TCambio{
    vector<int> nMonete;
    float valore;

    TCambio (int n) : nMonete (n,0) ,valore(0){}
};

TCambio cambio(const vector<float>& tagli, flloat valoreAssegno){
    int n = tagli.size();
    TCambio sol(n);
    for(int i=0; i<n && sol.valore < valoreAssegno; ++i){
        sol.nMonete[i] = (valoreAssegno - sol.valore) / tagli[i];
        sol.valore += sol.nMonete[i] * tagli[i];
    }

    if(sol.valore < valoreAssegno){
        sol.nMonete[n-1]++;
        sol.valore += tagli[n-1];
    }
    
}


```

