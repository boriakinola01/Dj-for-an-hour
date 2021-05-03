//
// Created by Bori Akinola on 17/03/2021.
//

#ifndef ASS1_USERINPUT_H
#define ASS1_USERINPUT_H

#include <stdio.h>

// set the maximum number of lines that the user can enter to 120
//#define MAX_LINES 120

// set the maximum number of characters that each line can be to 50
#define MAX_CHAR 50

// set the maximum number of artistes to be 10
#define MAX_ARTISTES 10

// set the maximum number of sings that an artiste can have be 10
#define MAX_SONGS 10

// the maximum number of songs possible is now 100
#define TOTAL_SONGS 100

// declare a struct that has three variables in it:

struct profile{
    // - a string to hold the artiste name
    char artiste[MAX_CHAR];

    // - an integer to hold the number of songs that the artiste has
    int num_songs;

    // - a 2d array to hold the songs of each artiste
    char songs[MAX_SONGS][MAX_CHAR];
};


// global variable to hold the number of artistes
int artNum;

#endif //ASS1_USERINPUT_H

void readKeyboard(struct profile sArr[]);

void readFile(FILE* fp, struct profile sArr[]);

void inputKey(char *str);

void inputFile(char *str, FILE* fp);

void initialiseProfile(struct profile sArr[]);