//
//  main.c
//  Problem 3
//
//  Created by Nancy Jiang on 2017-05-26.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//
//  Finds the the largest prime factor of a given number

#include <stdio.h>
#define NUM 600851475143

int main(void) {
    long divisor = 2, num = NUM;
    
    while(num > 1){
        if(num%divisor == 0){
            num = num/divisor;
            divisor--;
        }
        divisor++;
    }
    printf("%ld", divisor);
    
    return 0;
}
