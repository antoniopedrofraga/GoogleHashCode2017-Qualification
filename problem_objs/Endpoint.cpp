//
// Created by António Pedro Fraga on 27/02/2017.
//

#include <vector>
#include <algorithm>
#include "Endpoint.h"

Endpoint::Endpoint(unsigned int ld, std::vector<CLatency> * lc) {
    this->latency_to_datacenter = ld;
    std::sort(lc->begin(), lc->end());
    this->latencies_to_cache_server = lc;
}