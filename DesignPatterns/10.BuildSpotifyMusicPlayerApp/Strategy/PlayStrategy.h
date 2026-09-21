#ifndef PLAYSTRATEGY_H
#define PLAYSTRATEGY_H

#include <bits/stdc++.h>
#include "../models/Song.h"
#include "../models/Playlist.h"

using namespace std;

class PlayStrategy {
    public:
    virtual void setPlaylist(Playlist *pl) = 0;
    virtual Song* next() = 0;
    virtual bool hasNext() = 0;
    virtual Song* previous() = 0;
    virtual bool hasPrevious() = 0;
    virtual void addToNext(Song *song) {};
};

#endif