//
// Created by António Pedro Fraga on 25/02/2017.
//
#include <iostream>
#include "Parser.h"
#include "Solver.h"

int main() {
    std::string filename = "kittens";
    Parser* parser = new Parser("..\\input files\\" + filename + ".in");
    Solver* solver = new Solver("..\\output files\\" + filename + ".out", parser);
}
