// **WORK IN PROGRESS**
//  main.c
//  20
//
//  Created by Nancy Jiang on 2017-07-13.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

/*
 n! means n × (n − 1) × ... × 3 × 2 × 1
 
 For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 
 Find the sum of the digits in the number 100!
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NUM 100

int main(void){
    long factorial = 1, sum = 0;
    
    for(int i = NUM; i>1; i--){
        factorial*=i;
        printf("%ld\n", factorial);
    }
    
    while(factorial>0){
        sum+=factorial%10;
        factorial/=10;
    }
    printf("%ld", sum);
    
    return 0;
}
