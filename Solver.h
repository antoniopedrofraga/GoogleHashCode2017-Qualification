//
// Created by António Pedro Fraga on 25/02/2017.
//

#ifndef SOLVER_H
#define SOLVER_H


#include "Parser.h"

class Solver {
    std::string output;
    Parser* parser;
    void solve();
    void place_video(std::vector<Cache*> * caches, unsigned int video_id, Endpoint endpoint);
    void write_output();
    std::vector<Request> knapsack(int capacity, std::vector<unsigned int> video_sizes, std::vector<Request> requests, int number_of_items);
    unsigned int sum_of_requests(std::vector<Request> requests);
public:
    Solver(std::string output, Parser* parser);

};


#endif
