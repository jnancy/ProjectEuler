// ***WORK IN PROGRESS***
//  Highly divisible triangular number
//  12
//  What is the value of the first triangle number to have over five hundred divisors?

//  Created by Nancy Jiang on 2017-07-05.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

int main(void){
    int i=1,tnum=1,j,numdiv;
    
    while(numdiv<=500){
        i++;
        tnum+=i;
        numdiv=0;
        for(j=1;j<=tnum;j++){
            if(tnum%j==0)
                numdiv++;
        }
    }
    printf("%d",tnum);
    
}
