//
//  main.c
//  Lab 2, Uppgift 1
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det här prgrammet så matar in x-antal tal och sen får man olika värden pÂ olika tal.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float tal, i, max = 0, min = 10000000;
    float summa = 0, medel = 0, valj = 1;
    
    printf("Valkommen till talraknare!\n");// Printar ut fˆrsta texten fˆr programmet
    printf("---------------------------------------------------------------------------\n");
    printf("Ange ett negativt tal for att avsluta inmatningen och skriva ut resultatet.\n");// Printar ut att man ska skriva in ett negativt tal fˆr att avsluta inmatningen
    
    while(1) {// While-loop fˆr att kunna kˆra igen
        for(i = 1; i <= 1001; i++)
        {
            printf("\nGe tal: ");// Printar ut sÂ man ska ge en till tal
            scanf("%f", &tal);
            
            if(tal < 0)// if-sats om tal mindren 0 sÂ avslutar den loopen
            {
                medel = summa / (i-1);
                printf("\nTalens summa: %.2f \n", summa);// Skriver ut vad summan av alla tal ‰r
                printf("Storsta talet: %.2f \n", max);// Skriver ut stˆrsta talet ‰r
                printf("Minsta talet: %.2f \n", min);// Skriver ut minsta talet
                printf("Medelvardet: %.2f \n", medel);// Skriver ut medelv‰rdet av alla tal
                i = 100000;
            }
            if(tal > max) max = tal;
            if(tal < min) min = tal;
            summa = summa + tal;
            
        }
        summa = 0;// H‰r sÂ nollst‰ller jag om man vill kˆra om prgrammet
        medel = 0;
        min = 0;
        max = 0;
        
        printf("Vill du kora programmet en gang till for ja tryck 1 for nej 0. ");
        scanf("%f", &valj);// H‰r skriver man in om man vill kˆra igen eller inte
        if(!valj) return 0 ;
    }
    
    return 0;
}