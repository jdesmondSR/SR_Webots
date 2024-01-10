#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

// this is new
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
  const unsigned char *img;     // store whole image 
  static unsigned char gray;    // single pixel
  int image_width = cam->getWidth(); // just to make it easier later
  
  // shows the height and width of the camera (the resolution)
  printf("height: %d\n", cam->getHeight());
  printf("width:  %d\n", cam->getWidth());
  

  while (robot->step(timeStep) != -1) {
    // get the image from the cam
    img = cam->getImage();
    
    // get the grayscale value of the center pixel.
    gray = cam->imageGetGray(img, image_width, 5, 5);
    /*   arguments
        img - the image read from teh camera
        image_width - width of the camera object
        5, 5 - row,column location of the pixel being viewed. 
    */
    
    
    printf("gray -> %3d\n", gray);
    
    // move forward slowly
    leftmotor->setVelocity(2);
    rightmotor->setVelocity(2);
    
  } // end main while loop

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
