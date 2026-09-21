#ifndef STRATEGYMANAGERS_H
#define STRATEGYMANAGERS_H

#include <bits/stdc++.h>
#include "../Strategy/SequentialPlayStrategy.h"
#include "../Strategy/RandomPlayStrategy.h"
#include "../Strategy/PlayStrategy.h"

enum strategyType {
    RANDOM,
    SEQUENTIAL
};

class StrategyManagers {
    static class StrategyManagers *instance;
    class SequentialPlayStrategy *sps;
    class RandomPlayStrategy *rps;
    StrategyManagers(){
        sps = new SequentialPlayStrategy();
        rps = new RandomPlayStrategy();
    }
    public:
    static StrategyManagers* getInstance() {
        if(!instance) {
            instance = new StrategyManagers();
        }
        return instance;
    }

    PlayStrategy* getStrategy(strategyType st) {
        if(st == strategyType::RANDOM) {
            return rps;
        } else {
            return sps;
        }
    }
};

StrategyManagers* StrategyManagers::instance = NULL; 

#endif