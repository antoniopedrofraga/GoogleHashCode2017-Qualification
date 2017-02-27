//
// Created by António Pedro Fraga on 25/02/2017.
//

#include <ctime>
#include "Solver.h"

Solver::Solver(std::string output, Parser* parser) : output(output), parser(parser) {
    clock_t start_time, end_time;
    char reading_time[100];
    start_time = clock();

    solve();

    end_time = clock();
    sprintf(reading_time, "Solving time: %3.3f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    std::cout << reading_time << std::endl;

    write_output();
}

void Solver::solve() {
    unsigned int number_of_requests = parser->get_r();

    std::vector<Request> requests = *parser->get_requests();
    std::vector<Endpoint> endpoints = *parser->get_endpoints();
    std::vector<Cache*> * caches = parser->get_caches();

    for (unsigned int i = 0; i < number_of_requests; i++) {
        Endpoint * e = requests[i].get_endpoint();
        unsigned int video_id = requests[i].get_video_id();
        this->place_video(caches, video_id, *e);
    }
}

void Solver::place_video(std::vector<Cache*> * caches, unsigned int video_id, Endpoint endpoint) {

    std::vector<unsigned int> video_sizes = parser->get_video_sizes();
    unsigned int size = video_sizes[video_id];
    std::vector<CLatency> latencies_to_cache = *endpoint.get_latencies_to_cache();


    for (unsigned int j = 0; j < latencies_to_cache.size(); j++) {
        unsigned int cache_id = latencies_to_cache[j].get_cache_id();
        unsigned int capacity = (*caches)[cache_id]->get_capacity();
        unsigned int used_capacity = (*caches)[cache_id]->get_used_capacity();
        if (capacity >= used_capacity + size) {
            (*caches)[cache_id]->place_on_cache(video_id, size);
            return;
        }
    }
}

void Solver::write_output() {
    std::ofstream output_file;
    output_file.open (this->output);
    if (output_file.is_open()) {
        std::string ostring = "";
        std::vector<Cache*> caches = *parser->get_caches();
        unsigned int used_caches = 0;
        for (unsigned int i = 0; i < caches.size(); i++) {
            used_caches += caches[i]->is_used() ? 1 : 0;
        }
        output_file << used_caches << "\n";
        for (unsigned int i = 0; i < caches.size(); i++) {
            used_caches += caches[i]->is_used() ? 1 : 0;
            output_file <<  i << " ";
            std::vector<unsigned int> videos = caches[i]->get_videos();
            for (unsigned int j = 0; j < videos.size(); j++) {
                output_file <<  videos[j] << " ";
            }
            output_file << "\n";
        }
        output_file.close();
    } else {
        std::cout << "File is closed" << std::endl;
    }
}

