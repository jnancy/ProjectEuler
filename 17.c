/* 
   If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

   If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


   NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage
*/
//  ** WORK IN PROGRESS **
//  main.c
//  17
//
//  Created by Nancy Jiang on 2017-07-08.
//  Copyright © 2017 Nancy Jiang. All rights reserved.
//

#include <stdio.h>
#define HUNDRED 7
#define THOUSAND 8

//Initial attempt - too time consuming
int main(void) {
    //stores the number of letters in numbers 0-9 (note that zero is 0 because it is never included in written numbers >= 1)
    int unit[] = {0,3,3,5,4,4,3,5,5,4};
    //stores the number of letter in numbers 10-90 (the 0 is just a placeholder so ten is in entry ten[1])
    int ten[] = {0,3,6,6,6,5,5,7,6,6};
    int num, count = 0;
    
    //counts letters in numbers 1-999
    for(num=1; num<1000; num++){
        //accounts for the "and" in most numbers greater than one hundred
        if(num>100 && num%100!=0){
            count+=3;
        }
        while(num>0){
            //counts the num of letters in the units place
            count+=unit[num%10];
            num/=10;
            //counts the num of letters in the tens place
            count+=ten[num%10];
            num/=10;
            ////counts the num of letters in the hundreds place
            if(num>0){
                count+=HUNDRED;
                count+=unit[num];
            }
        }
        
    }
    //adds 1000 to the count
    count+=THOUSAND;
    
    printf("%d",count);

    return 0;
}

//Attempt numero dos:
int main(void) {
    //stores the number of letters in numbers 0-9 (note that zero is 0 because it is never included in written numbers >= 1)
    int unit[] = {0,3,3,5,4,4,3,5,5,4};
    //stores the number of letter in numbers 10-90 (the 0 is just a placeholder so ten is in entry ten[1])
    int ten[] = {0,3,6,6,6,5,5,7,6,6};
    int count, i;
    
    for(i = 1; i<=9; i++){
        //each number from 1-999 can be expressed as [0-9][0-9][0-9] (e.g. 12 = [0][1][2])
        //only the units place and hundreds place include the words one-nine, when written
        //thus, each number from 1-9 is used 200 times
        count+=200*unit[i];
        //counts letters contributed by tens place
        count+=100*ten[i];
    }
    //counts the number of times "hundred" is used
    //used for numbers >=100, therefore used (999-100+1) times
    count+=900*HUNDRED;
    //counts the number of times "and" is used
    count+=AND;
    
    printf("%d",count);
    return 0;
}
