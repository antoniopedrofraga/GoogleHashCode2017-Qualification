//
// Created by António Pedro Fraga on 25/02/2017.
//

#ifndef SOLVER_H
#define SOLVER_H


#include "Parser.h"

class Solver {
    Parser* parser;
public:
    Solver(Parser* parser);
    void solve();
    void place_video(unsigned int video_id, Endpoint endpoint);
    unsigned int update_array_sum(unsigned int * array, unsigned int size);

};


#endif
