//
//  main.c
//  Problem 4
//
//  Created by Nancy Jiang on 2017-05-26.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//
//  Find the largest palindrome made from the product of two 3-digit numbers.

#include <stdio.h>

int main(void) {
    int n = 997, a, b, c, pal, fact;
    
    while(n > 900){
        a = (n - n%100)/100;
        b = (n%100 - n%10)/10;
        c = n%10;
        
        pal = a*100000 + b*10000 + c*1000 + c*100 + b*10 + a;
    
        fact = 999;
        
        while(pal%fact!=0 && fact>800){
            fact--;
        }
        
        if(pal%fact == 0 && pal/fact < 1000){
            printf("Largest pal is %d and its factors are %d,%d", pal, fact, pal/fact);
            break;
        }
        n--;
    }
    return 0;
}
