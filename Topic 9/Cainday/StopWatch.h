#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <ctime>

class StopWatch {
    private:
        time_t startTime, endTime;
    
    public: 
        StopWatch() {
            this->startTime = 0;   
            this->endTime = 0;
        }

        void start() {
            this->startTime = time(NULL) * 1000;
        }

        void stop() {
            this->endTime = time(NULL) * 1000;
        }

        float getElapsedTime() {
            return this->endTime - this->startTime;
        }
};

#endif