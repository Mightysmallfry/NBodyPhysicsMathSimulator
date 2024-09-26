## What is NBodyPhysMathSim
This program is meant to allow someone to construct a Nbody problem and then simulate the events that follow at different time intervals.

### Creating a CBody
Create a body with a:
- `Name`
- `BodyType` (Planet, Moon, Star, Singularity)
- `Mass` (Kg)
- `Position` (M)
- `NetForce` (N)

### Creating a CSim
Pretty simple, instantiate it. Then add all of your bodies and then you can run the simulation for a desired time. 
This will have the functionality of changing specifying how long you want the simulation to run and how quickly of an update you will want. Understand that more updates,
means more calculations and thus a longer runtime. Too large of a update interval (`deltaTime`) may result in missed collisions, or false behavior of the a body.

### Goals 
The Goal of this program is to allow get a working foundation such that, with a visual library, can be used to visualize multiple body problems.
This includes examples of simulating a solar system with 8 to 9 planetary bodies, or a binary system with several moons.


### How it works
Each object you want to add will be some kind of CBody object. This has the basic information that will allow the simulation of gravitational forces and changes in position.

Each object will have to be added to a CSim if you want it to be simulated. Otherwise it won't do anything currently. 
This should mean later on if possible/desired, multiple threads could be used to run different simulations at the same time.
