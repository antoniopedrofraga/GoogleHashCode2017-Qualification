//
// Created by António Pedro Fraga on 27/02/2017.
//

#ifndef UNTITLED_CLATENCY_H
#define UNTITLED_CLATENCY_H


class CLatency {
private:
    unsigned int cache;
    unsigned int latency;
public:
    CLatency(unsigned int c, unsigned int l);
    unsigned int get_latency();
    unsigned int get_cache_id();
    bool operator < (CLatency cache_latency) {
        return (latency < cache_latency.get_latency());
    }
};


#endif //UNTITLED_CLATENCY_H
