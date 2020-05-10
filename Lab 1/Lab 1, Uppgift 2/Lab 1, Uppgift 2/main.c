//
//  main.c
//  Lab 1, Uppgift 2
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det här programmet plusar ihop två olika tal.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tal1, tal2, summa;
    
    printf("Skriv in ditt forsta tal\n");// Printar ut att man ska skriva in fˆrsta talet
    scanf("%d", &tal1);
    
    printf("Skriv in ditt andra tal\n");// Printar ut att man ska skriva in andra talet
    scanf("%d", &tal2);
    
    summa = tal1 + tal2;// H‰r plusar den ihop bÂda talen
    
    printf("Ditt svar ar %d", summa);// Printar ut vad svaret ‰r
    
    return 0;
}


