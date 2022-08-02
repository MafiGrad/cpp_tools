#pragma once

#include <iostream>
#include <chrono>

#define LOG_DURATION(msg) Profiler pr(msg);

class Profiler{
    public:
        explicit Profiler(const std::string& msg = "")
        : start(std::chrono::steady_clock::now()),
        message(msg + ": ")
        {}

        ~Profiler(){
            auto finish = std::chrono::steady_clock::now();
            auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
            std::cerr << message << elapsed_time.count() << " ms" << std::endl;
        }

    private:
        std::string message;
        std::chrono::steady_clock::time_point start;
};