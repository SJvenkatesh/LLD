#ifndef PLAYLISTMANAGERS_H
#define PLAYLISTMANAGERS_H

#include "bits/stdc++.h"
#include "../models/Playlist.h"

using namespace std;

class PlaylistManagers {
    static PlaylistManagers *instance;
    PlaylistManagers() {
        cout<<"Playlist Managers "<<endl;
    }
    public:
    unordered_map<string, Playlist*> playlist;
    static PlaylistManagers* getInstance() {
        if(!instance){
            return instance = new PlaylistManagers();
        }
        return instance;
    }

    Playlist* getPlaylist(string name) {
        return playlist[name];
    }

    void addPlaylist(string name, Playlist *pl){
        playlist[name] = pl;
    }
};

PlaylistManagers* PlaylistManagers::instance = NULL;

#endif