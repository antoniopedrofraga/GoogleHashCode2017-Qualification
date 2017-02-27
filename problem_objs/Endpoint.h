//
// Created by António Pedro Fraga on 27/02/2017.
//

#ifndef UNTITLED_ENDPOINT_H
#define UNTITLED_ENDPOINT_H


#include "CLatency.h"
#include <vector>

class Endpoint {
private:
    unsigned int index;
    unsigned int latency_to_datacenter;
    std::vector<CLatency>* latencies_to_cache_server;
public:
    Endpoint(unsigned int i, unsigned int ld, std::vector<CLatency> * lc);
    unsigned int get_index();
    std::vector<CLatency>* get_latencies_to_cache();
};


#endif //UNTITLED_ENDPOINT_H
