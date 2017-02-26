//
// Created by António Pedro Fraga on 25/02/2017.
//

#ifndef UNTITLED_SOLVER_H
#define UNTITLED_SOLVER_H


#include "Parser.h"

class Solver {
    Parser* parser;
public:
    Solver(Parser* parser);
    void solve();
};


#endif //UNTITLED_SOLVER_H
