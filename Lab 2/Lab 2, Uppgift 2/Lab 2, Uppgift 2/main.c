//
//  main.c
//  Lab 2, Uppgift 2
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det här programmet växlar korner till euro i princip.

#include <stdio.h>
#include <stdlib.h>

// Den h‰r funktionen printar ut att man ska mata en hur mycket man vill konvertera till euro
float Inmatning()
{
    float fsek;
    printf("Mata in antal svenska kronor: ");
    scanf("%f", &fsek);
    return fsek;
}

// Den h‰r funktionen konverterar sÂ mycket man har skrivit ut
float konvertering(float fsek, float vxlkurs)
{
    return fsek/vxlkurs;
}

// Den h‰r funktionen skriver ut hur mycket kronerna blev till euro
void utskrift(float summa)
{
    printf("Detta motsvarar %.2f euro.\n", summa);
}


int main(void)
{
    float fsek, vxlkurs, summa;
    vxlkurs = 9.33;// H‰r sÂ jag har skrivit ut hur mycker v‰xelkursen ligger pÂ(kollade pÂ Forex)
    char svar;
    
    do// SÂ jag kan kˆra programmet igen om man vill
    {
        svar = '\0';
        fsek = Inmatning();// H‰r ‰r funktionen tar hand om inmatningen fˆr programmet
        summa = konvertering(fsek, vxlkurs);// H‰r ‰r funktionen tar hand om konverteraringen av v‰xelkursen
        utskrift(summa);// H‰r ‰r funktionen tar hand om utskriften
        printf("Ska vi köra en gång till?(j/n)\n");// Printar ut om man vill kˆra programmet igen eller inte
        scanf(" %c", &svar);
        
    } while( svar == 'j' || svar == 'J' );// H‰r visar den kan man anv‰nda ett J eller j fˆr att kˆra igen
    
    return 0;
}
