// include files
#include <webots/Robot.hpp>
using namespace webots;



// create the Robot instance.
Robot *robot = new Robot();

// get the time step of the current world.
int timeStep = (int)robot->getBasicTimeStep();


// Delay function
void delay(int ms)
{
  double initTime = robot->getTime();
  while (robot->step(timeStep) != -1)
  {
    if ((robot->getTime() - initTime) * 1000.0 > ms)
    {
      break;
    }
  }
}





/* ---------------------------------------------------------------

    Sample 1
    
-----------------------------------------------------------------*/

// if else sample
void sample_if_else()
{
  // first, set the variable value
  int x = 10;
  
  // each time this loop runs, the simulation moves forward in SIMULATION time
  while (robot->step(timeStep) != -1)
  {
    
    // print current variables value
    printf("x is %3d  ", x);
    
    // check if variable x is greater than 0 (possitive integer)
    if( x > 0 )
    {
      // boolean expression true
      printf("Possitve number  -> statement TRUE\n");
    }
    else 
    {
      // boolean expression false 
      printf("non-possitive number -> statement FALSE\n");
    }
    
    // delay to read output
    delay(750);
    
    // modify the variable x
    x--;
  
  
  } //  end of loop

} // end of sample








/* ---------------------------------------------------------------

    Sample 2
    
-----------------------------------------------------------------*/

// if else if sample
void sample_if_else_if()
{
  // compare the following variables
  int a = 30;
  int b = 20;
  
  // each time this loop runs, the simulation moves forward in SIMULATION time
  while (robot->step(timeStep) != -1)
  {
    
    // print current variables value
    printf("a is %3d  b is %3d  ", a, b);
    
    /*
        The following if-else-if will
        check which variable is larger.
    */
    
    // A
    if( a > b)
    {
      // A TRUE
      printf("___ is larger than ___\n");
    }
    
    // B
    else if(a < b)
    {
      // A false B TRUE
      printf("___ is larger than ___\n");
    }
    
    // C
    else if(a == b)
    {
      // A false B false C TRUE
      printf("a is EQUAIVALENT to b\n");
    }
    
    else
    {
      // A false B false C false
      printf("Nothing was true. This is called a trailing else\n");
    }
    
    // delay to read output
    delay(750);
    
    // modify the variable x
    b++;
  
  
  } //  end of loop

} // end of sample


/* ---------------------------------------------------------------

    Sample 3
    
-----------------------------------------------------------------*/

// nested if statement
void sample_nested_if()
{
  // check if the following grade is in valid range 0-100
  int grade = 92;
  
  // each time this loop runs, the simulation moves forward in SIMULATION time
  while (robot->step(timeStep) != -1)
  {

    // A
    if(grade <= 100)
    {
    
      // B
      if(grade >= 0)
      {
        printf("The grade is in the valid range!\n");
      }
      else
      {
        printf("The grade is _______ (above/below) the range...\n");
      }
    
    }
    else
    {
      printf("The grade is _______ (above/below) the range...\n");
    }
    
    // BIG delay to pause simulation for a long time
    delay(20000);



  } // end of loop

} // end of sample


/* ---------------------------------------------------------------

    Challenge
    
-----------------------------------------------------------------*/

// given 3 numbers, find the sum of the largest 2 values
void challenge()
{
  // variables for 3 values and the sum
  int a = 42;
  int b = 100;
  int c = 15;
  int sum = 0;
  
  // each time this loop runs, the simulation moves forward in SIMULATION time
  while (robot->step(timeStep) != -1)
  {
  
    // ----- put your code here ----- //
    
    // ------------------------------ //
    
    
    
    // print the sum that you calculated
    
    
    // BIG delay to pause simulation for a long time
    delay(20000);
  } // end of loop

} // end of sample







int main(int argc, char **argv)
{
  // ---------- call sample function here ---------- //
  
  sample_if_else();
  
  // sample_if_else_if();

  // sample_nested_if();
  
  // challenge();
  
  
  delete robot;
  return 0;
}
