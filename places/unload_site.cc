#include "unload_site.h"

using namespace std;

void UnloadSite::AddTruck(shared_ptr<Truck> truck) {
    if (current_truck_ == nullptr) {
        wait_queue_.push(truck);
    }
    else {
        SetCurrentTruck(truck);
    }
}

void UnloadSite::ProcessQueue() {
    if (!wait_queue_.empty()) {
        SetCurrentTruck(wait_queue_.front());
        wait_queue_.pop();
    }
}

void UnloadSite::SetCurrentTruck(shared_ptr<Truck> truck) {
    current_truck_ = truck;
}