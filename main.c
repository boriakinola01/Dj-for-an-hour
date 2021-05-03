/*
 * Software Engineering project 1
 * Author: Toluwabori Akinola
 *         20720321
 *         University College Dublin
 */

#include <stdio.h>
#include "userInput.h"
#include "anagrams.h"
#include "sort.h"

int main(int argc, char*argv[]){

    // create an array of structs of type profile
    struct profile Array[MAX_ARTISTES];
    // initialise the struct array
    initialiseProfile(Array);

    // create an array of structs of type songL
    struct songL songList[TOTAL_SONGS];
    // initialise the struct array
    initialiseList(songList);

    FILE *fp; // declare a pointer to the file

    if(argc > 1){
        // if file specified as argument doesn't exist or cannot be
        // accessed for reading
        if((fp =fopen(argv[1], "r")) == NULL){
            // prompt the user
            printf("%s cannot be accessed for reading or does not exist\n", argv[1]);
            return 1;
        } else{ // but if the file specified as an argument
            // read from the file into the struct array
            readFile(fp, Array);
            fclose(fp); // close the file
        }
    } else { // if no argument specified to the program
        // check if the file exists in current directory, if it doesn't
        // call the readKeyboard function
        if((fp=fopen("artistes+songs.txt", "r")) == NULL){
            readKeyboard(Array);
        } else { // else if the file exists in the directory,
                 // read from the file into the array of structs
            readFile(fp, Array);
            fclose(fp); // close the file
        }
    }

    // sort the artistes
    sortArtistes(Array);

    // sort the songs for each artistes
    sortSongs(Array);

    // fill songList from Array
    songFill(Array, songList);

    // print the sorted list of songs and artistes
    printSorted(Array);

    // shuffle the randomised playlist and priint it out
    randomised(Array, songList);

    return 0;
}