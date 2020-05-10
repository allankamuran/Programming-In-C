//
//  main.c
//  Lab 4, Uppgift 2
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det h‰r programmet ‰r en frekvensanalys, man matar max 100 tal och den ska visa vilket tal som fˆrekommer mest och hur mÂnga gÂnger.
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Den h‰r funktionen tar hand om intervallet och sÂ man fÂr hur mpnga gÂnger talen fˆrekom
void intervallet(int *arr, int *lengd)
{
    int i, j, oversittare = 0, count = 0, storst = 0, temp = 0;
    
    for(i = 0; i < lengd; i++)
    {
        temp = arr[i];
        for(j = 0; j < lengd; j++)
        {
            if(temp == arr[j])
                count++;// SÂ den plusar fˆr varje gÂng ett tal fˆrekom
        }
        if(count > storst)
        {
            oversittare = temp;
            storst = count;
        }
        count = 0;
    }
    
    printf("\nTalet %d forekommer flest ganger, totalt %d ganger.\n", oversittare, storst);
    // Printar ut vilket tal och hur mÂnga gÂnger den fˆrekommer
}

// Det h‰r ‰r en funktion sÂ jag kan kˆra en gÂng till
char kora_igen()
{
    char go = 'j';
    do
    {
        printf("\nOm du vill kora om programmet tryck in (j/n)? ");
        fflush(stdin);
        scanf("%c", &go);
        if(go == 'n' || go == 'j') break;
    }
    while(go != 'n' || go != 'j');
    return go;
}


int main(void)
{
    int i, array[100], count = 0;// H‰r sÂ visar jag att den har 100 platser som man kan anv‰nda
    char fortsatt = 'j';
    
    while(fortsatt == 'j')// SÂ l‰nge jag trycker in j sÂ kˆra jag programmet igen
    {
        printf("Vanligen mata in tal mellan 0-1000 (Max 100 st). Avsluta med ett negativt tal.\n");
        printf("------------------------------------------------------------------------------\n");
        
        for(i = 0; i < 100; i++)// Loopar sÂ jag kan skriva in fler olika tal
        {
            printf("\nTal: ");
            scanf("%d", &array[i]);
            count++;// Plusar pÂ sÂ jag fÂr r‰tt antal fˆrkommnda tal
            
            if(array[i] > 1001)// If-sats sÂ jag inte kan skriva in ett stˆrre tal ‰n 1000
            {
                printf("For stort tal, fˆrsˆk igen.\n");
            }
            
            if(array[i] < 0)// If-sats sÂ om jag skriver in ett tal som ‰r mindre ‰n 0 sÂ avslutar jag och fort‰stter
                i = 1000000;
        }
        
        intervallet(array, &count);// Deklarerat funktionen h‰r
        
        count = 0;
        fortsatt = kora_igen();// Deklarerat funktionen h‰r
    }
    
    return 0;
}
