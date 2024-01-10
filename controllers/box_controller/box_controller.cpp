// drive around the box program

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

// All the webots classes are defined in the "webots" namespace
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
  
  // main loop
  int x = 0;
  while (robot->step(timeStep) != -1) {
    leftmotor->setVelocity(6);
    rightmotor->setVelocity(6);
    delay(5200);
    
    leftmotor->setVelocity(0);
    rightmotor->setVelocity(0);
    delay(500);
    
    leftmotor->setVelocity(-3);
    rightmotor->setVelocity(3);
    delay(725);
    
    leftmotor->setVelocity(0);
    rightmotor->setVelocity(0);
    delay(500);
    
    x++;
    printf("x = %d\n\n", x);
    
    if(x > 3){
      leftmotor->setVelocity(0);
      rightmotor->setVelocity(0);
      printf("Done!!!\n\n");
      delay(5000);
      
      // reset x and go again
      x = 3;
    }
  
  } // end main while loop

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
