//
//  main.c
//  Problem 2
//
//  Created by Nancy Jiang on 2017-05-26.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//
//Finds the sum of all the even-valued fibonacci terms that do not exceed a specified maximum

#include <stdio.h>
#define MAX 4000000

int main(void) {
    int a = 1, b = 1, c = a + b, sum = 0;
    
    while(c<MAX){
        if(c%2 == 0){
            sum+=c;
        }
        a = b;
        b = c;
        c = a+b;
    }
    
    printf("%d", sum);
    
    
    return 0;
}
