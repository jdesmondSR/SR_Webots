#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
using namespace webots;

// create the Robot instance.
Robot *robot = new Robot();
  
// should load the value 32 from the world
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
  // create motor objects (found in epuck>children>hingeJoint>device
  // click on rotational motor to get aditional details
  Motor *leftmotor = robot->getMotor("left wheel motor");
  Motor *rightmotor = robot->getMotor("right wheel motor");
  
  // set position to infinity so it can turn continuously
  leftmotor->setPosition(INFINITY);
  rightmotor->setPosition(INFINITY);
  
  // set initial velocity to 0
  leftmotor->setVelocity(0.0);
  rightmotor->setVelocity(0.0);
  
  
  while (robot->step(timeStep) != -1) {
    // forward max speed
    leftmotor->setVelocity(3);
    rightmotor->setVelocity(3);
    delay(6000);
    
    if(a > 100){
      // do stuff
    }
    // merge logic
    
    // backward max speed
    leftmotor->setVelocity(-3);
    rightmotor->setVelocity(3);
    delay(600);
  }

  delete robot;
  return 0;
}
