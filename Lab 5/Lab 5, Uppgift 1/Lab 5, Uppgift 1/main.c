//
//  main.c
//  Lab 5, Uppgift 1
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define ANTALVAROR 2

// ≈ = \217 ƒ = \216 ÷ = \231 Â = \206 ‰ = \204 ˆ = \224

/*
 Allan Kamuran
 920824
 akn14006
 
 Det h‰r programmet ska man kunna skriva in x-antal varor
 och jag anv‰nder mig av struct.
 */

typedef struct
{
    int id;
    char namn[50];
    float antal;
    char enhet[10];
    
}varapost;

void inmatning(varapost Varor[], int antal)
{
    int i;
    
    for(i = 0; i < antal; i++)
    {
        Varor[i].id = i + 1;
        
        printf("Namn p\206 vara %d: ", Varor[i].id);
        gets(Varor[i].namn);
        
        printf("Ange antal: ");
        while((scanf("%f", &Varor[i].antal) == 0))
        {
            printf("-> fel format p\206 inmatning, f\224rs\224k igen! <-\n");
            printf("Ange antal: ");
            fflush(stdin);
        }
        
        fflush(stdin);
        
        printf("Ange enhet: ");
        gets(Varor[i].enhet);
    }
}

int main(void)
{
    setlocale(LC_ALL,"sv_SE.ISO8859-1");
    
    int j;
    
    varapost Varor[ANTALVAROR];
    
    printf("Ange dina varor.\n");
    printf("----------------\n\n");
    
    inmatning(Varor, ANTALVAROR);
    printf("\nID\t\tNamn\t\tAntal\t\tEnhet\n");
    printf("-----------------------------------------------------\n");
    
    for(j = 0; j < ANTALVAROR; j++)
    {
        printf("\n%d\t\t%s\t\t%.2f\t\t%s\t\n",Varor[j].id, Varor[j].namn, Varor[j].antal, Varor[j].enhet);
    }
    
    return 0;
}
