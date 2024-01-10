#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/Gyro.hpp>
using namespace webots;

#define UPDATE robot->step(timeStep) != -1

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
  Gyro *gyro = robot->getGyro("my_gyro");
  gyro->enable(timeStep);


  Motor *leftmotor = robot->getMotor("left wheel motor");
  Motor *rightmotor = robot->getMotor("right wheel motor");
  
  // set position to infinity so it can turn continuously
  leftmotor->setPosition(INFINITY);
  rightmotor->setPosition(INFINITY);
  
  // set initial velocity to 0
  leftmotor->setVelocity(0.0);
  rightmotor->setVelocity(0.0);
  
  double angle = 0;
  while (robot->step(timeStep) != -1) {
    
    angle = 0;
    while(angle < 90 && UPDATE){
      angle += ((timeStep / 1000.0) * (gyro->getValues()[2])) * (180.0/3.141592653589793238463);
      printf("angle: %f\n", angle);
    
      leftmotor->setVelocity(-0.5);
      rightmotor->setVelocity(0.5);
    }
    
    printf("Done turning");
    
    leftmotor->setVelocity(0);
    rightmotor->setVelocity(0);
    delay(2000);
  }

  delete robot;
  return 0;
}
