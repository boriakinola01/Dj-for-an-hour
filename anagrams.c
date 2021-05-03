//
// Created by Bori Akinola on 21/02/2021.
//

#include "anagrams.h"
#include "userInput.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
 * function to fill an array of structs of type songL (which holds all the songs
 * in the playlist) from an array of structs of type profiles
 *
 */
void songFill(struct profile sArr[], struct songL songLi[]){
    // declare necessary variables
    int k = 0;
    size = 0;
    const char delim[] = "***";
    char copy[MAX_CHAR];
    char *token;

    // loop until the artistes in the playlist
    for(int i=0; i < artNum; i++){
        // loop through the songs of each artiste
        for (int j = 0; j < sArr[i].num_songs; j++){

            // create a copy of each song
            strcpy(copy, sArr[i].songs[j]);

            // tokenise the copy and extract the necessary tokens
            token = strtok(copy, delim);
            strcpy(songLi[k].songName, token);

            token = strtok(NULL, "***:");
            // convert the minutes from a string to an integer
            songLi[k].min = atoi(token);

            token = strtok(NULL, ":");
            // convert the seconds from a string to an integer
            songLi[k].secs = atoi(token);

            songLi[k].total = songLi[k].secs + (60*songLi[k].min);
            songLi[k].artId = i; // set the artId to the artiste  position in the profile array
            k++; // increment the counter
        }
    }
    size = k; // set the size to the value of k. Which is the total number of songs present
}

// function to initialise the struct type songL
void initialiseList(struct songL songList[]){
    for(int i = 0; i < TOTAL_SONGS; i++){
        strcpy(songList[i].songName," ");
        songList[i].artId = 0;
        songList[i].secs = 0;
        songList[i].min = 0;
    }
}

/*
 * function to create a randomised playlist that meets the following requirements:
 *  --> an artiste cannot have more than 3 songs in the playlist
 *  --> an artiste cannot have more than 2 songs in a row
 *  --> a song cannot appear twice in the playlist
 *  --> the total length of the playlist should be aas close to one hour
 *      possible with the last song starting on or before 59:59
 */
void randomised(struct profile sArr[], struct songL songList[]){

    // declare necessary variables
    int sum = 0;
    int i;
    int k=0;
    size_t arr[artNum]; // an array the size of the number of artistes present
    size_t arr2[size]; // an array the size of the number of songs present
    struct songL song[size]; // an array of structs of type songL to hold the created randomised playlist

    // initialise the array of structs
    for(int j = 0; j < size; j++){
        strcpy(song[j].songName," ");
        song[j].artId = 0;
        song[j].secs = 0;
        song[j].min = 0;
    }

    /* set every value in the number of artistes array to 3
    * this will ensure we do not have more than 3 songs for each artiste
    * in the playlist
    */
    for(int j = 0; j < artNum; j++){
        arr[j] = 3;
    }

    /*
     * Set every value in the song array to be a 1. This will ensure that
     * no song appears more than once in the playlist
     */
    for(int j = 0;j < size; j++){
        arr2[j] = 1;
    }

    srand(time(NULL)); // seed the random number generator

    printf("Randomised playlist: \n\n");

    /*
     * generate a new number (which corresponds to the position of the song
     * in the global array of structs of type songL) each time the while loop
     * runs until the total duration of the songs is greater than or equal to 3599 seconds
     * which is 59:59
     */
    while(sum <= 3599) {
        i = rand() % (size - 1);
        // if statement checks if the artiste has more than 3 songs already
        // generated and if the song itself has already been generated
        if(arr[songList[i].artId]>0 && arr2[i]>0){
            sum = songList[i].total + sum; // keep a running sum of the duration
            song[k] = songList[i];
            // decrement the value in both the song array and the artiste array
            arr[songList[i].artId]--;
            arr2[i]--;
            k++; // increment the counter to the next song
        }
    } // playlist already created with 3/4 of the criteria met

    // check if the playlist has 3 songs by the same artiste in a row
    // if so , shuffle the playlist
    while(check(song, k)){
        shuffle(song, k);
    }

    // playlist meets all criteria now

    // print out playlist
    for (int j=0; j < k;j++){
        if(song[j].artId > 0){
            printf("%s: \"%s\" (%d:%02d)\n", sArr[song[j].artId].artiste, song[j].songName,
                   song[j].min, song[j].secs);
        }
    }

    // print out total duration
    printf("\nTotal duration: %d minutes %02d seconds\n", sum/60, sum%60);
}

// function to check if the array of structs songL have songs from the same
// artiste occurring three ties in a row
bool check(struct songL songList[], int n){
    int a, b, c;
    for(int i=1; i < n-1; i++){
        a = songList[i].artId;
        b = songList[i-1].artId;
        c = songList[i+1].artId;

        if(a==b && b==c && a==c){
            return true;
        }
    }

    return false;
}

// function to shuffle an array of structs of type songL
void shuffle(struct songL songList[], int n){
    struct songL tmp;
    int j;
    for(int i = n-1; i > 0; i--){
        j = rand() % (i + 1);

        tmp = songList[i];
        songList[i] = songList[j];
        songList[j] = tmp;
    }
}