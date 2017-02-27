//
// Created by António Pedro Fraga on 27/02/2017.
//

#ifndef UNTITLED_CACHE_H
#define UNTITLED_CACHE_H


#include <vector>

class Cache {
private:
    unsigned int capacity;
    unsigned int used_capacity;

    std::vector<unsigned int> videos;
public:
    Cache(unsigned int capacity);
};


#endif //UNTITLED_CACHE_H
