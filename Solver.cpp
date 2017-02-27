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

    Cache ** caches = parser->get_caches();
    std::vector<unsigned int> video_sizes = parser->get_video_sizes(); //aka s
    std::vector<Request> requests = *parser->get_requests();
    std::vector<Endpoint> endpoints = *parser->get_endpoints();

    
}


unsigned int Solver::update_array_sum(unsigned int * array, unsigned int size) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}
