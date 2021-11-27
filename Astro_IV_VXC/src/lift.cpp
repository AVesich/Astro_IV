#include "vex.h"

bool clawClosed = false;

// Funcs
// Operator control
void liftOp() {
  if (Controller1.ButtonX.pressing() || Controller2.ButtonR1.pressing()) { // Up
    if (RLift.position(rotationUnits::deg) < 560) {
      RLift.spin(directionType::fwd, 100, velocityUnits::pct);
      LLift.spin(directionType::fwd, 100, velocityUnits::pct);
    } else {
      RLift.stop();
      LLift.stop();
    }
  } else if (Controller1.ButtonUp.pressing() || Controller2.ButtonL1.pressing()) { // Down
    if (!LiftBumper.pressing()) {
      RLift.spin(directionType::rev, 100, velocityUnits::pct);
      LLift.spin(directionType::rev, 100, velocityUnits::pct);
    } else {
      RLift.stop();
    LLift.stop();
    }
  } else {
    RLift.stop();
    LLift.stop();
  }
}

void liftClawToggle() {
  LiftClaw.set(!clawClosed);
  clawClosed = !clawClosed;
}

void liftAuto(double deg, char dir) {
  // Tare the lift's position
  resetLift();

  directionType liftDir;

  if (dir == 'u')
    liftDir = directionType::fwd;
  else if (dir == 'd')
    liftDir = directionType::rev;

  RLift.startRotateFor(liftDir, deg, rotationUnits::deg, 100, velocityUnits::pct);
  LLift.startRotateFor(liftDir, deg, rotationUnits::deg, 100, velocityUnits::pct);

  while (lifting()) {}
}

void flipoutLift() {
  LLift.rotateTo(100, rotationUnits::deg, 100, velocityUnits::pct, false);
  RLift.rotateTo(100, rotationUnits::deg, 100, velocityUnits::pct, true);
  LLift.rotateTo(10, rotationUnits::deg, 100, velocityUnits::pct, false);
  RLift.rotateTo(10, rotationUnits::deg, 100, velocityUnits::pct, true);
}

int liftAsync() {
  while (1) {
    if (LLift.rotation(deg) < liftTarget-5 || LLift.rotation(deg) > liftTarget+5) {
      LLift.rotateTo(liftTarget, rotationUnits::deg, 100, velocityUnits::pct, false);
      RLift.rotateTo(liftTarget, rotationUnits::deg, 100, velocityUnits::pct, true);
    }
    task::sleep(20); // Sleep to save resources
  }

  return 0;
}

void liftClawAuto(bool on) {
  LiftClaw.set(on);
  clawClosed = !clawClosed;
}

// Utility
void initLift() {
  RLift.resetRotation();;
  RLift.setBrake(brakeType::hold);
  LLift.resetRotation();;
  LLift.setBrake(brakeType::hold);
}

void resetLift() {
  RLift.resetRotation();
  RLift.stop();
  LLift.resetRotation();
  LLift.stop();
}

void resetLiftEncoders() {
  RLift.resetRotation();
  LLift.resetRotation();
}

bool lifting() {
  if (LLift.isSpinning() || RLift.isSpinning())
    return true;
  else
    return false;
}