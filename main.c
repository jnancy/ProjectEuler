//
//  main.c
//  Problem 7
//
//  Created by Nancy Jiang on 2017-02-12.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//
// Largest prime factor.

#include <stdio.h>

#define NUMBER 10001

int main( void ) {
    int num = 2;
    int count;
    int add = 0;
    int factor;
    
    for( count = 0; count < NUMBER; count++ ){
        do{
            add = 0;
            
            for( factor = num - 1; factor > 1; factor-- ){
                if ( num%factor == 0 )
                    add+=1;
            }
            num++;
        }while( add != 0 );
    }
    
    printf( "The %d prime is %d.", count, num - 1 );
    return 0;
}
