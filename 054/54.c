/* In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
 
 High Card: Highest value card.
 One Pair: Two cards of the same value.
 Two Pairs: Two different pairs.
 Three of a Kind: Three cards of the same value.
 Straight: All cards are consecutive values.
 Flush: All cards of the same suit.
 Full House: Three of a kind and a pair.
 Four of a Kind: Four cards of the same value.
 Straight Flush: All cards are consecutive values of same suit.
 Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
 The cards are valued in the order:
 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
 
 If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.
 
 The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.
 
 How many hands does Player 1 win?
 */

//  main.c
//  54
//
//  Created by Nancy Jiang on 2017-07-18.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

#include <stdio.h>

#define NUMBEROFROUNDS 1000

//name of inputfile
#define INPUTFILE "poker.txt"

//converts 5 card values to numbers (i.e. 1,2,7,Q,A -> 1,2,7,12,14)
void convert(char vals[], int nums[]);

//returns the smallest value
int smallest(int nums[]);

//determines if player 1 won
int win(char p1nums[], char p1suits[], char p2nums[], char p2suits[]);

int main(void) {
    FILE *infile;
    infile = fopen(INPUTFILE, "r");
    
    if(infile == NULL){
        printf("ERROR: unable to open file\n");
    }
    else{
        //number of player 1 wins
        int wins = 0;
        //keeps track of player 1's hand
        char p1nums[5];
        char p1suits[5];
        //keeps track of player 2's hand
        char p2nums[5];
        char p2suits[5];
        
        //scans the document for NUMBEROFROUNDS (1000) rounds of poker
        for(int numrounds = 0; numrounds<NUMBEROFROUNDS; numrounds++){
        
        //scans a line and stores the values in the appropriate array
            for(int i = 0; i<10; i++){
                fscanf(infile, "%c%c", &p1nums[i], &p1suits[i]);
            }
            for(int i = 0; i<10; i++){
                fscanf(infile, "%c%c", &p2nums[i], &p2suits[i]);
            }
            if(win(p1nums, p1suits, p2nums, p2suits))
                wins++;
        }
    }
    return 0;
}
//deleted functions b/c a more elegant solution was found - will implement it soon
