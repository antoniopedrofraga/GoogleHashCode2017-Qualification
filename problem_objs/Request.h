//
// Created by António Pedro Fraga on 27/02/2017.
//

#ifndef UNTITLED_REQUEST_H
#define UNTITLED_REQUEST_H


#include <ostream>
#include "Endpoint.h"

class Request {
private:
    unsigned int video_id;
    Endpoint * endpoint;
    unsigned int number_of_requests;
    unsigned int size;
public:
    Request(unsigned int v, Endpoint * e, unsigned int r, unsigned int size);
    unsigned int get_number_of_requests();
    Endpoint * get_endpoint();
    unsigned int get_video_id();
    double get_score();

    bool operator < (Request& request) {
        return (get_score() > request.get_score());
    }
};


#endif //UNTITLED_REQUEST_H
