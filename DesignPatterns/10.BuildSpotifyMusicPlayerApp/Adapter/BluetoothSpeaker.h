#ifndef BLUETOOTHSPEAKER_H
#define BLUETOOTHSPEAKER_H

#include "bits/stdc++.h"
#include "./IOutputDevice.h"
#include "../models/Song.h"
#include "../models/BluetoothSpeakerApi.h"

using namespace std;

class BluetoothSpeaker : public IOutputDevice {
    class BluetoothSpeakerApi *bsa;
    public:
    BluetoothSpeaker(){
        bsa = new BluetoothSpeakerApi();
    }
    void playAudio(Song *song) override {
        bsa->connectBluetoothSpeaker();
    };
};


#endif