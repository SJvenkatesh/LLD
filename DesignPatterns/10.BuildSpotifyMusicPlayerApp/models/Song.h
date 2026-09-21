#ifndef SONG_H
#define SONG_H

#include "bits/stdc++.h"

using namespace std;

class Song {
    public:
    string title;
    string artist;
    Song(string title, string artist) {
        this->title = title;
        this->artist = artist;
    }
    string getTitle() {
        return title;
    }
};

#endif