//
// Created by António Pedro Fraga on 27/02/2017.
//

#include "Request.h"

Request::Request(unsigned int v, Endpoint * e, unsigned int r, unsigned int size) : endpoint(e) {
    this->video_id = v;
    this->number_of_requests = r;
    this->size = size;
}

unsigned int Request::get_number_of_requests() {
    return this->number_of_requests;
}

Endpoint * Request::get_endpoint() {
    return this->endpoint;
}

unsigned int Request::get_video_id() {
    return this->video_id;
}

double Request::get_score() {
    double latency_to_datacenter = this->endpoint->get_latency_to_datacenter();
    std::vector<CLatency> * latencies_to_cache = this->endpoint->get_latencies_to_cache();
    for (unsigned int i = 0; i < latencies_to_cache->size(); i++) {
        Cache * cache = (*latencies_to_cache)[i].get_cache();
        if (size <= cache->get_free_space()) {
            return ((double) latency_to_datacenter - (double) (*latencies_to_cache)[i].get_latency()) / (double) this->size;
        }
    }
}