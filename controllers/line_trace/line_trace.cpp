// line trace program

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/Camera.hpp>
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
  // motor setup
  Motor *leftmotor = robot->getMotor("left wheel");
  Motor *rightmotor = robot->getMotor("right wheel");
  leftmotor->setPosition(INFINITY);
  rightmotor->setPosition(INFINITY);
  leftmotor->setVelocity(0.0);
  rightmotor->setVelocity(0.0);
  
  // sensor setup
  Camera *cam = robot->getCamera("Color Sensor");
  cam->enable(timeStep);
  
  // variables for image processing
  const unsigned char *img;
  static unsigned char gray, red, green;
  int image_width = cam->getWidth();
  
  // varibales for line tracing
  int black = 0, white = 207;
  int threshold = (white+black)/2;
  

  while (robot->step(timeStep) != -1) {
    // get the image and get the center pixel
    img = cam->getImage();
    gray = cam->imageGetGray(img, image_width, 5, 5);
    //printf("gray -> %3d\n", gray);
    
    red = cam->imageGetRed(img, image_width, 5, 5);
    green = cam->imageGetGreen(img, image_width, 5, 5);
    printf("r/g -> %3.2f\n", (float)red/green);
    
    if((float)red/green > 1.5){
      leftmotor->setVelocity(0);
      rightmotor->setVelocity(0);
    }
    else if(gray < threshold){
      leftmotor->setVelocity(4);
      rightmotor->setVelocity(0);
    }
    else{
      leftmotor->setVelocity(0);
      rightmotor->setVelocity(4);
    }
    
    
  } // end main while loop

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
