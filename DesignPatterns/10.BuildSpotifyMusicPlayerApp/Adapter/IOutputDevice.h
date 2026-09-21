#ifndef IOUTPUTDEVICE_H
#define IOUTPUTDEVICE_H

#include "bits/stdc++.h"
#include "../models/Song.h"

using namespace std;

class IOutputDevice {
    public:
    void virtual playAudio(Song *song)=0;
};

#endif