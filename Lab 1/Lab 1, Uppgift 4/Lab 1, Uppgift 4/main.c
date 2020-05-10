//
//  main.c
//  Lab 1, Uppgift 4
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det här programmet visar olika morsekod genom att använda en switch-sats

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int morsekod;
    int kora = 1;
    
    while(kora)// Så jag kan köra programmet om igen om man vill
    {
        printf("\nValj din morsekod: ");// Printar ut att man ska välja en morsekod
        scanf("%d", &morsekod);
        
        switch(morsekod)// Här börjar switch-satsen
        {
            case 0: printf("-----"); break;
            case 1: printf(".----"); break;
            case 2: printf("..---"); break;
            case 3: printf("...--"); break;
            case 4: printf("....-"); break;
            case 5: printf("....."); break;
            default: printf("Du har skrivit in fel siffra"); break;// Här printar jag ut om man har skrivit in fel siffra
        }
        printf("\nVill du kora en gang till (1 for ja, 0 for nej)?");// Om man vill köra programmet igen
        scanf("%d", &kora);
    }
    return 0;
}
