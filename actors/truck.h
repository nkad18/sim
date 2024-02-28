#ifndef SIM_TRUCK_H_
#define SIM_TRUCK_H_

#include "actor.h"

// Declaration of truck
class Truck : public Actor{
    public:
      // Initialize the truck's given a simulation mode
      void Initiliaze(ActorState) override;

      // Increment the truck's timer
      void Increment() override;

      // Reset the truck's timer
      void ResetTimer() override;

      // Set the duration of current mode
      void SetDuration(unsigned int);

      // Get timer
      unsigned int GetTimer();

      // Get duration
      unsigned int GetDuration();

      // Incrememnt loads completed
      void IncrementLoadsCompleted();

      // Get loads completed
      unsigned int GettLoadsCompleted();

    private:
      unsigned int duration_;
      unsigned int loads_completed_;
};
#endif //SIM_TRUCK_H_