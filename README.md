
# CarND-PID-Control-Project
PID controller in C++ to maneuver a vehicle.

---

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Effect of the P, I, D components

With only the P component, the trajectory oscillates around the reference, in this case, the car oscillates around the center of the lane. To solve this, we add the D component, which takes into account the derivative, and the trajectory goes to the reference value, after oscillating a little.

But with only the P and D component, the value of the trajectory tends to a constant error with respect to the reference, so we add the component I, which is the integral vale of the CTE to reduce the error. The effect of this component cannot be seen easily in the simulation, but the driving seems smoother.

## Selection of the hyperparameters

To choose the hyperparameters I used a two step process:
	
	- First, I tried various possible values manually, using the simulation to check their validity.

	- Then, I used a modification of twiddle, which executes in runtime, optimizing the hyperparameters, reducing the absolute value of the error. This is used to improve a little the relations of the different hyperparameters.
