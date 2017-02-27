//
// Created by António Pedro Fraga on 27/02/2017.
//

#ifndef UNTITLED_CACHE_H
#define UNTITLED_CACHE_H


#include <vector>
#include <algorithm>

class Cache {
private:
    unsigned int capacity;
    unsigned int used_capacity;

    std::vector<unsigned int> videos;
public:
    Cache(unsigned int capacity);
    unsigned int get_capacity();
    unsigned int get_used_capacity();
    void place_video(unsigned int video_id, unsigned int size);
};


#endif //UNTITLED_CACHE_H
