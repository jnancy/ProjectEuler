//  **WORK IN PROGRESS**
//  Longest Collatz sequence
//  Which starting number, under one million, produces the longest chain?
//  n -> n/1 (n is even); n -> 3n + 1 (n is odd)
//  main.c
//  14
//
//  Created by Nancy Jiang on 2017-07-06.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

#include <stdio.h>

int main(void){
    int startingnum, nextnum, count, num, longestlength = 0;
    
    for(startingnum = 900000; startingnum < 1000000; startingnum++){
        nextnum = startingnum;
        while(nextnum>1){
            if (nextnum%2 == 0){
                nextnum/=2;
            }
            else{
                nextnum = 3*nextnum + 1;
            }
            count++;
        }
        if(count>longestlength){
            longestlength = count;
            num = startingnum;
        }
    }
    
    printf("%d", startingnum);
        
}
