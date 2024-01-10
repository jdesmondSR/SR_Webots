
#include <webots/Robot.hpp>


using namespace webots;

// create the Robot instance.
Robot *robot = new Robot();

// get the time step of the current world.
int timeStep = (int)robot->getBasicTimeStep();


// Delay function
void delay(int ms) {
  double initTime = robot->getTime();
  while (robot->step(timeStep) != -1) {
    if ((robot->getTime() - initTime) * 1000.0 > ms) {
      break;
    }
  }
}

int main(int argc, char **argv) {
  
  // write a program that determines how many digits a number has
  // 1, 2, or 3. you can assume no number will be larger than 999
  
  
  while (robot->step(timeStep) != -1) {
    // remember to use the flowchart
    
  };


  delete robot;
  return 0;
}
