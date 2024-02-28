#ifndef SIM_PLACES_UNLOAD_SITE_H_
#define SIM_PLACES_UNLOAD_SITE_H_

#include <queue>
#include "place.h"
#include "truck.h"

using namespace std;

// Declaration of unload site type
class UnloadSite : public Place {
    public:
      // Add an actor to this place
      void AddTruck(shared_ptr<Truck>) override;

      // Update trucks to current frame
      void ProcessTrucks() override;

      // Move truck from queue to unload port
      void ProcessQueue();

      // Set value of the the current truck
      void SetCurrentTruck(shared_ptr<Truck>);

    private:
      queue<shared_ptr<Truck>> wait_queue_;
      shared_ptr<Truck> current_truck_;
};
#endif // SIM_PLACES_UNLOAD_SITE_H_
