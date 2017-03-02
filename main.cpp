//
// Created by António Pedro Fraga on 25/02/2017.
//
#include <iostream>
#include "Parser.h"
#include "Solver.h"

int main() {
    std::cout << std::endl;
    std::string filenames[4] = {"me_at_the_zoo", "videos_worth_spreading", "trending_today", "kittens"};
    for (unsigned int i = 0; i < 4; i++) {
        std::cout << "File: " << filenames[i] << std::endl;
        Parser *parser = new Parser("..\\input files\\" + filenames[i] + ".in");
        new Solver("..\\output files\\" + filenames[i] + ".out", parser);
    }
}