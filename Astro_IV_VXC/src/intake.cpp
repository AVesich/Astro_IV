#include "vex.h"

void intakeOp() {
    directionType intakeDir;
    int intakeSp;
    if(Controller1.ButtonL1.pressing()) {
      intakeDir = directionType::fwd;
      intakeSp = 250;
    } else if (Controller1.ButtonL2.pressing()) {
      intakeDir = directionType::rev;
      intakeSp = 450;
    } else {
      intakeSp = 0;
    }
    Intake.spin(intakeDir, intakeSp, velocityUnits::rpm);
}

// UTILITY
void initIntake() {
  // Motors
  Intake.setBrake(brakeType::hold);
  Intake.resetRotation();
}

void resetIntake() {
    Intake.resetRotation();
}

void stopIntake() {
  Intake.stop();
}

// CONTROL
void intakeAuto(int deg, char dir, int sp) {
  resetIntake();

  directionType intakeDir;

  if (dir == 'u')
    intakeDir = directionType::fwd;
  else if (dir == 'd')
    intakeDir = directionType::rev;

  // Set the average intake degrees to 0
  Intake.rotateFor(deg, rotationUnits::deg, sp, velocityUnits::rpm);
}

void intakeAsync(intakeState m_intakeState) {
    if (m_intakeState == INTAKE_IN) {
        Intake.spin(directionType::fwd, 250, velocityUnits::rpm);
    } else if (m_intakeState == INTAKE_OUT) {
        Intake.spin(directionType::rev, 450, velocityUnits::rpm);
    } else if (m_intakeState == INTAKE_OFF) {
      Intake.stop();
    }
    resetIntake();
}