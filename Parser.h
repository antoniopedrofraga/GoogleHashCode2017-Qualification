//
// Created by António Pedro Fraga on 25/02/2017.
//

#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

class Parser {
private:
    std::string filename;
    std::ifstream file;

    unsigned int v;
    unsigned int e;
    unsigned int r;
    unsigned int c;
    unsigned int x;

    std::vector<unsigned int> video_sizes;
    std::vector<unsigned int> video_latencies; //video latencies from each end point aka ld

    unsigned int * cache_latencies; //video latencies from each cache server to each end point aka lc
public:
    Parser(std::string filename);
    void open_file();
    void parse_first_line();
    void parse_sizes_line();
    void parse_endpoints();
    void parse_rlines();

    void split(std::string &line, std::vector<unsigned int> &numbers, char character);
};


#endif //UNTITLED_PARSER_H
