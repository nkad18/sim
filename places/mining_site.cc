#include "mining_site.h"

using namespace std;

void MiningSite::AddTruck(shared_ptr<Truck> truck) {
     trucks_.push_back(truck);
}

list<shared_ptr<Truck>> MiningSite::GetFullTrucks () {
    list<shared_ptr<Truck>> fullTrucks;

    std::list<shared_ptr<Truck>>::iterator truck_ptr = trucks_.begin();
    while (truck_ptr != trucks_.end()) {
       bool isFull = truck_ptr->get()->GetTimer() >= truck_ptr->get()->GetDuration();
       if (isFull) {
        fullTrucks.push_back(*truck_ptr);
        trucks_.erase(truck_ptr++);
       }
    }
    return fullTrucks;
}