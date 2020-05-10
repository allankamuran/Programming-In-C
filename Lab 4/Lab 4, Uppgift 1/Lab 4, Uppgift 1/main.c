//
//  main.c
//  Lab 4, Uppgift 1
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det h‰r programmet ska vista om talen man skriver in är ett primtal eller inte.
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Den h‰r funktionen gör sÂ den visar vilket tal som är ett primtal eller inte
int primtal(int tal)
{
    int i;
    
    for (i = 2; i < tal; i++)
    {
        if((tal%i) == 0)
            return 0;
    }
    return 1;
}

// Den h‰r funktionen tar bort alla tal som inte ‰r ett primtal sen i main!
int ta_bort_tal(int *arr, int len)
{
    int i, antal = len;
    for(i = 0; i < len; ++i)
    {
        if(!primtal(arr[i]) || arr[i] < 2)
        {
            arr[i] = 0;
            antal--;
        }
        
    }
    return antal;
}

// Den h‰r funktionen visar bara upp giltiga tal som ‰r primtal
int tal_giltiga(int *arr, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(arr[i] < 2)
            return -1;
    }
    return 1;
}

// Den h‰r funktionen visar om talen man sj‰lv harskrivit in ‰r ogiltiga tal eller ‰r alla primtal
void ogiltiga_tal(int *arr, int len)
{
    if(tal_giltiga(arr, len) != -1)
        printf("\nAlla tal ar giltiga.\n");// if-sats om alla tal ‰r giltiga
    else
        printf("\nOgiltiga tal finns.\n");// else-sats om det finns ett tal som ‰r ogiltiga
    
}

// Den h‰r funktionen gör sÂ man kan kˆra om prgrammet igen
char kora_igen()
{
    char go = 'j';
    do
    {
        printf("\n\nVill du kora en gang till? (j/n)\n");
        fflush(stdin);
        scanf("%c", &go);
        if(go == 'n' || go == 'j') break;
    }
    while(go != 'n' || go != 'j');
    return go;
}

int main(void)
{
    int input, i;
    int lista[100];// Här har jag 100 olika array platser
    char fortsatt = 'j';
    
    while(fortsatt == 'j')// SÂ jag kan köra programmet igen
    {
        printf("Mata in antal tal som ska anvandas(max 100): ");// Här börajar programmet med att mata in hur många olika tal man ska köra
        scanf("%d", &input);
        
        printf("\nMata in %d positiva tal.\n", input);// H‰r printar den ut hur många olika tal mna vill som ska köras
        
        for(i = 0; i < input; i++)// Visar vilka tal man har skrivit in
        {
            printf("\nTal: ");
            scanf("%d", &lista[i]);
        }
        
        ogiltiga_tal(lista, input);// H‰r deklarerade en funktion om visar om det finns nÂgon ogiltia tal eller om alla ‰r giltiga
        
        printf("Du matade in foljande tal: ");// H‰r printar den ut alla tal man har valt
        
        for(i = 0; i < input; i++)
        {
            printf("\t[%d]", lista[i]);
        }
        
        printf("\nPrimtal (totalt %d st):     ", ta_bort_tal(lista, input));// H‰r visar jag vilka av alla tal man har valt ‰r primtal
        for(i = 0; i < input; i++)
        {
            if(lista[i] != 0)
                printf("\t[%d]", lista[i]);
            else
                printf("\t");
        }
        fortsatt = kora_igen();// Den h‰r funktionen gˆr sÂ man kan kˆra om programmet igen
        
    }
    
    return 0;
}
