//
//  inkopslista.h
//  Lab 7, Uppgift 1
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//

#ifndef inkopslista_h
#define inkopslista_h
#ifndef INKOPSLISTA_H //Include Guard pÂ stackoverflow
#define INKOPSLISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct // H‰r ‰r structen som jag anv‰nder fˆr alla olika varpr
{
    int id; // ID pÂ varan
    char namn[50]; // Namn pÂ varan
    float antal; // Hur mÂnga va varan
    char enhet[10]; // Vad den har fˆr enhet som kg, liter eller st
    short int raderad; // Den h‰r anv‰nder jag sen n‰r jag tar bort varor i filerna
    
} varapost;

void str_space(char*, int, char*); // Den h‰r funktionen Skapar en str‰ng(strut) av en viss bredd(strlangd). UtgÂr frÂn en str‰ng(str) och fyller pÂ med mellanslag tills den ˆnskade bredden(strlangd) ‰r uppfylld

void meny(varapost*, int*); // Den h‰r funktionen ‰r fˆr alla olika alternativ i menyen

void skapa_vara(varapost**, varapost**, int *); // Den h‰r funktionen skapar en vara som sen sparas i filen

void skriv_ut_varor(varapost*, int*); // Den h‰r funktionen skriver ut varorna pÂ terminalen sÂ man vet vilka varor man har d‰r

int ar_nummer(char*); // Den h‰r funktionen tar reda pÂ om en str‰ng innehÂller ett tal

void ta_bort_vara(varapost*, int*); // Den h‰r funktionen tar bort varor ifrÂn filen

void spara_varor(varapost*, int*); // Den h‰r funktionen sparar varorna i en fil

void hamta_varor(varapost**, int*); // Den h‰r funktionen l‰ser in varorna frÂn en fil

void andra_vara(varapost*, int*); // Den h‰r funktionen ‰ndrar pÂ varorna

#endif


#endif /* inkopslista_h */
