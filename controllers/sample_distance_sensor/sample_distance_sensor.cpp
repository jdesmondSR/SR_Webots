#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>
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
  // distance sensor
  DistanceSensor *front_right = robot->getDistanceSensor("ps0");
  front_right->enable(timeStep);
  
  double dist;
  printf("Max value: %f\n", front_right->getMaxValue());
  printf("Min value: %f\n", front_right->getMinValue());
  printf("Aperture:  %f\n", front_right->getAperture());
  
  // left motor
  Motor *leftmotor = robot->getMotor("left wheel motor");
  leftmotor->setPosition(INFINITY);
  leftmotor->setVelocity(0.0);
  
  // right motor
  Motor *rightmotor = robot->getMotor("right wheel motor");
  rightmotor->setPosition(INFINITY);
  rightmotor->setVelocity(0.0);
  
  
  while (robot->step(timeStep) != -1) {
    //leftmotor->setVelocity(2);
    //rightmotor->setVelocity(2);
    
    dist = front_right->getValue();
    printf("Distance: %4.3f\n", dist);
    
    // need to add front left as well... otherwise it keeps bumping
    
  }

  delete robot;
  return 0;
}
