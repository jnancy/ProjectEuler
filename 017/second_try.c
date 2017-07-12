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
    //used for numbers >=100 that aren't divisible by 100, therefore used (999-100+1-9) times
    count+=891*AND;
    
    printf("%d",count);
    return 0;
}
