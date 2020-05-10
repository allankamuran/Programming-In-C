//
//  main.c
//  Lab 7, Uppgift 1
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran & Erik Bostrˆm
//
//  940806
//  ebm13004
//  920824
//  akn14006
//
//  Det h‰r programmet ‰r en sorts av inkˆpslista d‰r man matar in x-antal varor och sen kan kolla vad fˆr varor man har skirvit in och sen ska man kunna skriva in varorna i en fil f‰r som sparars. Man kan ocksÂ ta bort varor, ‰ndra pÂ varor och l‰sa varor frÂn en fil ‰r ocksÂ en alternativ med det h‰r programmet.


#include "inkopslista.h" // H‰r har jag deklarerat "inkopslista.h"


int main(void)
{
    setlocale(LC_ALL,"");
    varapost *varor = NULL;
    
    int antal_varor = 0;
    
    meny(varor, &antal_varor); // H‰r har jag deklarerat en huvudfunktion d‰r alla andra funktioner ‰r inlagda
    
    return 0;
}

