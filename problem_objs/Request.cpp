//
// Created by António Pedro Fraga on 27/02/2017.
//

#include "Request.h"

Request::Request(unsigned int v, Endpoint * e, unsigned int r) : endpoint(e) {
    this->video_id = v;
    this->number_of_requests = r;
}

unsigned int Request::get_number_of_requests() {
    return this->number_of_requests;
}

Endpoint * Request::get_endpoint() {
    return this->endpoint;
}

unsigned int Request::get_video_id() {
    return this->video_id;
}