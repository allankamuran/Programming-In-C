//
//  main.c
//  Lab 3, Uppgift 2
//
//  Created by Allan Kamuran on 11/11/15.
//  Copyright © 2015 Allan Kamuran. All rights reserved.
//
//  Allan Kamuran
//  920824
//  akn14006
//
//  Det h‰r programmet ska visa upp olika tr‰ningar och summa ihop detoch visa om det ‰r ett par, tvÂ par, triss.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DICECOUNT 5 // Man kan byta 5 till en annan siffra sÂ den visar flera tr‰ningar

// Den h‰r funktionen l‰gger ett slumptal mellan 1 till 6 i varje array
void the_array(int array[])
{
    
    int i;
    
    for(i = 0; i < DICECOUNT; i++)
    {
        array[i] = rand()%6+1;
    }
    
}

// Den h‰r funktionen printar ut den grafiska delen till tr‰ningarna
void grafiska_tarningar(int array[])
{
    
    int i;
    
    char ett[3][6]= {{"     "},{"  *  "},{"     "}};
    char tva[3][6]= {{"     "},{" * * "},{"     "}};
    char tre[3][6]= {{"  *  "},{"  *  "},{"  *  "}};
    char fyra[3][6]= {{" * * "},{"     "},{" * * "}};
    char fem[3][6]= {{" * * "},{"  *  "},{" * * "}};
    char sex[3][6]= {{" * * "},{" * * "},{" * * "}};
    
    for( i = 0; i < DICECOUNT; i++)
    {
        
        switch(array[i]) // H‰r anv‰nde jag en switch-sats
        {
            case 1:
                printf("%s\n%s\n%s\n\n", ett[0], ett[1], ett[2]);
                break;
                
            case 2:
                printf("%s\n%s\n%s\n\n", tva[0], tva[1], tva[2]);
                break;
                
            case 3:
                printf("%s\n%s\n%s\n\n", tre[0], tre[1], tre[2]);
                break;
                
            case 4:
                printf("%s\n%s\n%s\n\n", fyra[0], fyra[1], fyra[2]);
                break;
                
            case 5:
                printf("%s\n%s\n%s\n\n", fem[0], fem[1], fem[2]);
                break;
                
            case 6:
                printf("%s\n%s\n%s\n\n", sex[0], sex[1], sex[2]);
                break;
        }
    }
}

// Den h‰r funktionen summerar ihop alla olika tr‰ningar till ett v‰rde
void summera_tarningarna(int array[])
{
    
    int sum = 0, i;
    
    for( i = 0; i < DICECOUNT; i++ )
    {
        sum = sum + array[i];
    }
    printf("Summa (%d+%d+%d+%d+%d): %d\n", array[0], array[1], array[2], array[3], array[4], sum); // H‰r har jag deklarerat alla arrays
    
}

// Den funktionen printar ut om av det ‰r ett par, tvÂ par eller triss som har visats av alla t‰rningar
void par_eller_inte(int array[])
{
    
    int i, j, count = 0, par = 0, triss = 0;
    
    for(i = 0; i < 6; i++)// Fˆrsta loopen gÂr igenom allt som ‰r mellan kramlarna och kollar 6 gÂnger
    {
        for(j = i + 1; j < 6; j++)// Andra loopen kollar om array i ‰r lika med array j och plusar pÂ
        {
            if(array[i] == array[j])
                count++;
        }
        if(count == 2)
            triss++;
        
        else if(count == 1)
            par++;
        
        count = 0;
    }
    if(triss == 1)
        printf("Triss");
    
    else if(par == 1)
        printf("Par");
    
    
    else if(par == 2)
        printf("Tva par");
}

int main(void)

{
    system("color A"); // H‰r sÂ byta jag f‰rg pÂ terminalen
    
    char os = ' '; // mellan slag fˆr att kˆra igen
    int array[DICECOUNT];
    
    srand(time(0)); // Behˆver den h‰r fˆr att jag ska kˆra med rand-sats sÂ den slumpar talet
    
    while(1)
    {
        system("cls"); // H‰r sÂ rensar jag terminalen fˆr varje gÂng jag kˆr programmet igen
        
        the_array(array); // Den h‰r gˆr sÂ jag fÂr olika slumptal pÂ t‰rningarna
        
        grafiska_tarningar(array); // Den h‰r printar ut den grafiska delen av t‰rningarna
        
        summera_tarningarna(array); // Den h‰r summmerar ihop alla t‰rningar
        
        par_eller_inte(array); // Den h‰r visar om det ‰r ett par eller inte
        
        while(1) // Fˆr att jag ska kunna kˆra programmet igen eller inte
        {
            printf("\nTryck pa mellanslag for en ny korning eller 'q' for avsluta.\n");
            os = getch();
            if (os == ' ') // mellanslag fˆr att kˆra igen
            {
                break;
            }
            else if(os == 'q') // q fˆr att avsluta programmet
            {
                return 0;
            }
        }
    }
    
    return 0;
}
