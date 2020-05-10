//
//  main.c
//  Lab 3, Uppgift 1
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det här programmet visar 10 olika tal och sen ska man skriva in om ett tal förekommer mest.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Den h‰r funktionen slumpar tal mellan 1 till 10
int slumptal(int array[], int antal)
{
    int i;
    
    for( i = 0; i < antal; i++)
    {
        array[i] = rand() % 10+1;
        
    }
    return 0;
}

// H‰r ska jag sˆka efter ett specefikt tal i arrayen
int sokning(int array[], int antal, int sok_tal)
{
    int i;
    int summa = 0;
    
    for( i = 0; i < antal; i++ )
    {
        if(sok_tal == array[i])
            summa = summa + 1;
    }
    return summa;
}


int slumptal(int array[], int antal);

int main()
{
    srand(time(0));
    
    char fortsatt = '\0';
    int array[10];
    int tal;
    int summa;
    int i;

    do{
        slumptal(array, 10); // H‰r visar dom slumpade talen
        
        for( i = 0; i < 10; i++)
        {
            printf("Tal:%d\n", array[i]); // H‰r sÂ printar den ut alla 10 tal
        }
        
        printf("Vad ska jag soka efter?\n"); // H‰r ska man skriva in vilket tal man ska sˆka efter
        scanf("%d", &tal);
        
        summa = sokning(array, 10, tal);
        
        printf("Talet %d forekommer %d ganger.\n", tal, summa); // H‰r sÂ visar den de talet man skrev in som fˆrekom mest
        
        printf("Vill du mata in en ny sekvens j/n?\n"); // Om jag vill kˆra programmet igen eller inte
        scanf(" %s", &fortsatt);
        
    }while(fortsatt == 'j'); // Om jag vill forts‰tt sÂ skriver jag in j
    
    return 0;
}