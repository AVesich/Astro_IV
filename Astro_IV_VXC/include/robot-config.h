using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Intake;
extern motor RLift;
extern motor mogoLift;
extern controller Controller1;
extern controller Controller2;
extern digital_out LiftClaw;
extern motor lFront;
extern motor lBack;
extern motor rFront;
extern motor rBack;
extern limit LAutoClick;
extern limit RAutoClick;
extern motor LLift;
extern gps mh8Gps;
extern bumper LiftBumper;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );