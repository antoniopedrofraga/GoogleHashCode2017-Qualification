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
public:
    Solver(std::string output, Parser* parser);
    unsigned int update_array_sum(unsigned int * array, unsigned int size);

};


#endif
