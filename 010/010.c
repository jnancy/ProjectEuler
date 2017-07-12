//
// Find the sum of all the primes below two million.
//
//  Created by Nancy Jiang on 2017-07-02.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

#include <stdio.h>
#define NUM 2000000

int isPrime(long int);

int main(void) {
    long int i;
    unsigned long sum = 2;
    for (i = 3; i < NUM; i+=2){
        if(isPrime(i) == 1){
            sum+=i;
        }
    }
    printf("%ld", sum);
    return 0;
}

//determines if a num is prime
int isPrime(long int num){
    int i;
    for(i = 3; i<=sqrt(num); i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
    }
