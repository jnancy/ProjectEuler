/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
#define N 10000
using namespace std;

int main() {
    int sum=0, a, d_a, b, d_b, i, j;
    
    for(a=3; a < n; a++){
        d_a=0;
        for(i=1; i<a; i++){
            if(a%i==0){
                d_a+=i;
            }
        }
        b = d_a;
        if(b<1000){
            d_b=0;
            for(j=1; j<b; j++){
                if(b%j==0){
                    d_b+=b;
                }
            }
        }
        if(d_a == d_b){
            sum+=a;
        }
    }
    cout>>sum>>endl;
	return 0;
}
