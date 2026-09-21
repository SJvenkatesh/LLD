#ifndef SEQUENTIALPLAYSTRATEGY_H
#define SEQUENTIALPLAYSTRATEGY_H

#include <bits/stdc++.h>
#include "./PlayStrategy.h"
#include "../models/Song.h"

using namespace std;

class SequentialPlayStrategy : public PlayStrategy {
    Playlist *pl;
    int index;
    public:
    void setPlaylist(Playlist *pl) {
        this->pl = pl;
        index = -1;
    }

    Song* next() override {
        Song *nS = new Song("nextSong", "nextSongArtist");
        return nS;
    }
    bool hasNext() override {
        return true;
    }

    Song* previous() override {
        Song *pS = new Song("prevSong", "prevSongArtist");
        return pS;
    }
    bool hasPrevious() override {
        return true;
    }
};

#endif