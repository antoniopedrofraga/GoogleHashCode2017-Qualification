//
// Created by António Pedro Fraga on 25/02/2017.
//

#include <ctime>
#include <set>
#include "Solver.h"

Solver::Solver(std::string output, Parser* parser) : output(output), parser(parser) {
    clock_t start_time, end_time;
    char reading_time[100];
    start_time = clock();

    this->solve();

    end_time = clock();
    sprintf(reading_time, "Solving time: %5.3f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    std::cout << reading_time << std::endl;

    this->write_output();
}

void Solver::solve() {
    unsigned int number_of_requests = parser->get_r();
    unsigned int cache_capacity = parser->get_x();

    std::deque<Request> requests = *parser->get_requests();
    std::vector<Endpoint> endpoints = *parser->get_endpoints();
    std::vector<Cache*> * caches = parser->get_caches();
    std::vector<CLatency*> * cache_latencies = parser->get_cache_latencies();

    std::vector<unsigned int> video_sizes = parser->get_video_sizes();

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
        Cache* cache = latencies_to_cache[j].get_cache();
        unsigned int capacity = cache->get_capacity();
        unsigned int used_capacity = cache->get_used_capacity();
        if (capacity >= used_capacity + size) {
            cache->place_on_cache(video_id, size);
            return;
        }
    }
}


/*
unsigned int Solver::sum_of_requests(std::vector<Request> requests) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < requests.size(); i++) {
        sum += requests[i].get_number_of_requests();
    }
    return sum;
}

std::vector<Request> Solver::knapsack(int capacity, std::vector<unsigned int> video_sizes, std::vector<Request> requests, int number_of_items) {

    if (number_of_items == 0 || capacity == 0)
        return {};

    unsigned int video_id = requests[number_of_items - 1].get_video_id();
    std::vector<Request> add_hypothesis = knapsack(capacity - video_sizes[video_id], video_sizes, requests, number_of_items - 1);
    std::vector<Request> dont_add_hypothesis = knapsack(capacity, video_sizes, requests, number_of_items - 1);
    unsigned int add_sum = sum_of_requests(add_hypothesis);
    unsigned int dont_add_sum = sum_of_requests(dont_add_hypothesis);

    if (video_sizes[video_id] > capacity)
        return knapsack(capacity, video_sizes, requests, number_of_items - 1);
    else {
        std::vector<Request> maximizers;
        if (requests[number_of_items - 1].get_number_of_requests() + add_sum > dont_add_sum) {
            maximizers.push_back(requests[number_of_items - 1]);
            maximizers.insert(maximizers.end(), add_hypothesis.begin(), add_hypothesis.end());
        } else {
            maximizers.insert(maximizers.end(), dont_add_hypothesis.begin(), dont_add_hypothesis.end());
        }
        return maximizers;
    }
}*/


void Solver::write_output() {
    std::ofstream output_file;
    output_file.open (this->output);
    if (output_file.is_open()) {
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

