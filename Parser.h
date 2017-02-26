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
    unsigned int * video_latencies; //video latencies from each end point aka ld
    unsigned int * cache_latencies; //video latencies from each cache server to each end point aka lc (matrix)

    unsigned int * request_endpoints; //the ID of the endpoint from which the request is coming aka re
    unsigned int * requests_number; //number of requests aka rn

    void open_file();
    void parse_first_line();
    void parse_sizes_line();
    void parse_endpoints();
    void parse_requests();

    void split(std::string &line, std::vector<unsigned int> &numbers, char character);
public:
    Parser(std::string filename);

    unsigned int get_c();
    unsigned int get_e();
    unsigned int get_x();
    unsigned int get_v();

    std::vector<unsigned int> get_video_sizes();
    unsigned int * get_cache_latencies();
    unsigned int * get_video_latencies();
};


#endif
