//
// Created by António Pedro Fraga on 27/02/2017.
//

#include "CLatency.h"


CLatency::CLatency(Cache * cache, unsigned int latency, int time_to_save) {
    this->cache = cache;
    this->latency = latency;
    this->time_to_save = time_to_save;
}

Cache* CLatency::get_cache() {
    return this->cache;
}

unsigned int CLatency::get_latency() {
    return this->latency;
}