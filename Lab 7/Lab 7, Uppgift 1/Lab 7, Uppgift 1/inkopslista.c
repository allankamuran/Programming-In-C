//
//  inkopslista.c
//  Lab 7, Uppgift 1
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//

#include "inkopslista.h"
#include "inkopslista.h"  // H‰r har jag deklarerat "inkoplista.h"


/* Skapar en str‰ng(strut) av en viss bredd(strlangd). UtgÂr frÂn en str‰ng(str)
 och fyller pÂ med mellanslag tills den ˆnskade bredden(strlangd) ‰r uppfylld */
void str_space(char *str, int strlangd, char *strut)
{
    int i;
    int ilen;
    ilen = strlen(str);
    
    strcpy(strut, str);
    for(i = ilen; i < strlangd; i++)
    {
        strut[i]=' ';
    }
    strut[strlangd]='\0';
    
}


// Den h‰r funktionen ‰r fˆr meny och alla andra funktioner ‰r deklareade h‰r i menyn
void meny(varapost varor[], int *antal) // H‰r har jag struct och antal som inparametrar
{
    varapost *startvara;
    int anvandar_val = 0; // N‰r man v‰ljer vilken av alternativen man v‰ljer i menyn
    *antal = 0;
    
    do
    {
        printf("Meny\n\n");
        printf("-------------------------------------\n");
        printf("1)Lägg till en vara till inköpslistan\n2)Skriv ut inköpslistan\n3)Skriv inköpslistan till fil\n4)Läs in inköpslista frÂn fil\n5)Ändra vara\n6)Ta bort vara\n7)Avsluta\n");
        printf("Val: ");
        scanf("%d", &anvandar_val); // V‰ljer en valen man har
        
        switch(anvandar_val) // H‰r har jag anv‰nt mig av en switch-sats fˆr att det var det b‰sta alternativet
        {
            case 1:
                skapa_vara(&varor, &startvara, antal);
                break;
                
            case 2:
                skriv_ut_varor(varor, antal);
                break;
                
            case 3:
                spara_varor(varor, antal);
                break;
                
            case 4:
                hamta_varor(&varor, antal);
                break;
                
            case 5:
                andra_vara(varor, antal);
                break;
                
            case 6:
                ta_bort_vara(varor, antal);
                break;
                
            case 7:
                printf("\nTack för att du använde mitt program! :)\n");
                break;
                
            default:
                printf("Ogiltigt alternativ.\n"); // Om man skriver in nÂgot som ‰r under 1 eller ˆver 7 sÂ fÂr man ett meddelande
                break;
        }
    }
    while (anvandar_val != 7); // Jag loopar h‰r fˆr att jag ska kunna v‰lja flera gÂnger
    
    free(varor); // Fˆr att rensa det dynamiska minnet
}

// Den h‰r funktionen skapar varorna som sparas senare
void skapa_vara(varapost **vara, varapost **startvara, int *antal)
{
    int inmatning_ok;
    char tmpstr[100];
    int i = 0;
    int vara_index;
    //Fˆrsta alternativet ‰r att arryen ‰r helt tom: skapa fˆrsta varan
    if (*antal == 0)
    {
        *vara = (varapost*)malloc(sizeof(varapost)*1); // H‰r sÂ skapar jag dynamiskt minne till alla varor
        
        *startvara = *vara;
        vara_index = 0;
        (*antal) = 1;
    }
    else
    {
        //Om det finns nÂgon raderad vara, sˆk upp index(i-v‰rdet) fˆr den varan
        
        while( i < *antal  && (*vara)[i].raderad == 0)
        {
            i++;
        }
        //Andra alternativet. Om vi inte hittar nÂgon raderad vara sÂ mÂste vi allokera nytt minne
        if(i==(*antal))
        {
            *vara = (varapost*)realloc(*startvara, sizeof(varapost)*((*antal)+1));
            vara_index = *antal;
            (*antal)++;
        }
        else
        {
            //Tredje alternativet. Hittade en raderad vara sÂ vi anv‰nder det befintliga minnesutrymmet
            vara_index = i;
        }
    }
    
    
    (*vara)[vara_index].raderad = 0;
    (*vara)[vara_index].id = vara_index + 1;
    
    printf("Namn pÂ vara %d: ", (*vara)[vara_index].id); // H‰r sÂ skriver namn pÂ varan
    fflush(stdin);
    gets((*vara)[vara_index].namn);
    
    inmatning_ok=0;
    do
    {
        printf("Ange antal: "); // H‰r skriver man in antal pÂ varan
        gets(tmpstr);
        if(ar_nummer(tmpstr))
        {
            inmatning_ok = 1; // Om man skriver in r‰tt sÂ gÂr den it annars
        }
        else
        {
            printf("-> fel format pÂ inmatning, fˆrsˆk igen! <-\n");
        }
    }
    while(!inmatning_ok);
    
    (*vara)[vara_index].antal = atof(tmpstr);
    
    printf("Ange enhet: "); // H‰r sÂ matar man in enheten pÂ varan
    gets((*vara)[vara_index].enhet);
}

