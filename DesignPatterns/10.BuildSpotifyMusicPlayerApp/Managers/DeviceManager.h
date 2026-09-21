#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "bits/stdc++.h"
#include "../Adapter/IOutputDevice.h"
#include "../models/Song.h"
#include "../Adapter/WiredSpeaker.h"
#include "../Adapter/BluetoothSpeaker.h"

using namespace std;

enum DeviceType {
    WIRED,
    BLUETOOTH
};

class DeviceManager {
    class IOutputDevice *iod;
    public:
    DeviceManager(DeviceType dt) {
        if(dt == WIRED){
            iod = new WiredSpeaker();
        } else {
            iod = new BluetoothSpeaker();
        }
    }
    void playAudio(Song *song) {
        iod->playAudio(song);
    }
};

#endif