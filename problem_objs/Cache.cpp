//
// Created by António Pedro Fraga on 27/02/2017.
//

#include "Cache.h"


Cache::Cache(unsigned int capacity) {
    this->capacity = capacity;
    this->used_capacity = 0;
}

unsigned int Cache::get_capacity() {
    return this->capacity;
}

unsigned int Cache::get_used_capacity() {
    return this->used_capacity;
}

void Cache::place_video(unsigned int video_id, unsigned int size) {
    videos.push_back(video_id);
    used_capacity += size;
}