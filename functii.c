#include "header.h"

void alege_cuvant_random(char cuvant_secret[])
{
    FILE *f;
    f=fopen("dictionar.txt","r");
    if(f==NULL)
    {
        printf("nu am putut gasi fisierul\n");
        return;
    }
int n=rand()%20;
int i;
for(i=0;i<=n;i++)
fscanf(f,"%s",cuvant_secret);
fclose(f);


}
void start_joc()
{
    char secret[LUNGIME_MAX];
    char mascat[LUNGIME_MAX];
    int vieti=MAX_VIETI;
    alege_cuvant_random(secret);
    int n=strlen(secret);
    int i;
    for(i=0;i<n;i++)
    mascat[i]='_';
    mascat[i]='\0';
    int ok=1;
    while(vieti>0&&ok==1)
    { int da=0;
        afiseaza_spanzuratoarea(vieti);
        printf("\nMai ai %d vieti\n",vieti);
        for(i=0;i<n;i++)
        {printf("%c",mascat[i]);
        printf(" ");}
        char litera;
        scanf(" %c",&litera);
        for(i=0;i<n;i++)
        if(secret[i]==litera)
        {mascat[i]=litera;da=1;}
        if(da==0)
        vieti--;
        int contor=0;
        for(i=0;i<n;i++)
        if(mascat[i]=='_') contor++;
        if(contor ==0) ok=0;
    }
    if(vieti>0)
    {
        printf("AI CASTIGAT ,BRAVO!");
    }
    else
    {
        afiseaza_spanzuratoarea(0);
        printf("ai pierdut,mai incearca o data baiete.Cuvantul cautat era %s",secret);
    }
}
void afiseaza_spanzuratoarea(int vieti) {
    printf("\n  +---+\n");
    printf("  |   |\n");
    
    switch(vieti) {
        case 6: 
            printf("      |\n      |\n      |\n"); break;
        case 5: 
            printf("  O   |\n      |\n      |\n"); break;
        case 4: 
            printf("  O   |\n  |   |\n      |\n"); break;
        case 3: 
            printf("  O   |\n /|   |\n      |\n"); break;
        case 2: 
            printf("  O   |\n /|\\  |\n      |\n"); break;
        case 1: 
            printf("  O   |\n /|\\  |\n /    |\n"); break;
        case 0: 
            printf("  O   |\n /|\\  |\n / \\  |\n"); break;
    }
    printf("      |\n=========\n");
}