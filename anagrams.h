//
// Created by Bori Akinola on 17/03/2021.
//

#ifndef ASS1_ANAGRAMS_H
#define ASS1_ANAGRAMS_H

#include <stdbool.h>
#include "userInput.h"

// declare a struct of type songL
struct songL{
    // variable to hold the name of the song
    char songName[MAX_CHAR];
    // variable to hold the artiste Id
    int artId;
    // variable to hold the number of minutes in the song
    int min;
    // variable to hold the number of seconds in the song
    int secs;
    // variable to hold the total number of seconds in the song
    int total;
};

// global variable to hold the number of total songs
int size;

#endif //ASS1_ANAGRAMS_H


void songFill(struct profile sArr[], struct songL songList[]);

void randomised(struct profile sArr[], struct songL songList[]);

void initialiseList(struct songL songList[]);

bool check(struct songL songList[], int n);

void shuffle(struct songL songList[], int n);
