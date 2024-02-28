Overview
We are simulating a Helium-3 mining operation on the moon. The operation includes
a mining site, roads to and from the mining site, and an unload site abstracted as “places”. 
The operation lasts for 72 hours, trucks take 1-5 hours to fill up at the mine, 30 minutes 
to travel one way between the mine and the unload site, and 5 minutes to unload once
there. The simulation uses the integer value of 1 to represent 1 minute, and 1 frame,
in the simulation. The simulation is, at the lowest level, composed of frames. During
each frame, the simulation services the trucks located in 4 different 'places' within
the simulation. The simulation keeps tallies of per truck and overall amount of 
complete loads.

Detailed Design
Abstractions: 
Place (Mining Site, Road to Unload, Road to Mine, Unload Site)
Actor (Truck)

Specifications:
A frame corresponds to 1 minute: This is done because every interesting event in the
simulation is divisible be 1 minute. Choosing 1 minute guarantees that, regardless
of the scenario, there will be no ambiguity in the relative order, with respect to time,
of actors in the simulation.

The efficiency of each truck is randomly set to a value between 1-5 hours upon arriving
at the mine, each time. The value can be randomly selected only once. But it is more 
realistic to have some variability between loads. If given more time I would expend on this 
design detail by basing future selections on the initially selected value.

The List data structure was used throughout the simulation because of it allows efficient 
deletion of nodes located in the middle of the list. Lastly, shared pointer is used to safely 
and efficiently manage ownership and lifetime of trucks throughout the simulation.

Summary
Trucks, the mine, the unload sites, and the roads to and from the mine are initialized at 
the beginning of the simulation. The simulation iterates, 1 "minute" at a time, for the 
equivalent of 72 hours. Each iteration corresponds to a frame. In each frame, the timer 
in each truck is incremented, and then the timer is compared to
the duration that the truck will spend at its current place. If the truck's timer
has reached the duration, it will be moved to the next place. If the current 
place is the unload site, we will increment the trucks total load count and overall load 
completion. 

At the end of the simulation, the load counts can be used to determine the performance
of each truck.

The per-frame update to each truck is independent from other trucks; at each location 
except for the unload site. Thus, if given more time, I would introduce concurrency to this 
design. 

If given more time, I would add functional and integration testing. I would also add more
comments to .cc files.