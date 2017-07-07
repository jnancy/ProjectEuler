//  **Works but not optimal**
//  Highly divisible triangular number
//  12
//  What is the value of the first triangle number to have over five hundred divisors?

//  Created by Nancy Jiang on 2017-07-05.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

int main(void){
    int i=1,triangleNum=1,div,numDiv;
    
    while(numDiv<=500){
        i++;
        triangleNum+=i;
        numDiv=0;
        for(div=1;div<=triangleNum;div++){
            if(triangleNum%div==0)
                numDiv++;
        }
    }
    printf("%d",triangleNum);
    
}
