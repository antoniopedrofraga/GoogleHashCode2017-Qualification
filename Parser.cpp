//
// Created by António Pedro Fraga on 25/02/2017.
//

#include "Parser.h"
#include <time.h>

Parser::Parser(std::string filename) {
    this->filename = filename;
    this->open_file();
}

void Parser::open_file() {
    this->file.open(filename);
    if (this->file.is_open()) {
        clock_t start_time, end_time;
        char reading_time[100];
        start_time = clock();

        this->parse_first_line();
        this->parse_sizes_line();
        this->parse_endpoints();
        this->parse_requests();

        end_time = clock();
        sprintf(reading_time, "Time of reading: %3.5f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
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
    this->video_latencies = (unsigned int *)malloc((this->v) * sizeof(unsigned int));
    this->cache_latencies = (unsigned int *)malloc((this->c * this->e) * sizeof(unsigned int));

    this->request_endpoints = (unsigned int *)malloc(this->v * sizeof(unsigned int));
    this->requests_number = (unsigned int *)malloc(this->v * sizeof(unsigned int));
}

void Parser::parse_sizes_line() {
    std::string line;
    std::getline(this->file, line);
    this->split(line, this->video_sizes, ' ');
}

void Parser::parse_endpoints() {
    std::string line;
    for (unsigned int i = 0; i < this->c; i++) {
        std::getline(this->file, line);
        std::vector<unsigned int> ldk;
        split(line, ldk, ' ');
        this->video_latencies[i] = ldk[0];
        unsigned int k = ldk[1];

        for (unsigned int j = 0; j < k; j++) {
            std::getline(this->file, line);
            std::vector<unsigned int> clc;
            split(line, clc, ' ');
            this->cache_latencies[clc[0] * this->c + j] = clc[1];
        }
    }
}

void Parser::parse_requests() {
    std::string line;
    for (unsigned int i = 0; i < r; i++) {
        std::getline(this->file, line);
        std::vector<unsigned int> rs;
        split(line, rs, ' ');
        request_endpoints[rs[0]] = rs[1];
        requests_number[rs[0]] = rs[2];
    }
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


unsigned int Parser::get_c() {
    return this->c;
}

unsigned int Parser::get_e() {
    return this->e;
}

unsigned int Parser::get_x() {
    return this->x;
}

unsigned int Parser::get_v() {
    return this->v;
}

std::vector<unsigned int> Parser::get_video_sizes() {
    return this->video_sizes;
}

unsigned int * Parser::get_cache_latencies() {
    return this->cache_latencies;
}

unsigned int * Parser::get_video_latencies() {
    return this->video_latencies;
}