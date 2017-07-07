//  **WORK IN PROGRESS**
//  Longest Collatz sequence
//  Which starting number, under one million, produces the longest chain?
// n -> n/1 (n is even); n -> 3n + 1 (n is odd)
//  main.c
//  14
//
//  Created by Nancy Jiang on 2017-07-06.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

#include <stdio.h>
#define MAX 1000000

int main(void){
    int i, sequence, count, sequenceLength = 0, startingNumber = 0;
    
    for(i = 1; i <= MAX; i++){
        sequence = i;
        count = 0;
        while(sequence>1){
            if (sequence%2 == 0){
                sequence/=2;
            }
            else{
                sequence = 3*sequence + 1;
            }
            count++;
        }
        if(count>sequenceLength){
            sequenceLength = count;
            startingNumber = i;
        }
    }
    printf("%d", startingNumber);
}

