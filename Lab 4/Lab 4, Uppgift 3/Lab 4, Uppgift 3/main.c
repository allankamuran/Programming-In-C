//
//  main.c
//  Lab 4, Uppgift 3
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Den h‰r programmet sÂ matar man in en mening och programmet visar upp alla olika ord per rad.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Den h‰r funktionen r‰nkar hur mÂnga ord det ‰r i varje string
int ta_bort_mellanslag(char text[200], char *pointers[200])
{
    int i, n;
    for(i = 0, n = 0; text[i] != '\0'; ++i)// H‰r loopar den sÂ den r‰nkar alla ord och hoppar till n‰sta ord om det ‰r mellanslag
    {
        if(i == 0 || (text[i-1] == ' ' && text[i+1] != '\0'))
        {
            pointers[n] = &text[i]; // pekar till ett ord!
            n++;
        }
    }
    return n;
}

// Den h‰r funktionen printar ut Ord1:...
void print_ord(char *pointers, char *ord)
{
    int i;
    
    for(i = 0; pointers[i] != '\0' && pointers[i] != ' '; i++)
    {
        ord[i] = pointers[i];
    }
    
}

// Den h‰r funktionen gˆr sÂ man kan kˆra flera gÂnger om man vill
int kora_igen(char *string, char *pekare[])
{
    char igen, i;
    
    printf("\nVill du kora igen (j/n)? ");
    scanf("%c", &igen);
    
    if(igen == 'j')
    {
        for(i=0; pekare[i] != '\0'; ++i)// Loopar och nollst‰ller ord arrayen
        {
            pekare[i] = ' ';
        }
        for(i=0; string[i] != '\0'; ++i)
        {
            string[i] = ' ';
        }
    }
    else
    {
        return 0;
    }
    fflush(stdin);// Tar bort rest grejer i programmet sÂ det inte blir fel n‰r man kˆr om programmet
    
    return 1;
}

int main(void)
{
    char string[200];// Jag har 200 olika array som jag kan anv‰nda orden i
    char *pekare[200];
    int ord, i;
    
    do
    {
        printf("Mata in en string: ");// H‰r mataqr man in meningen
        gets(string);
        
        ord = ta_bort_mellanslag(string, pekare);// H‰r deklarerar jag en funktion
        for(i = 0; i < ord; ++i)
        {
            char orden[100] = {'\0'};
            if(pekare[i] == NULL)// Den h‰r rensar med NULL
                break;
            
            print_ord(pekare[i], orden);// H‰r deklarerar jag andra funktionen
            printf("Ord%d: %s\n", i + 1, orden);// Printar ut Ord1...osv
        }
        
    }
    while(kora_igen(string, pekare));// H‰r deklarerar jag funktionen sÂ man kan kˆra programmet
    
    return 0;
}

