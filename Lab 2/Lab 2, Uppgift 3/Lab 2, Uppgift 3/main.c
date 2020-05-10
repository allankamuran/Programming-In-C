//
//  main.c
//  Lab 2, Uppgift 3
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det h‰r ‰r mitt fˆrsta spel, spelaren ska gissa pÂ ett tal mellan 1 till 100.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gissningar = 0;// Den h‰r gˆra sÂ gissningarna nollas fˆr varje gÂng man kˆr aprogrammet igen

// Den h‰r funktionen gˆr sÂ man fÂr ett slumptal som man ska gissa pÂ
int slumptal_startvarde(void)
{
    int slumptal = rand()%100+1;
    return slumptal;
}

// Den h‰r funktionen gˆr sÂ man kan kˆra om programmet om och om igen
char kora_igen()
{
    char go = 'j';
    do
    {
        printf("Vill du kora en gÂng till? (j/n)\n");
        fflush(stdin);
        scanf("%c", &go);
        if(go == 'n' || go == 'j') break;
    }
    while(go != 'n' || go != 'j');
    return go;
}

// Den h‰r funktionen printar ut det mesta fˆr programmet
int gissa_tal(int slumptal)
{
    int tal;
    
    printf("Gissa pa ett tal som jag tanker pa mellan 1 till 100!\n");// Start texten till programmet
    scanf("%d", &tal);
    
    fflush(stdin);// Den h‰r tar bort alla resterande gamla scanf i prgrammet
    gissningar++;// Den h‰r delen gˆr sÂ det plusas pÂ med 1 fˆr att visa sen hur mÂnga man har gissat
    
    if(tal < slumptal)// H‰r ‰r alla ifs-satser fˆr att printa ut om man gissar fˆr hˆgt eller fˆr lÂgt
    {
        printf("Talet ar for lag\n");
    }
    else if(tal > slumptal)
    {
        printf("Talet ar for hogt\n");
    }
    else if(tal == slumptal)// H‰r sÂ printar den ut allt om man gissar r‰tt
    {
        printf("DU HAR GISSAT RATT GRATTIS!\n");// Om man gissar pÂ r‰tt siffra
        printf("Du har gissat %d ganger\n", gissningar);// H‰r sÂ visar den hur mÂnga gÂnger man har gissat
    }
    
    return tal;
}

int main()
{
    char fortsatt = 'j';
    int slumptal, slumpat = 0;
    srand(time(0));
    
    while(fortsatt == 'j')// En while-loop fˆr att kunna kˆra sen
    {
        system("cls");
        
        slumptal = slumptal_startvarde();// Funktionen som gˆr sÂ man fÂr ett startv‰rde
        
        while(slumpat != slumptal)// Funktionen sÂ man kan gissa flera gÂnger tills man gissar pÂ r‰tt tal
        {
            slumpat = gissa_tal(slumptal);// Funktionen sÂ mman kan gissa och fÂ test om man har gissat fˆr lÂgt eller fˆr hˆgt
        }
        
        fortsatt = kora_igen();// Funktionen sÂ man kan kˆra om igen
        
        gissningar = 0;
    }
    
    return 0;
}
