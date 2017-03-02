//
// Created by António Pedro Fraga on 27/02/2017.
//

#ifndef UNTITLED_CACHE_H
#define UNTITLED_CACHE_H


#include <vector>
#include <algorithm>

class Cache {
private:
    bool used;
    unsigned int capacity;
    unsigned int used_capacity;


    std::vector<unsigned int> * videos;
public:
    Cache(unsigned int capacity);
    unsigned int get_capacity();
    unsigned int get_used_capacity();
    unsigned int get_free_space();
    void place_on_cache(unsigned int video_id, unsigned int size);
    std::vector<unsigned int> get_videos();
    bool is_used();
};


#endif //UNTITLED_CACHE_H
