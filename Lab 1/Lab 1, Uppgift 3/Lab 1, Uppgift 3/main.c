//
//  main.c
//  Lab 1, Uppgift 3
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det här programmet så ska man skriva in en vinkel och sen ska den
//  skriva ut om vinkeln är trubbig, spetsig eller rät.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int vinkel;
    
    printf("Ange din vinkel: ");// Start pÂ programmet
    scanf("%d", &vinkel);
    
    
    if(vinkel > 0 && vinkel < 90)// H‰r ‰r alla if-satser beroende pÂ vad fˆr vinkel man har skrivit in
    {
        printf("spetsig");
    }
    else if(vinkel > 90 && vinkel < 181)
    {
        printf("Trubbig!");
    }
    else if(vinkel == 90)
    {
        printf("Rat!");
    }
    else if (vinkel > 181)
    {
        printf("Vinkel ar for stor!");
    }
    else if(vinkel < 0)
    {
        printf("Vinkel ar for liten!");
    }
    
    return 0;
}

