//
// Created by António Pedro Fraga on 25/02/2017.
//

#include "Solver.h"

Solver::Solver(Parser* parser) : parser(parser) {
    solve();
    //write_output();
}

void Solver::solve() {
    unsigned int number_of_caches = parser->get_c();
    unsigned int number_of_endpoints = parser->get_e();
    unsigned int number_of_videos = parser->get_v();
    unsigned int number_of_requests = parser->get_r();
    unsigned int cache_capacity = parser->get_x();

    std::vector<Request> requests = *parser->get_requests();
    std::vector<Endpoint> endpoints = *parser->get_endpoints();

    for (unsigned int i = 0; i < number_of_requests; i++) {
        Endpoint * e = requests[i].get_endpoint();
        unsigned int video_id = requests[i].get_video_id();
        //this->place_video(video_id, *e);
    }
    Cache ** caches = parser->get_caches();
    for (unsigned int i = 0; i < number_of_caches; i++) {
        //std::cout << (*caches)[i].get_capacity() << std::endl;
    }
}

void Solver::place_video(unsigned int video_id, Endpoint endpoint) {

    std::vector<unsigned int> video_sizes = parser->get_video_sizes();
    unsigned int size = video_sizes[video_id];
    std::vector<CLatency> latencies_to_cache = *endpoint.get_latencies_to_cache();
    Cache ** caches = parser->get_caches();

    for (unsigned int i = 0; i < latencies_to_cache.size(); i++) {
        unsigned int cache_id = latencies_to_cache[i].get_cache_id();
        unsigned int capacity = (*caches)[cache_id].get_capacity();
        unsigned int used_capacity = (*caches)[cache_id].get_used_capacity();
        if (capacity >= used_capacity + size) {
            (*caches)[cache_id].place_video(video_id, size);
        }
    }
}

