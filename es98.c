/*
  Una stringa "seq" si dice SOTTOSEQUENZA di una stringa "testo" 
  se i caratteri di "seq" compaiono in "testo" nello stesso ordine, 
  anche se non necessariamente consecutivi.

  Ad esempio:
  - "cne" è una sottosequenza di "cane" (c, poi n, poi e).
  - "prma" è una sottosequenza di "programmazione".
  - "roma" NON è una sottosequenza di "programmazione" (la 'o' 
    viene prima della 'r' in "roma", ma non in "programmazione").
  - "abc" NON è una sottosequenza di "ab" (il testo è troppo corto).

  Si implementi il sottoprogramma RICORSIVO:
  int is_sottosequenza(char *testo, char *seq)
  
  La funzione deve restituire 1 se "seq" è una sottosequenza di "testo",
  e 0 altrimenti.

  Non è consentito usare cicli (for, while, do-while) all'interno 
  della funzione, né funzioni della libreria <string.h>.
*/

#include <stdio.h>

// Prototipo
int is_sottosequenza(char *testo, char *seq);

int main() {
    char testo1[] = "programmazione";
    char seq1[] = "prma";
    
    char testo2[] = "esame";
    char seq2[] = "sme";
    
    char testo3[] = "cane";
    char seq3[] = "cna"; // Ordine sbagliato, deve dare 0

    printf("'%s' in '%s'? %d (Atteso: 1)\n", seq1, testo1, is_sottosequenza(testo1, seq1));
    printf("'%s' in '%s'? %d (Atteso: 1)\n", seq2, testo2, is_sottosequenza(testo2, seq2));
    printf("'%s' in '%s'? %d (Atteso: 0)\n", seq3, testo3, is_sottosequenza(testo3, seq3));

    return 0;
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

int is_sottosequenza(char *testo, char *seq) {
    if(testo[0] == '\0'){
        return 0;
    }

    if(seq[0] == '\0'){
        return 1;
    }
    
    if(seq[0] == testo[0]){
        return is_sottosequenza(testo + 1, seq + 1);
    }

    return is_sottosequenza(testo + 1, seq);
}