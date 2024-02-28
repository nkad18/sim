#ifndef SIM_ACTORS_ACTOR_H_
#define SIM_ACTORS_ACTOR_H_
// Abstraction of a simulation actor
class Actor {
    public:
    enum ActorState{
        kMine = 0,
        kRoadToUnload,
        kRoadToMine,
        kUnload
    };

    public:
      // Initialize the entity given a simulation mode
      virtual void Initiliaze(ActorState) = 0;

      // Increment the entity's timer
      virtual void Increment() = 0;

      // Reset the actors's timer
      virtual void ResetTimer() = 0;

      // Set the current state
      void SetState(ActorState state) {
        state_ = state;
      }

      // Get the current state
      ActorState GetState() {
        return state_;
      }

    protected:
       unsigned int timer_;
       ActorState state_;
};
#endif // SIM_ACTORS_ACTOR_H_