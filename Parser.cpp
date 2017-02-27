//
// Created by António Pedro Fraga on 25/02/2017.
//

#include "Parser.h"
#include <time.h>

Parser::Parser(std::string filename) {
    this->filename = filename;
    this->requests = new std::vector<Request>();
    this->endpoints = new std::vector<Endpoint>();
    this->caches = new std::vector<Cache*>();
    this->open_file();
}

void Parser::open_file() {
    this->file.open(filename);
    if (this->file.is_open()) {
        clock_t start_time, end_time;
        char reading_time[100];
        start_time = clock();

        this->parse_first_line();
        this->parse_sizes();
        this->parse_endpoints();
        this->parse_requests();

        end_time = clock();
        sprintf(reading_time, "Reading time: %3.3f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
        std::cout << reading_time << std::endl;
    } else {
        std::cout << "File is closed" << std::endl;
    }
}

void Parser::parse_first_line() {
    std::string line;
    std::getline(this->file, line);
    std::istringstream iss(line);

    iss >> this->v >> this->e >> this->r >> this->c >> this->x;
    for (unsigned int i = 0; i < this-> c; i++) {
        this->caches->push_back(new Cache(this->x));
    }
}

void Parser::parse_sizes() {
    std::string line;
    std::getline(this->file, line);
    this->split(line, this->video_sizes, ' ');
}

void Parser::parse_endpoints() {
    std::string line;
    for (unsigned int i = 0; i < this->e; i++) {
        std::getline(this->file, line);
        std::vector<unsigned int> ldk;
        split(line, ldk, ' ');

        unsigned int latency = ldk[0];
        unsigned int k = ldk[1];

        std::vector<CLatency>* cache_latencies = new std::vector<CLatency>();
        for (unsigned int j = 0; j < k; j++) {
            std::getline(this->file, line);
            std::vector<unsigned int> clc;
            split(line, clc, ' ');
            cache_latencies->push_back(*(new CLatency(clc[0], clc[1])));
        }
        this->endpoints->push_back(*(new Endpoint(i, latency, cache_latencies)));
    }
}

void Parser::parse_requests() {
    std::string line;
    for (unsigned int i = 0; i < this->r; i++) {
        std::getline(this->file, line);
        std::vector<unsigned int> rs;
        split(line, rs, ' ');

        this->requests->push_back(*(new Request(rs[0], &((*endpoints)[rs[1]]), rs[2])));
    }
    std::sort(this->requests->begin(), this->requests->end());
}


void Parser::split(std::string &line, std::vector<unsigned int> &numbers, char character) {
    unsigned int pos = line.find(character);
    unsigned int initial_pos = 0;
    numbers.clear();
    while(pos != std::string::npos) {
        numbers.push_back((unsigned int)atoll(line.substr(initial_pos, pos - initial_pos).c_str()));
        initial_pos = pos + 1;
        pos = line.find(character, initial_pos);
    }
    numbers.push_back((unsigned int)atoll(line.substr(initial_pos, std::min(pos, line.size()) - initial_pos).c_str()));
}

unsigned int Parser::get_r() {
    return this->r;
}

std::vector<Cache*> * Parser::get_caches() {
    return this->caches;
}

std::vector<unsigned int> Parser::get_video_sizes() {
    return this->video_sizes;
}

std::vector<Request> * Parser::get_requests(){
    return this->requests;
}

std::vector<Endpoint> * Parser::get_endpoints(){
    return this->endpoints;
}
