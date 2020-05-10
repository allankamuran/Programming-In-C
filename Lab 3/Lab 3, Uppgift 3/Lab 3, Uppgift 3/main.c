//
//  main.c
//  Lab 3, Uppgift 3
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det h‰r programmet ska kolla om en text som man skriver in ‰r en palindrom eller inte.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Den h‰r funktionen kopierar frÂn en till en annan string
void kopierar_string(char *from, char *to)
{
    int i;
    for(i = 0;; ++i)
    {
        to[i] = from[i];
        if(from[i] == '\0')
            break;
    }
}

// Den h‰r funktionen visar hur lÂng texten ‰r
int langden_pa_stringen(char* a)
{
    int langd;
    for(langd = 0; ; ++langd)
    {
        if(a[langd] == '\0') // den h‰r gˆr sÂ den best‰mmer l‰ngenden sÂ l‰nge arrayen har ett tecken i den
            break;
    }
    return langd;
}

// Den h‰r funktionen v‰nder pÂ ordet sÂ den kan kolla om den ‰r en palindrom eller inte
void vander_string(char *b)
{
    int i, langd;
    char typ; // H‰mtar l‰ngd pÂ str‰ngen, 1 fˆr index [0]
    
    langd = langden_pa_stringen(b)- 1;
    
    for(i=0; i<langd; ++i, --langd)
    {
        typ = b[i];
        b[i] = b[langd]; // Den h‰r delen v‰nder pÂ stringen
        b[langd] = typ;
    }
}

// Den h‰r funktionen jemfˆr tvÂ olika str‰ngarna och retunerar 0 vid olika och 1 fˆr lika
int jemfor_string(char *string, char *string2)
{
    int i;
    for(i = 0;; ++i)
    {
        if (string[i] != string2[i])
            return 0;
        if (string[i] == '\0' && string2[i] == '\0')
            break;
    }
    return 1;
}

// Den h‰r ifrÂn ctype.h sÂ den hoppar ˆver mellanslag och andra tecken
void ta_bort_tecken(char *a)
{
    int i, k;
    for(i=0, k=0;; ++i)// den h‰r loopen snurrar fˆrevit fˆr att den har inte nÂgot vilkor
    {
        if(a[i] != ' ' && a[i] != '.' && a[i] != ',' && a[i] != '\n')// Den hoppar ˆver mellansalg och sÂnt
        {
            a[k] = tolower(a[i]);// tolower ‰r med i ctype och den gˆr sÂ bokst‰verna blir lowercase
            k++;// Den tar bort och ers‰tter den med n‰sta element med en bokstav med i
        }
        if(a[i] == '\0')// Den berakar loppen sÂ fort det kommer ett element som ‰r tom
            break;
    }
}

int main()
{
    char a[100], b[100]; // Aryyen har upp till 100 olika lagerplatser
    char kora_igen = ' ';
    char dub[10];
    int jamfor;
    
    while(1)
    {
        printf("Skriv in en text: ");
        if (!fgets(a, sizeof a, stdin)) // Om fgets inte l‰ser nÂgot returnar den 0
        {
            return 0;
        }
        
        ta_bort_tecken(a); // Den h‰r tar bort mellanslag och andra olika tecken
        
        kopierar_string(a, b); // Den h‰r kopierar str‰ngen sÂ jag kan j‰mfˆra
        
        vander_string(b); // Den h‰r v‰nder pÂ str‰ngen
        
        jamfor = jemfor_string(a, b); // Den h‰r jemfˆr str‰ngen fˆr att se om det ‰r en palindrom eller inte
        
        if(jamfor == 0) // En if-sats fˆr att printa ut om det ‰r en palindrom eller inte
            puts("Ar inte en palindrom.\n");
        else if(jamfor == 1)
            puts("Ar en palindrom.\n");
        
        while(1) // Den h‰r kˆr programmet igen om man trycker in j eller n
        {
            
            printf("\nOm du vill kora igen(j/n)? ");
            if (fgets(dub, sizeof(dub), stdin) != 0)
                sscanf(dub, "%c", &kora_igen);
            if (kora_igen == 'j')
                break;
            else if(kora_igen == 'n')
                return 0;
            
        }
        
    }
    
    return 0;
}
