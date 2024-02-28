#include "truck.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Truck::Initiliaze (ActorState mode) {
    ResetTimer();
    switch (mode) {
        case ActorState::kMine:
           int duration = rand() % 300;
           SetDuration(duration);
        case ActorState::kRoadToMine:
           SetDuration(30);
        case ActorState::kRoadToUnload:
           SetDuration(30);
        case ActorState::kUnload:
           SetDuration(5);
    };
}

void Truck::Increment () {
    timer_++;
}

void Truck::ResetTimer () {
    timer_ = 0;
}

void Truck::SetDuration (unsigned int duration) {
    duration_ = duration;
}

unsigned int Truck::GetDuration () {
    return duration_;
}

unsigned int Truck::GetTimer () {
    return timer_;
}

void Truck::IncrementLoadsCompleted () {
    loads_completed_++;
}

unsigned int Truck::GettLoadsCompleted () {
    return loads_completed_;
}