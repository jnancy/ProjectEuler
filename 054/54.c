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
//returns the highest card
int royalFlush(int nums[], char suits[]);
int straightFlush(int nums[], char suits[]);
int fourOfAKind(int nums[]);
int fullHouse(int nums[]);
int flush(int nums[], char suits[]);
int straight(int nums[]);
int threeOfAKind(int nums[]);
int twoPairs(int nums[]);
int onePair(int nums[]);
int highCard(int nums[]);

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
        fclose(infile);
        printf("Player 1 won %d out of %d matches", wins, NUMBEROFROUNDS);
    }
    return 0;
}
//****************
//determines if the player has a royal flush
int royalFlush(int nums[], char suits[]){
    if(straightFlush(nums, suits) && smallest(nums) == 11) return 1;
    return 0;
}
//****************
//determines if the player has a straight flush
int straightFlush(int nums[], char suits[]){
    int high = flush(nums,suits);
    if(straight(nums) && high) return high;
    return 0;
}
//****************
//determines if there's four of a kind
int fourOfAKind(int nums[]){
    int count1 = 0;
    int count2 = 0;
    
    int val1 = nums[0];
    int val2 = nums[1];
    
    for(int i = 0; i<5; i++){
        if(nums[i] == val1)
            count1++;
        else if(nums[i] == val2)
            count2++;
    }
    if(count1 == 4 || count2 == 4) return 1;
    return 0;
}
//****************
//determines if there's a full house
int fullHouse(int nums[]){
    int val = threeOfAKind(nums);
    int pair = 0;
    if(val){
        for(int i = 0; i<5; i++){
            if(nums[i]!=val) pair++;
        }
        if(pair == 2) return val;
    }
    return 0;
}
//****************
//determines if there's a flush
int flush(int nums[], char suits[]){
    char suit = suits[0];
    int highest = highCard(nums);
    
    for(int i = 1; i<5; i++){
        if(suits[i]!=suit) return 0;
    }
    return highest;
}
//****************
//determines if there's a straight
int straight(int nums[]){
    int least = smallest(nums);
    int ret = 0;
    for(int i = 1; i<5; i++){
        for(int j = 0; j<5; j++){
            if(nums[j] == least+i)
                ret = 1;
        }
        if(ret==0) return 0;
        ret = 0;
    }
    printf("straight\n");
    return 1;
}
//****************
//determines if there's a three-of-a-kind
int threeOfAKind(int nums[]){
    int count = 0;
    int val;
    //we need to try at most 3 vals bc at most 2 cards are not part of the three-of-a-kind
    for(int i = 0; i<3; i++){
        val = nums[i];
        for(int j = i+1; j<5; j++){
            if(nums[j] == val)
                count++;
        }
        if(count == 3)
            return 1;
    }
    return 0;
}
//****************
//determines if there are two pairs
int twoPairs(int nums[]){
    int pairs = 0;
    
    int val1 = nums[0];
    int val2 = nums[1];
    int val3 = nums[2];
    int val4 = nums[3];
    
    for(int i = 3; i<5; i++){
        if(nums[i] == val1)
            pairs++;
        else if(nums[i] == val2)
            pairs++;
        else if(nums[i] == val3)
            pairs++;
        else if(nums[i] == val4)
            pairs++;
    }
    if(pairs == 2) return 1;
    return 0;
}
//****************
//determines if there's one pair
int onePair(int nums[]){
    for(int i = 0; i<5; i++){
        int num = nums[i];
        for(int j = i+1; j<5; j++){
            if(nums[j] == num) return 1;
        }
    }
    return 0;
}
//****************
//determines the high card
int highCard(int nums[]){
    int largest = nums[0];
    for(int i = 1; i<5; i++){
        if(nums[i]>largest)
            largest = nums[i];
    }
    return largest;
}
//****************
//converts chars to nums
void convert(char vals[], int nums[]){
    for(int i=0;i<5;i++){
        if(vals[i] == 'J') nums[i] = 11;
        if(vals[i] == 'Q') nums[i] = 12;
        if(vals[i] == 'K') nums[i] = 13;
        if(vals[i] == 'A') nums[i] = 14;
        else nums[i] = vals[i];
    }
}
//****************
//finds the smallest value
int smallest(int nums[]){
    int smallest = nums[0];
    for(int i = 1; i<5; i++){
        if(nums[i]<smallest)
            smallest = nums[i];
    }
    return smallest;
}
//****************
//determines if p1 won
int win(char p1vals[], char p1suits[], char p2vals[], char p2suits[]){
    int p1nums[5];
    int p2nums[5];
    convert(p1vals, p1nums);
    convert(p2vals, p2nums);
    //highest card in player1, player2's best hand
    int high1, high2;
    
    if(royalFlush(p1nums, p1suits)){
        return 1;
    }
    else{
        high1 = straightFlush(p1nums, p1suits);
        high2 = straightFlush(p2nums, p2suits);
        if(high1>high2)
            return 1;
        //since there's always a "clear winner", this means that both players have no straight flushes (high 1 = high2 = 0)
        else if(high1==high2){
            high1 = fourOfAKind(p1nums);
            high2 = fourOfAKind(p2nums);
            if(high1>high2)
                return 1;
            else if(high1==high2){
                high1 = fullHouse(p1nums);
                high2 = fullHouse(p2nums);
                if(high1>high2)
                    return 1;
                else if(high1==high2){
                    high1 = flush(p1nums, p1suits);
                    high2 = flush(p2nums, p2suits);
                    if(high1>high2){
                        return 1;
                    }
                    else if(high1==high2){
                        high1 = straight(p1nums);
                        high2 = straight(p2nums);
                        if(high1>high2){
                            return 1;
                        }
                        else if(high1==high2){
                            high1 = threeOfAKind(p1nums);
                            high2 = threeOfAKind(p2nums);
                            if(high1>high2){
                                return 1;
                            }
                            else if(high1==high2){
                                high1 = twoPairs(p1nums);
                                high2 = twoPairs(p2nums);
                                if(high1>high2){
                                    return 1;
                                }
                                else if(high1==high2){
                                    high1 = onePair(p1nums);
                                    high2 = onePair(p2nums);
                                    if(high1>high2){
                                        return 1;
                                    }
                                    else if(high1==high2){
                                        high1 = highCard(p1nums);
                                        high2 = highCard(p2nums);
                                        if(high1>high2){
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
