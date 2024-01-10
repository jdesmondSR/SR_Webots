#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Lidar.hpp>
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


  Lidar *lidar = robot->getLidar("lidar");
  lidar->enable(timeStep);
  
  // left motor
  Motor *leftmotor = robot->getMotor("left wheel motor");
  leftmotor->setPosition(INFINITY);
  leftmotor->setVelocity(0.0);
  
  // right motor
  Motor *rightmotor = robot->getMotor("right wheel motor");
  rightmotor->setPosition(INFINITY);
  rightmotor->setVelocity(0.0);
  
  // motor max power on e-puck
  //int max_power = 6.28;
  
  
  
  while (robot->step(timeStep) != -1) {
    //leftmotor->setVelocity(2);
    //rightmotor->setVelocity(2);
    
    const float *image = lidar->getRangeImage();
    for(int i = 0; i < 512; i+=((512/2)-1)){
      printf("%3d: %f\n", i, image[i]);
    }
    
    // need to add front left as well... otherwise it keeps bumping
    
  }

  delete robot;
  return 0;
}
