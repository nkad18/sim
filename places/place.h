#ifndef SIM_PLACES_PLACE_H_
#define SIM_PLACES_PLACE_H_

#include <vector>
#include "truck.h"

using namespace std;

// Declaration of place abstraction
class Place {
    public:
      // Add a truck to this place
      virtual void AddTruck(shared_ptr<Truck>) = 0;

      // Update trucks to current frame
      virtual void ProcessTrucks() = 0;
};
#endif // SIM_PLACES_PLACE_H_