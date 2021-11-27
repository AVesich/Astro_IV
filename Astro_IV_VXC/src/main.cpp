/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Intake               motor         12              
// RLift                motor         5               
// mogoLift             motor         21              
// Controller1          controller                    
// Controller2          controller                    
// LiftClaw             digital_out   A               
// lFront               motor         3               
// lBack                motor         4               
// rFront               motor         13              
// rBack                motor         14              
// LAutoClick           limit         B               
// RAutoClick           limit         C               
// LLift                motor         15              
// mh8Gps               gps           6               
// LiftBumper           bumper        D               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // Init stuff
  initIntake();
  initLift();
  initmogoLift();

  //m_driveTrain.mh8_initGps(0.03175, 0.1016, 0);

  Controller1.ButtonDown.pressed(liftClawToggle);
  Controller2.ButtonX.pressed(liftClawToggle);
  // Reverse "front" of the robot when the b button is pressed
  Controller1.ButtonB.pressed(revDrive);

  LiftBumper.pressed(resetLiftEncoders);

  autoSelector();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  runAuto();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  m_driveTrain.mh8_setBrake('c'); // Set brake mode to coast
  while (1) {
    
    driveOp();
    intakeOp(); // Intake operator control
		mogoOp(); // Mogo lift operator control
		liftOp(); // Lift operator control

    // Allow running auto from the controller if not in competition
    if (!Competition.isCompetitionSwitch()) {
      if (Controller1.ButtonLeft.pressing())
        runAuto();
    }

    wait(10, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
