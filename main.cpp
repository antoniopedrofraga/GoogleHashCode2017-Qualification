//
// Created by António Pedro Fraga on 25/02/2017.
//
#include <iostream>
#include "Parser.h"
#include "Solver.h"

int main() {
    Parser* parser = new Parser("..\\input files\\me_at_the_zoo.in");
    Solver* solver = new Solver(parser);
}
