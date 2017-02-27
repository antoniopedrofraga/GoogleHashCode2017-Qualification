//
// Created by António Pedro Fraga on 25/02/2017.
//

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "problem_objs/Endpoint.h"
#include "problem_objs/Request.h"
#include "problem_objs/Cache.h"

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
    std::vector<Endpoint> * endpoints;
    std::vector<Request> * requests;
    std::vector<Cache*> * caches;

    void open_file();
    void parse_first_line();
    void parse_sizes();
    void parse_endpoints();
    void parse_requests();

    void split(std::string &line, std::vector<unsigned int> &numbers, char character);
public:
    Parser(std::string filename);

    unsigned int get_r();

    std::vector<Cache*> * get_caches();
    std::vector<unsigned int> get_video_sizes();
    std::vector<Request> * get_requests();
    std::vector<Endpoint> * get_endpoints();
};


#endif
