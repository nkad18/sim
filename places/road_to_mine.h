#ifndef SIM_PLACES_ROAD_TO_MINE_H_
#define SIM_PLACES_ROAD_TO_MINE_H_

#include <list>
#include "place.h"
#include "truck.h"

using namespace std;

// Declaration of unload site type
class RoadToMine : public Place {
    public:
      // Add an actor to this place
      void AddTruck(shared_ptr<Truck>) override;

      // Update trucks to current frame
      void ProcessTrucks() override;

      // Returns list of trcuks that arried at the mine
      list<shared_ptr<Truck>> GetTrucksThatArrived();

    private:
      list<shared_ptr<Truck>> trucks_;
};
#endif // SIM_PLACES_ROAD_TO_MINE_H_
