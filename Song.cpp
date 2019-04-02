//
// Created by Evan Chang on 2019-03-28.
//
#include "Song.h"
using namespace std;

//Default constructor
Song::Song() {
    title = "";
    artist = "";
    size = 0;
}

//Constructor with all variables
Song::Song(string artist, string title, int size) {
    this->title = title;
    this->artist = artist;
    this->size = size;
}

//Next three methods are all basic getters
string Song::getTitle() const{
    return title;
}

string Song::getArtist() const{
    return artist;
}

int Song::getSize() const{
    return size;
}

//Next three methods are all setters
void Song::setTitle(string newTitle){
    title = newTitle;
}

void Song::setArtist(string newArtist) {
    artist = newArtist;
}

void Song::setSize(int newSize){
    size = newSize;
}

//Overridden == method for Songs
bool Song::operator ==(Song const &other){

    if(title != other.title){
        return false;
    }
    if(artist != other.artist){
        return false;
    }
    if (size != other.size){
        return false;
    }
    return true;
}

//Overridden < method for Songs
bool Song::operator <(Song const &other) {

    if (this->artist < other.artist) {
        return true;
    }
    else if (this->artist > other.artist) {
        return false;
    }

    if (this->title < other.title){
        return true;
    }
    else if(this->title > other.title){
        return false;
    }

    return (this->size < other.size);
}

//Overridden > method for Songs
bool Song::operator >(Song const &other) {

    if (this->artist > other.artist) {
        return true;
    }
    else if (this->artist < other.artist) {
        return false;
    }

    if (this->title > other.title){
        return true;
    }
    else if(this->title < other.title){
        return false;
    }

    return (this->size > other.size);
}
