//
//  Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
//
//  Created by Nancy Jiang on 2017-06-21.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

#include <stdio.h>

int main(void){
    long sumOfSquares=0, sum=0, squareOfSum, i;
    
    for(i = 1; i<=100; i++){
        sumOfSquares+=(i*i);
        sum+=i;
    }
    squareOfSum = sum*sum;
    printf("%ld\n", squareOfSum-sumOfSquares);
    
    return 0;
}
