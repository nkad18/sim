#ifndef SIM_MINING_H_
#define SIM_MINING_H_

#include <list>
#include "mining_site.h"
#include "road_to_mine.h"
#include "road_to_unload.h"
#include "truck.h"
#include "unload_site.h"

using namespace std;

// Declaration of the mining sim
class Mining {

public:
   // Constructor sets the ammount of trucks and unload stations
   Mining(unsigned int trucks, unsigned int unload_stations);

public:
   // Process all trucks in route to mine
   void ProcessRoadToMine();

   // Process all trucks in route to unload station
   void ProcessRoadFromMine();
   
   // Process all trucks currently at the mine
   void ProcessMine();

   // Process all trucks currently at the unload site
   void ProcessUnloadSites();

   // Returns unload site with the emptiest queue
   UnloadSite GetEmptiestUnloadSite();

   // Returns unloaded trucks
   list<shared_ptr<Truck>> GetEmptyTrucks();

   // Increment the total loads completed during the simulation
   void IncrementTotalLoadsCompleted();

   //provide statistics after simulation is complete
   void Statistics();

   // Run the mining simulation
   void RunMiningSim();
   
private:
   list<UnloadSite> unload_sites_;
   MiningSite mining_site_;
   RoadToUnload road_to_unload_;
   RoadToMine road_to_mine_;
   unsigned int trucks_;
   unsigned int unload_stations_;
   unsigned int total_loads_completed_;
   unsigned int simulation_duration_minutes_;
};
#endif // SIM_MINING_H_
