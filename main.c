//
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
//
//  Created by Nancy Jiang on 2017-06-21.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

#include <stdio.h>
#define MAX 20

long divisible( long product);

int main(void) {
    long product = 1, i;
    
    for(i = 1; i<=MAX; i++){
        product*=i;
    }
    
    printf("%ld is the product of nums 1-%d\n", product, MAX);
    
    for( i = 1; i<=MAX; i++){
        if( divisible(product/i)){
            product = product/i;
        }
    }
    for( i = 1; i<=MAX; i++){
        if( divisible(product/i)){
            product = product/i;
        }
    }
    printf("%ld is evenly divisible by nums 1-%d\n", product, MAX);
}

//checks if product is divisible by nums 1-20
long divisible( long product){
    int i;
    for(i = 1; i<= MAX; i++){
        if (product%i != 0)
            return 0;
    }
    return 1;
}
