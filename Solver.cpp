//
// Created by António Pedro Fraga on 25/02/2017.
//

#include "Solver.h"

Solver::Solver(Parser* parser) : parser(parser) {
    solve();
    //write_solution();
}

void Solver::solve() {
    unsigned int number_of_caches = parser->get_c();
    unsigned int number_of_endpoints = parser->get_e();
    unsigned int number_of_videos = parser->get_v();
    unsigned int cache_capacity = parser->get_x();

    std::vector<unsigned int> video_sizes = parser->get_video_sizes(); //aka s
    unsigned int * video_latencies = parser->get_video_latencies(); //aka ld
    unsigned int * cache_latencies = parser->get_cache_latencies(); //aka lc (matrix)

    unsigned int * latencies_saved = (unsigned int *) malloc(number_of_caches * number_of_videos * sizeof(unsigned int)); //we want the maximum value in each row
    for (unsigned int i = 0; i < number_of_caches; i++) {
        
    }
}
