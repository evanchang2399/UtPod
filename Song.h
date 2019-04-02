//
// Created by Evan Chang on 2019-03-28.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>
#include <iostream>


using namespace std;

class Song{

    //Instance variables
    private:
        string title;
        string artist;
        int size;

    //Public constructors and methods
    public:
		  //Default constructor
        Song();

		  //Constructor with all info given
        Song(string artist, string title, int size);

		  //Basic accessor methods that return instance variables
        string getTitle() const;
        string getArtist() const;
        int getSize() const;

		  //Basic setters that change instance variables
        void setTitle(string newTitle);
        void setArtist(string newArtist);
        void setSize(int newSize);

		  //Overloaded operators that allow for Song comparison
        bool operator ==(Song const &other);

        bool operator <(Song const &other);

        bool operator >(Song const &other);


};

#endif //UTPOD_SONG_H
