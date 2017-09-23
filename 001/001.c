//
//  main.c
//  Problem 1
//
//  Created by Nancy Jiang on 2017-02-12.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//
// Finds the sum of all the multiples of specified factors below a specified number.

#include <stdio.h>

#define FACTOR1 3
#define FACTOR2 5
#define MAX 1000

int main( void ){
    int num;
    int sum = 0;
    
    for( num = 1; num < MAX; num++){
        if (num%FACTOR1 == 0 || num%FACTOR2 == 0)
            sum+=num;
    }
    printf("Sum is %d.", sum);
    return 0;
}
