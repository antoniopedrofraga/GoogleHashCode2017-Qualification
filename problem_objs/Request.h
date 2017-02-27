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
    Endpoint endpoint;
    unsigned int number_of_requests;
public:
    Request(unsigned int v, Endpoint e, unsigned int r);
    unsigned int get_number_of_requests();
    bool operator < (const Request& request) const {
        return (number_of_requests < request.number_of_requests);
    }
};


#endif //UNTITLED_REQUEST_H
