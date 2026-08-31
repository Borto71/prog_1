#include<stdio.h>
#include<string.h>
#define FNAME "testo.txt"
#define MAXS 15
#define SOGLIA 3

int conta_vocali(char *);

int main(){
  int i;
  FILE *fp;
  char p[MAXS+1];

  fp=fopen(FNAME,"r");

  if(fp == NULL){
    return -1;
  }

  while (fscanf(fp, "%s", p) == 1)
  {
    int vocali = conta_vocali(p);

    if(vocali >= SOGLIA){
        int massimo = strlen(p) - 1;
        for(i = massimo; i >= 0; i--){
            printf("%c", p[i]);
        }
        printf(" ");
    }
  }

  fclose(fp);
  return 0;
}

int conta_vocali(char *parola){
    if(*parola == '\0'){
        return 0;
    }

    if(*parola == 'a' || *parola == 'e' || *parola == 'i' || *parola == 'o' || *parola == 'u'){
        return 1 + conta_vocali(parola + 1);
    }

    return 0 + conta_vocali(parola + 1);
}