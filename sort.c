//
// Created by Bori Akinola on 15/03/2021.
//

#include "sort.h"

#include <string.h>


// function to sort the array of structs of type profile by artistes
void sortArtistes(struct profile arr[]){

    int i, j;
    struct profile current;

    for (i = 0;  i < artNum; i++){
        j = i-1;
        current = arr[i];

        while (j >= 0 && strcmp(current.artiste,arr[j].artiste)<0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

// function to sort the songs of each artistes in the
// array of structs of type profile
void sortSongs(struct profile arr[]){
    int i, j;
    char current[MAX_CHAR];

    for(int k=0; k < artNum; k++ ){
        for (i = 0;  i < arr[k].num_songs;  i++){
            j = i-1;
            strcpy(current,arr[k].songs[i]);

            while (j >= 0 && strcmp(current,arr[k].songs[j])<0)
            {
                strcpy(arr[k].songs[j+1],arr[k].songs[j]);
                j--;
            }
            strcpy(arr[k].songs[j+1],current);
        }
    }
}

// function to print the sorted array of structs of type profile
void printSorted(struct profile sArr[]){

    printf("The sorted list of artistes and songs: \n");
    for(int i=0; i< artNum; i++){
        printf("%s\n", sArr[i].artiste);
        for (int j=0; j<sArr[i].num_songs; j++){
            printf(" º%s\n", sArr[i].songs[j]);
        }
        printf("\n");
    }
}