// Den h‰r funktionen skriver ut alla varorna
void  skriv_ut_varor(varapost *varor, int *antal)
{
    char *tmpstr1 = (char*)malloc(sizeof(char)*100);
    char *tmpstr2 = (char*)malloc(sizeof(char)*100);
    char *str_rad =(char*)malloc(sizeof(char)*100);
    int i;
    int antal_raderade_varor = 0;
    
    if(*antal==0)
    {
        printf("\nDet finns inga varor i listan\n");
    }
    else
    {
        printf("INKÖPSLISTA\n"); // Printar ut title pÂ inkˆopslitan
        printf("-------------------------------------\n");
        for(i = 0; i < (*antal); i++)
        {
            
            if (varor[i].raderad == 0)
            {
                
                
                sprintf(tmpstr1, "%d", varor[i].id); // Allt det h‰r gˆr sÂ alla varor hanmnar fint pÂ varje rad bredvid varandera
                str_space(tmpstr1, 5, str_rad);
                
                str_space(varor[i].namn, 15, tmpstr1);
                str_rad = strcat(str_rad, tmpstr1);
                
                sprintf(tmpstr1, "%.2f", varor[i].antal);
                str_space(tmpstr1, 8, tmpstr2);
                str_rad = strcat(str_rad, tmpstr2);
                
                str_space(varor[i].enhet, 10, tmpstr1);
                str_rad = strcat(str_rad, tmpstr1);
                
                printf("%s\n",  str_rad);
                
                
                str_rad[0] = '\0';
                tmpstr1[0] = '\0';
                tmpstr2[0] = '\0';
                
            }
            else
            {
                antal_raderade_varor++; // Plusar pÂ alla varor
                
            }
            
        }
        if(antal_raderade_varor==(*antal))
        {
            
            printf("Det finns inga varor i listan"); // Om man inte har lagt till varor sÂ kommer det h‰r upp
        }
        
    }
}

