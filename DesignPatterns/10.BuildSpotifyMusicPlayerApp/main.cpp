#include <bits/stdc++.h>

using namespace std;

#include "./models/Playlist.h"
#include "./models/Song.h"
#include "./Managers/PlaylistManagers.h"
#include "./Managers/DeviceManager.h"
#include "./models/AudioEngine.h"
#include "./Adapter/WiredSpeaker.h"
#include "./Managers/StrategyManagers.h"
#include "./Strategy/SequentialPlayStrategy.h"
#include "./Strategy/RandomPlayStrategy.h"
#include "./Strategy/PlayStrategy.h"

int main() {
    class Playlist *pl = new Playlist(); 
    class Song *s1 = new Song("s1", "a1");
    class Song *s2 = new Song("s2", "a2");
    class Song *s3 = new Song("s3", "a3");
    class Song *s4 = new Song("s4", "a4");
    pl->addSong(s1);
    pl->addSong(s2);
    pl->addSong(s3);
    pl->addSong(s4);
    auto songs = pl->getSongs();
    for(auto song : songs) {
        cout<<"Name of song : "<<song->title<<endl;
    }
    PlaylistManagers *pm = PlaylistManagers::getInstance();
    pm->addPlaylist("pl1", pl);

    class Playlist *fpl = pm->getPlaylist("pl1");

    auto fetchedSongs = fpl->getSongs();

    for(auto song : fetchedSongs) {
        cout<<"Name of fetched song : "<<song->title<<endl;
    }


    class DeviceManager *dm = new DeviceManager(WIRED);
    dm->playAudio(s1);

    class AudioEngine *ae = new AudioEngine();
    class IOutputDevice *iod = new WiredSpeaker();

    ae->play(iod, s1);
    
    class StrategyManagers *sm = StrategyManagers::getInstance();
    PlayStrategy* ps = sm->getStrategy(strategyType::RANDOM);
    ps->setPlaylist(fpl);
    Song *ssm = ps->next();
    cout<<ssm->getTitle()<<endl;

    
    return 0;
}