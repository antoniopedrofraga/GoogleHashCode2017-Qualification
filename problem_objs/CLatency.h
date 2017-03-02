//
// Created by António Pedro Fraga on 27/02/2017.
//

#ifndef UNTITLED_CLATENCY_H
#define UNTITLED_CLATENCY_H


#include "Cache.h"

class CLatency {
private:
    Cache* cache;
    unsigned int latency;
    int time_to_save;
public:
    CLatency(Cache* c, unsigned int l, int t);
    unsigned int get_latency();
    Cache* get_cache();
    bool operator < (CLatency cache_latency) {
        return (time_to_save > cache_latency.time_to_save);
    }
};


#endif //UNTITLED_CLATENCY_H
