//
// Created by Evan Chang on 2019-03-28.
//
#include "UtPod.h"
#include <ctime>
#include <cstdlib>


using namespace std;

    //Default constructor
    UtPod::UtPod(){
        songs = NULL;
        podMemSize = MAX_MEMORY;
    }

    //Constructor that takes in a size
    UtPod::UtPod(int size) {
        songs = NULL;
        if (size <= 0 || size > MAX_MEMORY) {
            podMemSize = MAX_MEMORY;
        }
        else{
            podMemSize = size;
        }
    }

    //Private helper method that determines how many songs are in the pod
    int UtPod::findLength(){

        int length = 0;
        SongNode *current = songs;
        //Loop through to get length
        while(current != NULL){
            length++;
            current = current->next;
        }
        return length;
    }

    //Prints out all songs in the pod
    void UtPod::showSongList() {

        SongNode *current = songs;

        //Loop through prints out songs with artist first, then title, then size
        while(current!= NULL){
            cout<< current->s.getTitle() <<", "<<current->s.getArtist()<<", "<<current->s.getSize()<<endl;
            current = current->next;
        }
    }

    //Removes the first instance of a song
    int UtPod::removeSong(Song const &s) {

        if(songs == NULL){
            return -1;
        }

        SongNode *current = songs;

        //Check edge case where the head should be removed
        if(current->s.operator==(s)){
            songs = songs->next;
            current->next = NULL;
            return SUCCESS;
        }

        //Loop through songs
        while(current->next != NULL){

            //Find Song to be removed
            if(current->next->s.operator==(s)){
                if(current->next->next == NULL){

                    current->next = NULL;
                    return SUCCESS;
                }

                //Remove node
                SongNode *temp = current->next->next;
                current->next->next = NULL;
                current->next = temp;
                return SUCCESS;
            }
            current = current->next;
        }
        return -1;
    }

    //Add song to the Linked List
    int UtPod::addSong(Song const &s) {
        if(getRemainingMemory() < s.getSize()){
            return NO_MEMORY;
        }

        //If pod is empty, add to the front
        SongNode *current = songs;
        if(songs == NULL){
            songs = new SongNode;
            songs->s = s;
            songs->next = NULL;
            return SUCCESS;
        }

        //Loop to end of songs to add to the end
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new SongNode;
        current->next->s = s;
        current->next->next = NULL;
        return SUCCESS;
    }

    //Shuffle all songs in the pod
    void UtPod::shuffle() {
        srand(time(0));

        //Go through pod 5*length times and randomly switch adjacent songs
        for(int i = 0; i<(findLength()*5);i++) {

            SongNode *current = songs;
            //Keep randomly switching until end of pod is reached
            while (current != NULL && current->next != NULL) {

                int random = rand() % 2;
                //50% chance that two adjacent songs are swapped
                if (random == 1) {
                    Song temp = current->next->s;
                    current->next->s = current->s;
                    current->s = temp;
                }
                current = current->next;
            }
        }
    }

    //Sorts the list of songs by artist, then title, then size
    void UtPod::sortSongList() {
        if(songs->next == NULL){
            return;
        }

        //Run a modified insertion sort
        for(int i=0; i < findLength(); i++){
            SongNode *current = songs;

            //If the current song is greater than the next one, swap them
            while(current != NULL && current->next != NULL){
                if(current->s > current->next->s){
                    Song temp = current->next->s;
                    current->next->s = current->s;
                    current->s = temp;
                }
                current = current->next;
            }
        }
    }

    //Deletes all songs from the pod
    void UtPod::clearMemory() {

        while(songs != NULL) {

            SongNode *current = songs;
            if (current->next == NULL) {
                songs = NULL;
                return;
            }
            //Go to the end of the list and delete one song at a time
            while (current->next->next != NULL) {
                current = current->next;
            }
            current->next = NULL;
        }
    }

    //Calculates how much memory is left
    int UtPod::getRemainingMemory() {
        int remainingMem = podMemSize;
        SongNode *current = songs;

        //Subtract all songs memory from the total possible
        while(current != NULL){
            remainingMem = remainingMem - current->s.getSize();
            current = current->next;
        }
        return remainingMem;
    }

    UtPod::~UtPod() {

        clearMemory();
    }
