#include "vex.h"

// Driver control
void mogoOp() {
    directionType mogoLiftDir;
    int mogoLiftSp;

    if(Controller1.ButtonR1.pressing()) {
      mogoLiftSp = 100;
      //mogoLiftDir = directionType::rev;
    } else if (Controller1.ButtonR2.pressing()) {
      mogoLiftSp = -100;
      //mogoLiftDir = directionType::fwd;
    } else {
      mogoLift.stop();
    }

    mogoLift.spin(directionType::fwd, mogoLiftSp, velocityUnits::pct);
}

// Auto
void mogoAuto(double deg, char dir) {
  // Tare the lift's position
  resetMogoLift();

  directionType mogoLiftDir;

  if (dir == 'u')
    mogoLiftDir = directionType::fwd;
  else if (dir == 'd')
    mogoLiftDir = directionType::rev;

  mogoLift.rotateFor(mogoLiftDir, deg, rotationUnits::deg, 100, velocityUnits::pct);
  
  mogoLift.stop();
  resetMogoLift();
}

int mogoLiftAsync() {
  while (1) {
    if (mogoLift.rotation(deg) < mogoLiftTarget-5 || mogoLift.rotation(deg) > mogoLiftTarget+5) {
      mogoLift.rotateTo(mogoLiftTarget, rotationUnits::deg, 100, velocityUnits::pct, false);
    }
    task::sleep(20); // Sleep to save resources
  }

  return 0;
}

// Utility
void initmogoLift() {
  mogoLift.resetRotation();
  mogoLift.setBrake(brakeType::hold);
}

void resetMogoLift() {
  mogoLift.resetRotation();
  mogoLift.stop();
}