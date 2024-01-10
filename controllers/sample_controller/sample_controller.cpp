
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/InertialUnit.hpp>

using namespace webots;


int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();

  // get the time step of the current world.
  int timeStep = (int)robot->getBasicTimeStep();

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
    
  
  InertialUnit *imu = robot->getInertialUnit("my_imu");
  imu->enable(timeStep);
  
  
  
  while (robot->step(timeStep) != -1) {
    leftmotor->setVelocity(-1);
    rightmotor->setVelocity(1);
    
    const double yaw = imu->getRollPitchYaw()[2];
    printf("yaw = %.2f\n", yaw * (180/3.1415));
    
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
