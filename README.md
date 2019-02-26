# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from [here](https://github.com/udacity/self-driving-car-sim/releases/tag/v1.45) .

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

I am using [Eclipse style file](https://github.com/google/styleguide/blob/gh-pages/eclipse-cpp-google-style.xml) from Google to stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

##### Describe the effect each of the P, I, D components had in your implementation.

- __P__

  High P value : The line of the car is very unstable, and the car is swing left and right. At last the car will go out of the track very quickly.

  Low P value : The car can not return to the center of the lane immediately. 

- __D__

  High D value : The steering wheel is turning very fast.

  ![High D value](https://github.com/ZhihuiTian/CarND-PID-Control-Project/blob/master/gif/high-d-value.gif?raw=true "High D value")

- __I__

  I am using 0 for I, because I did not find a suitable value for I.

##### Describe how the final hyperparameters were chosen.

First I tried set P to 3 and the other values to 0.  The car is swing left and right and go out of the track very quickly. I tried to reduce the value of P from 3 to 0.2, but the result is not good.

I started trying to increase the I value and found the car can not run straight from the beginning, so I gave up to optimizing the I value.

For D value, I gave it to 100 at first. The result is like the video below. My car's steering wheel is turning very fast. I think it will make the passengers in the car feel uncomfortable. Then I tried to reduce the D value to 3. 

At last  the final hyperparameters is below:

P : 0.2

D : 3

I : 0



