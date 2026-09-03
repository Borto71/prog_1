#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// la dimensione massima del nome di un produttore di veicoli
#define MAX_PRODUTTORE 100

// la dimensione massima della targa di un veicolo
#define MAX_TARGA 20

// un veicolo registrato alla motorizzazione
typedef struct {
  // il produttore del veicolo, per esempio "Renault", "Fiat" etc
  char *produttore;

  // la targa, per esempio "DW367BX"
  char *targa;

  // l'identificativo della provincia, come in https://it.wikipedia.org/wiki/Province_d%27Italia
  // per esempio VR per Verona; si usi RM per Roma
  char provincia[2];
}
Veicolo;

// una lista di veicoli
typedef struct list {
  Veicolo veicolo;
  struct list *tail;
}
List;

// scrive nel file indicato il veicolo indicato, nella forma:
// Fiat HA345007YH VR
// va a capo alla fine
void write_veicolo(FILE *f, Veicolo *veicolo) {
    fprintf(f, "%s %s %s", veicolo->produttore, veicolo->targa, veicolo->provincia);
}

// scrive nel file indicato la lista di veicoli indicati, nell'ordine della lista,
// andando a capo dopo ciascun veicolo, chiamando ripetutamente write_veicolo()
void write_list(FILE *f, List *l) {
    if(l == NULL){
        return;
    }

    write_veicolo(f, &(l->veicolo));
    write_list(f, l->tail);
}

// come write_list(), ma scrive sullo standard output (normalmente quindi sullo schermo)
void print_list(List *l) {
    if(l == NULL){
        return;
    }

    printf("%s %s %s\n", l->veicolo.produttore, l->veicolo.targa, l->veicolo.provincia);
    print_list(l->tail);
}

// Legge dal file indicato, nel formato:
// produttore targa provincia
// e usa tali dati per inizializzare il veicolo indicato.
// Il produttore ha lunghezza massima di 100 caratteri;
// la targa ha una lunghezza massima di 20 caratteri;
// la provincia è fatta da esattamente due caratteri.
// Le dimensioni massime non vanno controllate: si dà per scontato che nel file siano corrette.
// Questa funzione ritorna 0 se non è riuscita a leggere il veicolo (per esempio: file terminato),
// altrimenti ritorna un qualsiasi numero diverso da 0
int read_veicolo(FILE *f, Veicolo *veicolo) {
    char t_produttore[MAX_PRODUTTORE];
    char t_targa[MAX_TARGA];
    char t_provincia[3];

    if(fscanf(f, "%s %s %s", t_produttore, t_targa, t_provincia) == 3){
        veicolo->produttore = malloc(strlen(t_produttore) + 1);
        strcpy(veicolo->produttore, t_produttore);

        veicolo->targa = malloc(strlen(t_targa) + 1);
        strcpy(veicolo->targa, t_targa);

        veicolo->provincia[0] = t_provincia[0];
        veicolo->provincia[1] = t_provincia[1];
        return 1;
    }
    return 0;
}

// legge dal file indicato una lista di veicoli, fino alla fine del file,
// chiamando ripetutamente read_veicolo()
List *read_list(FILE *f) {
    Veicolo temp;

    if(read_veicolo(f, &temp) == 0){
        return NULL;
    }

    List *nuovo = malloc(sizeof(List));
    nuovo->veicolo = temp;
    nuovo->tail = read_list(f);

    return nuovo;
}

// dealloca la memoria allocata per la lista indicata:
// deve deallocare i nodi della lista ma anche tutto ciò che avete
// allocato eventualmente per ciascun veicolo;
// questa funzione deve essere ricorsiva
void free_list(List *l) {
  if(l == NULL){
    return;
  }

  free_list(l->tail);

  free(l->veicolo.produttore);
  free(l->veicolo.targa);

  free(l);
}

int main(void) {
  // chiediamo all'utente il nome del file contenente la lista
  char filename[101];
  scanf("%100s", filename);

  // leggiamo la lista contenuta dentro filename e la stampiamo sul video
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Non riesco ad aprire il file %s\n", filename);
    return -1;
  }
  List *l = read_list(f);
  fclose(f);
  printf("Dentro %s ho trovato:\n", filename);
  print_list(l);

  // scriviamo la lista dentro copy.txt
  FILE *g = fopen("copy.txt", "w");
  if (g == NULL) {
    printf("Non riesco ad aprire il file copy.txt\n");
    return -1;
  }
  write_list(g, l);
  fclose(g);
  free_list(l); // l non ci serve più
  printf("Ho copiato tale lista in copy.txt\n");

  // rileggiamo la lista contenuta dentro copy.txt e la stampiamo sul video
  FILE *h = fopen("copy.txt", "r");
  if (h == NULL) {
    printf("Non riesco ad aprire il file copy.txt\n");
    return -1;
  }
  l = read_list(h);
  fclose(h);
  printf("Dentro copy.txt ho trovato:\n");
  print_list(l);
  free_list(l); // l non ci serve più

  return 0;
}