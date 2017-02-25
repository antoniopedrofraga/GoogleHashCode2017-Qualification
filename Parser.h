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
    std::vector<unsigned int> requested_videos; //the ID of the requested videos aka rv
    std::vector<unsigned int> request_endpoints; //the ID of the endpoint from which the request is coming aka re
    std::vector<unsigned int> requests_number; //number of requests aka rn
public:
    Parser(std::string filename);
    void open_file();
    void parse_first_line();
    void parse_sizes_line();
    void parse_endpoints();
    void parse_requests();

    void split(std::string &line, std::vector<unsigned int> &numbers, char character);
};


#endif //UNTITLED_PARSER_H
