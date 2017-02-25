//
// Created by António Pedro Fraga on 25/02/2017.
//

#include "Parser.h"

Parser::Parser(std::string filename) {
    this->filename = filename;
    this->open_file();
}

void Parser::open_file() {
    this->file.open(filename);
    if (this->file.is_open()) {
        this->parse_first_line();
        this->parse_sizes_line();
        this->parse_endpoints();
    }
}

void Parser::parse_first_line() {
    std::string line;
    std::getline(this->file, line);
    std::istringstream iss(line);

    iss >> this->v >> this->e >> this->r >> this->c >> this->x;
    this->cache_latencies = (unsigned int *)malloc((this->c * this->e) * sizeof(unsigned int));
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
        this->video_latencies.push_back(ldk[0]);
        unsigned int k = ldk[1];

        for (unsigned int j = 0; j < k; j++) {
            std::getline(this->file, line);
            std::vector<unsigned int> clc;
            split(line, clc, ' ');
            this->cache_latencies[clc[0] * this->c + j] = clc[1];
        }
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