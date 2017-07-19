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
#define INPUTFILE "cookie.txt"

//checks for the different types of wins
int royalFlush(char vals[], char suits[]);
int straightFlush(char vals[], char suits[]);
int fourOfAKind(char vals[]);
int fullHouse(char vals[]);
int flush(char vals[], char suits[]);
int straight(char vals[]);
int threeOfAKind(char vals[]);
int twoPairs(char vals[], char suits[]);
int onePair(char vals[], char suits[]);
int highCard(char vals[], char suits[]);

//converts 5 card values to numbers (i.e. 1,2,7,Q,A -> 1,2,7,12,14)
void convert(int nums[], char vals[]);

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
        //used to index hands
        int i;
        //keeps track of player 1's hand
        char p1nums[5];
        char p1suits[5];
        //keeps track of player 2's hand
        char p2nums[5];
        char p2suits[5];
        
        //scans the document for NUMBEROFROUNDS (1000) rounds of poker
        for(int numrounds = 0; numrounds<NUMBEROFROUNDS; numrounds++){
        
        //scans a line and stores the values in the appropriate array
            for(i = 0; i<10; i++){
                fscanf(infile, "%c%c", &p1nums[i], &p1suits[i]);
            }
        
            for(i = 0; i<10; i++){
                fscanf(infile, "%c%c", &p2nums[i], &p2suits[i]);
            }
            
        }
        
        fclose(infile);
    }
    return 0;
}
//****************
//determines if the player has a royal flush
int royalFlush(char vals[], char suits[]){
    //used to index things
    int i;
    
    //determines if all the cards are of the same suit
    int suit = suits[0];
    for(i = 1; i<5; i++){
        if(suits[i]!=suit){
            return 0;
        }
    }
    
    //determines if the cards are consecutive values
    int nums[5];
    convert(nums,vals);
    int smallest = nums[0];
    //finds the smallest value
    for(i = 1; i<5; i++){
        if(nums[i]<smallest)
            smallest = i;
        //can't have two of the same num
        else if(nums[i] == smallest)
            return 0;
    }
    //checks for consecutive values
    int ret = 0;
    for(i = 1; i<5; i++){
        for(int j = 0; j<5; j++){
            if(nums[j] == smallest+i){
                ret = 1;
            }
        }
        if(ret==0){
            return 0;
        }
    }
    printf("Royal flush!\n");
    return 1;
}
//****************
//determines if the player has a straight flush
int straightFlush(char vals[], char suits[]){
    //used to index things
    int i;
    
    //determines if all the cards are of the same suit
    int suit = suits[0];
    for(i = 1; i<5; i++){
        if(suits[i]!=suit){
            return 0;
        }
    }
    
    //determines if the cards are consecutive values
    int nums[5];
    convert(nums,vals);
    int smallest = nums[0];
    //finds the smallest value
    for(i = 1; i<5; i++){
        if(nums[i]<smallest)
            smallest = i;
        //can't have two of the same num
        else if(nums[i] == smallest)
            return 0;
    }
    //checks for consecutive values
    int ret = 0;
    for(i = 1; i<5; i++){
        for(int j = 0; j<5; j++){
            if(nums[j] == smallest+i){
                ret = 1;
            }
        }
        if(ret==0){
            return 0;
        }
    }
    printf("straight flush!\n");
    return 1;
}

//****************
//converts chars to nums
int fourOfAKind(char vals[]){
    int 
    
}


//****************
//converts chars to nums
void convert(int nums[], char vals[]){
    for(int i=0;i<5;i++){
        if(vals[i] == 'J'){
            nums[i] = 11;
        }
        if(vals[i] == 'Q'){
            nums[i] = 12;
        }
        if(vals[i] == 'K'){
            nums[i] = 13;
        }
        if(vals[i] == 'A'){
            nums[i] = 14;
        }
        else{
            nums[i] = vals[i];
        }
    }
}
