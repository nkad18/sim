#ifndef SIM_PLACES_MINING_SITE_H_
#define SIM_PLACES_MINING_SITE_H_

#include <list>
#include <memory>
#include "place.h"
#include "truck.h"

using namespace std;

// Declaration of Mining site type
class MiningSite : public Place {
    public:
      // Add a truck from this place
      void AddTruck(shared_ptr<Truck>) override;

      // Update trucks to current frame
      void ProcessTrucks() override;

      // Returns list of full trcuks
      list<shared_ptr<Truck>> GetFullTrucks();

    private:
      list<shared_ptr<Truck>> trucks_;
};
#endif // SIM_PLACES_MINING_SITE_H_