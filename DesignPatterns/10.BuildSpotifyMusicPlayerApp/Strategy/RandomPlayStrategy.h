#ifndef RANDOMPLAYSTRATEGY_H
#define RANDOMPLAYSTRATEGY_H

#include <bits/stdc++.h>
#include "./PlayStrategy.h"
#include "../models/Song.h"

using namespace std;

class RandomPlayStrategy : public PlayStrategy {
    Playlist *pl;
    int index;
    public:
    void setPlaylist(Playlist *pl) {
        this->pl = pl;
        index = -1;
    }

    Song* next() override {
        Song *nS = new Song("nextRandomSong", "nextRandomSongArtist");
        return nS;
    }
    bool hasNext() override {
        return true;
    }

    Song* previous() override {
        Song *pS = new Song("prevRandomSong", "prevRandomSongArtist");
        return pS;
    }
    bool hasPrevious() override {
        return true;
    }
};

#endif