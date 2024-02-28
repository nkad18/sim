#include "mining.h"

void Mining::RunMiningSim(){

    for(int i = 0; i<simulation_duration_minutes_; i++) {
       // Increment timer in each truck
       ProcessRoadToMine();
       ProcessRoadFromMine();
       ProcessMine();
       ProcessUnloadSites();

       // Perform state transitions for full trucks
       list<shared_ptr<Truck>> full_trucks = mining_site_.GetFullTrucks();
       for(shared_ptr<Truck> truck_ptr : full_trucks) {
           truck_ptr->Initiliaze(Actor::ActorState::kRoadToUnload);
           road_to_unload_.AddTruck(truck_ptr);
        }

       // Perform state transitions for full trucks
       list<shared_ptr<Truck>> trucks_arrived_at_unload = road_to_unload_.GetTrucksThatArrived();
       for(shared_ptr<Truck> truck_ptr : trucks_arrived_at_unload) {
           truck_ptr->Initiliaze(Actor::ActorState::kUnload);
           GetEmptiestUnloadSite().AddTruck(truck_ptr); 
        }

       // Perform state transitions for full trucks
       list<shared_ptr<Truck>> empty_trucks_at_unload = GetEmptyTrucks();
       for(shared_ptr<Truck> truck_ptr : empty_trucks_at_unload) {
           truck_ptr->Initiliaze(Actor::ActorState::kRoadToMine);
           truck_ptr->IncrementLoadsCompleted();
           IncrementTotalLoadsCompleted();
           road_to_mine_.AddTruck(truck_ptr);
        }
        
        // Perform state transitions for full trucks
       list<shared_ptr<Truck>> trucks_arrived_at_mine = GetEmptyTrucks();
       for(shared_ptr<Truck> truck_ptr : trucks_arrived_at_mine) {
           truck_ptr->Initiliaze(Actor::ActorState::kMine);
           mining_site_.AddTruck(truck_ptr);
        }
    }
}

// TODO