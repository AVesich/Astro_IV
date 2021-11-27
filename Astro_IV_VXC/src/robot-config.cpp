#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Intake = motor(PORT12, ratio6_1, false);
motor RLift = motor(PORT5, ratio36_1, false);
motor mogoLift = motor(PORT21, ratio18_1, false);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
digital_out LiftClaw = digital_out(Brain.ThreeWirePort.A);
motor lFront = motor(PORT3, ratio6_1, true);
motor lBack = motor(PORT4, ratio6_1, true);
motor rFront = motor(PORT13, ratio6_1, false);
motor rBack = motor(PORT14, ratio6_1, false);
limit LAutoClick = limit(Brain.ThreeWirePort.B);
limit RAutoClick = limit(Brain.ThreeWirePort.C);
motor LLift = motor(PORT15, ratio36_1, true);
gps mh8Gps = gps(PORT6, -31.75, 19.50, mm, 180);
bumper LiftBumper = bumper(Brain.ThreeWirePort.D);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}