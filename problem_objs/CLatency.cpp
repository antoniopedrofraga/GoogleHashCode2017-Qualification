//
// Created by António Pedro Fraga on 27/02/2017.
//

#include "CLatency.h"


CLatency::CLatency(unsigned int c, unsigned int l) {
    this->cache = c;
    this->latency = l;
}

unsigned int CLatency::get_latency() {
    return this->latency;
}