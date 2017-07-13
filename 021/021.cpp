//  main.c
//  21
//
//  Created by Nancy Jiang on 2017-07-12.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

/*
 Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 
 For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 
 Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>
#define N 10000
using namespace std;

int d(int);

int main() {
    int sum=0, a, b;
    
    for(a=1; a<N; a++){
        b=d(a);
        if(b<N && d(b)==a && a!=b){
            sum+=a;
        }
    }
    cout<<sum<<endl;
    return 0;
}

//sum of proper divisors
int d(int a){
    int sum = 0;
    for(int i=1; i<a; i++){
        if(a%i==0){
            sum+=i;
        }
    }
    return sum;
}
