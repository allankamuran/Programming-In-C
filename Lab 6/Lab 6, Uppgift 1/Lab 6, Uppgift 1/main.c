//
//  main.c
//  Lab 6, Uppgift 1
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det har programmet ska man kunna skriva in x-antal varor och jag anvander mig av struct.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    int id;
    char namn[50];
    float antal;
    char enhet[10];
    
} varapost;

varapost *inmatning(varapost *lista, int i)
{
    if(realloc(lista, sizeof(varapost)*(i+1)) == NULL)
        printf("Kan inte realloc minne!");
    
    (lista + i)->id = i + 1;
    
    printf("Namn p\206 vara %d: ", (lista + i)->id);
    fflush(stdin);
    
    gets((lista + i)->namn);
    
    printf("Ange antal: ");
    while((scanf("%f", &((lista + i)->antal)) == 0))
    {
        printf("-> fel format p\206 inmatning, f\224rs\224k igen! <-\n");
        printf("Ange antal: ");
        fflush(stdin);
    }
    fflush(stdin);
    
    printf("Ange enhet: ");
    gets((lista + i)->enhet);
    
    fflush(stdin);
    
    return lista;
}


int main(void)
{
    int j;
    int meny;
    int antal = 0;
    int kora = 1;
    
    setlocale(LC_ALL,"sv_SE.ISO8859-1");
    
    varapost *lista = malloc(sizeof(varapost));
    
    do
    {
        printf("\nMeny\n");
        printf("1 - Lagg till en vara till inkopslistan\n");
        printf("2 - Skriv ut inkopslistan\n");
        printf("3 - Avsluta programmet\n");
        
        printf("Ange val: ");
        scanf("%d", &meny);
        switch(meny)
        {
            case 1:
                lista = inmatning(lista, antal);
                antal++;
                break;
            case 2:
                printf("Inkopslista\n");
                printf("\nID\t\tNamn\t\tAntal\t\tEnhet\n");
                printf("-----------------------------------------------------\n");
                
                for(j = 0; j < antal; j++)
                {
                    printf("\n%d\t\t%s\t\t%.2f\t\t%s\t\n", (lista + j)->id, (lista + j)->namn, (lista + j)->antal, (lista + j)->enhet);
                }
                break;
            case 3:
                
                printf("\nAvslutar programmet!\n");
                free(lista);
                return 0;
                break;
            default:
                printf("fel val");
                break;
        }
    }
    while(kora);
    
    return 0;
}
