#ifndef WIREDSPEAKER_H
#define WIREDSPEAKER_H

#include "bits/stdc++.h"
#include "./IOutputDevice.h"
#include "../models/Song.h"
#include "../models/WiredSpeakerApi.h"

using namespace std;

class WiredSpeaker : public IOutputDevice {
    class WiredSpeakerApi *wsa;
    public:
    WiredSpeaker(){
        wsa = new WiredSpeakerApi();
    }
    void playAudio(Song *song) override {
        wsa->connectWiredSpeakerApi();
    };
};

#endif