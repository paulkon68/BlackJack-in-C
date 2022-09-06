// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SUITS 4
#define FACES 13
#define CARDS 52


// prototypes
void shuffle( unsigned int wDeck[][ FACES ] ); // shuffling modifies wDeck
int deal( unsigned int wDeck[][ FACES ], const char *wFace[], 
   const char *wSuit[] ); // dealing doesn't modify the arrays

int main( void )
{
   
   // initialize suit array                       
   const char *suit[ SUITS ] =            
      { "Hearts", "Diamonds", "Clubs", "Spades" };
   
   // initialize face array                   
   const char *face[ FACES ] =
      { "Ace", "Deuce", "Three", "Four",         
        "Five", "Six", "Seven", "Eight",         
        "Nine", "Ten", "Jack", "Queen", "King" };

   // initialize deck array
   unsigned int deck[ SUITS ][ FACES ] = { 0 };

   srand( time( NULL ) ); // seed random-number generator

   shuffle( deck ); // shuffle the deck
   deal( deck, face, suit );

} // end main

// shuffle cards in deck
void shuffle( unsigned int wDeck[][ FACES ] )
{
   size_t row; // row number
   size_t column; // column number
   size_t card; // counter

   // for each of the cards, choose slot of deck randomly
   for ( card = 1; card <= CARDS; ++card ) {

      // choose new random location until unoccupied slot found
      do {                                                        
         row = rand() % SUITS;                                   
         column = rand() % FACES;                             
      } while( wDeck[ row ][ column ] != 0 ); // end do...while

      // place card number in chosen slot of deck
      wDeck[ row ][ column ] = card;
   } // end for
} // end function shuffle

// deal cards in deck
int deal( unsigned int wDeck[][ FACES ], const char *wFace[], const char *wSuit[] )
{
   size_t card; // card counter
   size_t row; // row counter
   size_t column; // column counter
   size_t counter = 0;
   int player_card_sum = 0;
   int computer_card_sum = 0;
   int turn = 1;
   char choice = -1;
   
   // deal each of the cards
   printf("\nPlayer's turn Draw or pass? ");
   for ( card = 1; card <= CARDS; ++card ) {
      // loop through rows of wDeck
      for ( row = 0; row < SUITS; ++row ) {
         // loop through columns of wDeck for current row
         for ( column = 0; column < FACES; ++column ) {
            // if slot contains current card, display card
            if ( wDeck[ row ][ column ] == card ) {
                  if(turn = 1){
                     scanf("%c", &choice);
                     if(choice == 'P') {
                        turn = 0;
                     }
                     if(choice == 'D'){
                        printf( "%5s of %-8s ", wFace[ column ], wSuit[ row ]);
                        if(wFace[column] == "Ace"){
                           player_card_sum += 11;
                        }
                        else if(wFace[column] == "Deuce"){
                           player_card_sum += 2;
                        }
                        else if(wFace[column] == "Three"){
                           player_card_sum += 3;
                        }
                        else if(wFace[column] == "Four"){
                           player_card_sum += 4;
                        }
                        else if(wFace[column] == "Five"){
                           player_card_sum += 5;
                        }
                        else if(wFace[column] == "Six"){
                           player_card_sum += 6;
                        }
                        else if(wFace[column] == "Seven"){
                           player_card_sum += 7;
                        }
                        else if(wFace[column] == "Eight"){
                           player_card_sum += 8;
                        }
                        else if(wFace[column] == "Nine"){
                           player_card_sum += 9;
                        }
                        else if(wFace[column] == "Ten"){
                           player_card_sum += 10;
                        }
                        else if(wFace[column] == "Jack"){
                           player_card_sum += 2;
                        }
                        else if(wFace[column] == "Queen"){
                           player_card_sum += 3;
                        }
                        else{
                           player_card_sum += 4;
                        }
                        printf("Sum = %d\n", player_card_sum);
                        if(player_card_sum > 21){
                           puts("You\'ve lost!");
                           exit(0);
                        }

                     }
                  }
                     if(choice == 'P'){
                        printf("\nComputer's turn ");
                        do{
                           if(wFace[column] == "Ace"){
                              computer_card_sum += 11;
                           }
                           else if(wFace[column] == "Deuce"){
                              computer_card_sum += 2;
                           }
                           else if(wFace[column] == "Three"){
                              computer_card_sum += 3;
                           }
                           else if(wFace[column] == "Four"){
                              computer_card_sum += 4;
                           }
                           else if(wFace[column] == "Five"){
                              computer_card_sum += 5;
                           }
                           else if(wFace[column] == "Six"){
                              computer_card_sum += 6;
                           }
                           else if(wFace[column] == "Seven"){
                              computer_card_sum += 7;
                           }
                           else if(wFace[column] == "Eight"){
                              computer_card_sum += 8;
                           }
                           else if(wFace[column] == "Nine"){
                              computer_card_sum += 9;
                           }
                           else if(wFace[column] == "Ten"){
                              computer_card_sum += 10;
                           }
                           else if(wFace[column] == "Jack"){
                              computer_card_sum += 2;
                           }
                           else if(wFace[column] == "Queen"){
                              computer_card_sum += 3;
                           }
                           else{
                              computer_card_sum += 4;
                           }
                        }
                        while(computer_card_sum <= 21 && computer_card_sum <= 14);
                        printf("Sum = %d\n", computer_card_sum);
                        if(computer_card_sum > 21){
                           puts("Player Won!");
                           exit(0);
                        }
                        if(computer_card_sum >= player_card_sum){
                           puts("Computer Won");
                        }
                        else{
                           puts("Player Won!");
                        }
                        exit(0);
                     }
               
                  
            } 
         } 
      } 
   } 
    return 0;
} 
