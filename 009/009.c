//  **WORK IN PROGRESS** 
//  main.c
//  9
//
//  Created by Nancy Jiang on 2017-07-12.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

/*
 A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 
 a^2 + b^2 = c^2
 For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 
 There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 Find the product abc.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SUM 1000

int main(void){
    int a,b,c,sum=0;
    
    for( a = 1; sum!=SUM; a++){
        b = a+1;
        while(b<=333){
            c = sqrt(a*a + b*b);
            if(c*c == a*a + b*b){
               sum = a+b+c;
            }
            if(sum == SUM && b<c){
                printf("%d",a*b*c);
                break;
            }
            b++;
        }
    }
    
    return 0;
}
