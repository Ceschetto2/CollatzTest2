🧮 Collatz Conjecture Checker

Questo progetto in C permette di testare numeri interi secondo la congettura di Collatz.
🚀 Funzionalità

    Supporta numeri interi di qualsiasi dimensione, grazie all'uso di librerie C specifiche.

    Salva automaticamente su file l'ultimo numero elaborato, permettendo di riprendere l'esecuzione in un secondo momento.

    Si arresta in caso di rilevamento di un loop anomalo, ossia un numero che riporta a sé stesso nel ciclo di Collatz, confutando (teoricamente) la congettura.

🛠️ Tecnologie utilizzate

    Linguaggio: C

    Librerie: (specifica qui, es. GMP se usata)

    Salvataggio dati: file system locale

📄 Note

Per loop, si intende un'eventuale sequenza che, seguendo le regole della congettura di Collatz, ritorna al numero iniziale senza giungere a 1. Questo comporterebbe una violazione della congettura stessa, rendendola falsa.
📌 Esempio

collatz(27) ➝ 82 ➝ 41 ➝ ... ➝ 1

📁 Salvataggio

Il programma crea un file con il numero corrente raggiunto, utile in caso di interruzioni o per monitorare l'avanzamento su numeri molto grandi.  

🧪 Stato ✅ Funzionale  
🛠️ In fase di miglioramento per ottimizzare le performance su numeri molto grandi. 
