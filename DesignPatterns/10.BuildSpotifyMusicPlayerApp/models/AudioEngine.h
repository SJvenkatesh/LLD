#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include "./Song.h"
#include "../Adapter/IOutputDevice.h"

class AudioEngine {
    public:
    void play(IOutputDevice *iod, Song *song){
        cout<<" Audio Engine : "<<endl;
        iod->playAudio(song);
    }
};

#endif