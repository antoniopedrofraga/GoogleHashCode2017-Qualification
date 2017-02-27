//
// Created by António Pedro Fraga on 27/02/2017.
//

#include <vector>
#include <algorithm>
#include "Endpoint.h"

Endpoint::Endpoint(unsigned int i, unsigned int ld, std::vector<CLatency> * lc) {
    this->index = i;
    this->latency_to_datacenter = ld;
    std::sort(lc->begin(), lc->end());
    this->latencies_to_cache_server = lc;
}

unsigned int Endpoint::get_index() {
    return this->index;
}

std::vector<CLatency> * Endpoint::get_latencies_to_cache() {
    return this->latencies_to_cache_server;
}
