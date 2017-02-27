//
// Created by António Pedro Fraga on 27/02/2017.
//

#include <iostream>
#include "Cache.h"


Cache::Cache(unsigned int capacity) {
    this->capacity = capacity;
    this->videos = new std::vector<unsigned int>();
    this->used_capacity = 0;
    this->used = false;
}

unsigned int Cache::get_capacity() {
    return this->capacity;
}

unsigned int Cache::get_used_capacity() {
    return this->used_capacity;
}

void Cache::place_on_cache(unsigned int video_id, unsigned int size) {
    if (std::find(videos->begin(), videos->end(), video_id) == videos->end()) {
        this->videos->push_back(video_id);
        this->used_capacity += size;
        this->used = true;
    }
}

std::vector<unsigned int> Cache::get_videos() {
    return *this->videos;
}

bool Cache::is_used() {
    return used;
}