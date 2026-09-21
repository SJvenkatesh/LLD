#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "bits/stdc++.h"
#include "./Song.h"

using namespace std;

class Playlist {
    public:
    string name;
    vector<Song*> songs;
    vector<Song*> getSongs(){
        return songs;
    }
    void addSong(Song *song){
        songs.push_back(song);
    }
};

#endif