// Den h‰r funktionen tar reda pÂ om en str‰ng innehÂller ett tal
int ar_nummer(char *str)
{
    char *chk;
    
    
    if(strlen(str) == 0)
    {
        return 0;
    }
    else
    {
        //konvertera str‰ng till double(float).
        strtod(str, &chk);
        if ( isspace( *chk ) || *chk == 0 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


// Den h‰r funktionen ta bort en frÂn varor array
void ta_bort_vara(varapost *varor, int *antal)
{
    
    int vara_id;
    int i = 0;
    //int vara_idx;
    
    printf("Ange ID för vara du vill ta bort\n");
    scanf("%d", &vara_id);
    
    while(i < (*antal) && varor[i].id != vara_id)
    {
        i++;
    }
    if(i==(*antal))
    {
        printf("Kan inte ta bort vara med felaktigt ID");
    }
    else
    {
        varor[i].raderad=1;
        printf("Vara %d raderad. Skapar ny id för samtliga varor\n", vara_id);
        /* vara_idx = 1;
         for(i=0; i<*antal; i++){
         if(varor[i].raderad==0){
         varor[i].id = vara_idx;
         vara_idx++;
         }
         
         }*/
    }
}

// Den h‰r funktionen spara varor till fil
void spara_varor(varapost *varor, int *antal)
{
    
    size_t iAntal;
    int i;
    char *filnamn = malloc (sizeof(char)*100);
    FILE *fVaror;
    
    iAntal = 0;
    //kolla hur mÂnga varor som inte ‰r raderade
    for(i = 0; i < *antal; i++)
    {
        if(varor[i].raderad == 0)
        {
            iAntal++;
        }
    }
    if(iAntal == 0)
    {
        printf("Det finns inga varor i listan. Kan inte spara filen\n");
        
    }
    else
    {
        // Det finns minst en vara i arryen som inte ‰r raderad
        
        printf("Namnge fil\n");
        fflush(stdin);
        gets(filnamn);
        
        fVaror = fopen(filnamn, "wb");
        if(fVaror == NULL)
        {
            printf("Kan inte spara filen %s\n", filnamn);
        }
        else
        {
            // Spara antal varor fˆrst i filen
            fwrite(&iAntal, sizeof(int), 1, fVaror);
            
            // Lagra varje vara (som inte ‰r raderade) i filen
            
            for(i=0; i<*antal; i++)
            {
                if(varor[i].raderad == 0)
                {
                    fwrite(&varor[i],sizeof(varapost), 1, fVaror);
                }
            }
            fclose(fVaror);
        }
    }
}

// Den h‰r funktionen h‰mtar varor frÂn filen som angiven av anv‰ndaren
void hamta_varor(varapost **varorpek, int *antal)
{
    
    size_t iAntal;
    char *filnamn = malloc (sizeof(char)*100);
    FILE *fVaror;
    
    
    printf("Namnge sparad fil\n");
    fflush(stdin);
    gets(filnamn);
    
    
    fVaror = fopen(filnamn, "rb");
    
    if(fVaror == NULL)
    {
        printf("Kan inte ˆppna filen %s\n", filnamn);
    }
    else
    {
        // Om det redan finns varor i arrayen med varor ta bort dessa och frigˆr minne
        if(*varorpek != NULL)
        {
            free(*varorpek);
        }
        // L‰s in antalvaror
        iAntal=fread(antal, sizeof(int),1, fVaror);
        // Allokerar minne fˆr de inl‰sta varorna
        *varorpek = (varapost*)malloc(sizeof(varapost)*(*antal));
        
        
        // L‰s in varorna frÂn filen och placera de i arrayen med varor
        iAntal = fread(*varorpek, sizeof(varapost),*antal, fVaror);
        printf("L‰ste %zu antal varor frÂn filen\n", iAntal);
        
        fclose(fVaror);
    }
}

// Den h‰r funktionen
void andra_vara(varapost *varor, int *antal)
{
    
    int vara_id;
    int i = 0;
    int inmatning_ok;
    char tmpstr[100];
    
    
    printf("Ange ID fˆr vara du vill ‰ndra pÂ\n");
    scanf("%d", &vara_id);
    
    while(i < (*antal) && varor[i].id != vara_id)
    {
        i++;
    }
    if(i==(*antal))
    {
        printf("Kan inte ‰ndra vara. Felaktigt ID");
    }
    else
    {
        if(varor[i].raderad==1)
        {
            printf("Kan inte ‰ndra vara. Varan ‰r raderad");
        }
        else
        {
            // Visar vad varan har fˆr namn
            printf("Nuvarande namn pÂ vara ‰r: %s \n", varor[i].namn);
            printf("Namn pÂ vara %d \n",  varor[i].id);
            fflush(stdin);
            gets(varor[i].namn);
            
            inmatning_ok=0;
            // Visar vad varan har fˆr antal
            printf("Nuvrande antal av varan %f\n", varor[i].antal);
            do
            {
                printf("Ange antal: ");
                gets(tmpstr);
                if(ar_nummer(tmpstr))
                {
                    inmatning_ok=1;
                }
                else
                {
                    printf("-> fel format pÂ inmatning, fˆrsˆk igen! <-\n");
                }
            }
            while(!inmatning_ok);
            
            // Den visar vad nuvarande vara har fˆr enhet
            varor[i].antal = atof(tmpstr);
            printf("Nuvarande enhet pÂ vara %s\n", varor[i].enhet);
            printf("Ange enhet: ");
            gets(varor[i].enhet);
            
        }
    }
}
