//
// Created by Bori Akinola on 21/02/2021.
//

#include <stdio.h>
#include <string.h>
#include "userInput.h"


// function to initialise the array of structs of type profile
void initialiseProfile(struct profile sArr[]){

    for(int i = 0; i < MAX_ARTISTES; i++){
        // sets each artistes to empty strings
        strcpy(sArr[i].artiste, " ");
        // sets the number of songs of each artiste to 0
        sArr[i].num_songs = 0;

        for(int j = 0; j<MAX_SONGS; j++){
            // sets the songs of each artiste to empty strings as well
            strcpy(sArr[i].songs[j], " ");
        }
    }
}


// function to read in the input from the keyboard into the array
void readKeyboard(struct profile sArr[]){
    /*
     * prompt the user for the format to input the artistes and
     * their songs
     */

    printf("No file found.\n");
    printf("Enter the artistes and their songs with the following format:\n");
    printf("Artiste name\nSong title***Song duration\n"
           "Song title***Song duration\n"
           "...\nSong title***Song duration\n"
           "<blank line>\n");
    printf("Artiste name\nSong title***Song duration\n"
           "Song title***Song duration\n"
           "...\nSong title***Song duration\n"
           "<blank line>\n...\n");
    printf("Song duration in the form mm:ss\n"
           "End input with 0\nYour entry:\n");


    int i=0;  // declare necessary variables as loop counter

    char check[MAX_CHAR]; // variable to check the next string before going into
                            // the struct

    do{
        // put the first string in the struct artistev of the first struct in the array
        // of structs
        inputKey(sArr[i].artiste);

        // put the next string gotten from the keyboard into the check variable
        inputKey(check);

        // declare the counter for the array "songs" inside the struct
        int j=0;

        // while loop runs until the first string without the "***" substring is
        // encountered
        while(strstr(check, "***") != 0){
            // put copy into the first song array position
            strcpy(sArr[i].songs[j], check);
            // get the next value from the keyboard
            inputKey(check);

            // increment the songs array counter
            j++;
        } // loop ends
        sArr[i].num_songs = j; // set num.songs to j. The number of songs that artiste has
        i++; // increment the struct array counter
    } while(strcmp(check, "0") != 0);
    // the do while loop ends when a '0' is encountered which signals end of input
    artNum = i; // set global variable to i. which is the number of artistes encountered so far
}


// function to read in from a file into an array of structs
void readFile(FILE* fp, struct profile sArr[]){

    int i=0;  // declare necessary variables as loop counters

    char check[MAX_CHAR];

    // steps below same as readKeyboard above except the outer loop runs until the end of file

    while(!feof(fp)){
        inputFile(sArr[i].artiste, fp);
        inputFile(check, fp);
        int j=0;
        while(strstr(check, "***") != 0){
            strcpy(sArr[i].songs[j], check);
            if(feof(fp)) // break out of the inner loop when at end of file
                break;
            inputFile(check, fp);
            j++;
        }
        sArr[i].num_songs = j;
        i++;
    }
    artNum = i;
}


// function to get user input form the terminal without the newline character
void inputKey(char *str){

    fgets(str,MAX_CHAR,stdin); // read from the terminal
    // loop through all the characters in the string until newline is reached
    while(*str != '\n')
        str++; // increment the pointer
    *str = '\0'; // when newline is reached, change to null terminator
}


// function to read from a file without the newline character
void inputFile(char *str, FILE* fp){

    fgets(str,MAX_CHAR,fp); // read from the file
    // loop keeps running until inner if statement condition is met
    while(1){
        if(*str == '\n' || *str == '\0'){ // if character is newline or null character
            *str = '\0'; // set to the null character
            break; // break out of the while
        }
        str++; //increment the pointer
    }
}