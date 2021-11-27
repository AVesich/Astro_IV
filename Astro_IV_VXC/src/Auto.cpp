#include "vex.h"

/*
  // TURNS:
  // 525 deg input -> 90 deg turn
*/

// TASKS
task liftTask;
task mogoLiftTask;
task intakeTask;

void leftTip() {
  flipoutLift();
  m_driveTrain.mh8_Turn(90, 100, 'r');
  m_driveTrain.mh8_DriveStraight(48, 500, 'b');
  liftClawAuto(true);
  m_driveTrain.mh8_Turn(60, 100, 'r');
  m_driveTrain.mh8_DriveStraight(38, 500, 'f');
  liftClawAuto(false);
  m_driveTrain.mh8_DriveStraight(16, 500, 'f');
  m_driveTrain.mh8_Turn(620, 100, 'l');
  mogoAuto(580, 'd');
  m_driveTrain.mh8_DriveStraight(9, 500, 'f');
  mogoAuto(580, 'u');
  liftAuto(100, 'u');
  intakeAsync(INTAKE_IN);
  m_driveTrain.mh8_DriveStraight(9, 500, 'b');
  wait(1, sec);
  intakeAsync(INTAKE_OFF);
  liftAuto(100, 'd');
}
void leftClaw() { // TEST AUTO
   m_driveTrain.mh8_driveToCoord(0.73, -1.18, 90, 500, false);
}

void rightTip() {
  m_driveTrain.mh8_DriveStraight(44, 550, 'b');
  liftClawAuto(true);
  m_driveTrain.mh8_DriveStraight(24, 550, 'f');
  m_driveTrain.mh8_DriveStraight(4, 550, 'f');
  liftClawAuto(false);
  m_driveTrain.mh8_Turn(570, 100, 'l');
  liftTarget = 10;
  mogoAuto(580, 'd');
  m_driveTrain.mh8_DriveStraight(12, 550, 'f');
  mogoAuto(580, 'u');
  intakeAsync(INTAKE_IN);
  liftTarget = 0;
  m_driveTrain.mh8_DriveStraight(28, 550, 'b');
  intakeAsync(INTAKE_OFF);
  liftClawAuto(false);
  m_driveTrain.mh8_DriveStraight(12, 550, 'f');
  m_driveTrain.mh8_Turn(210, 100, 'r');
  m_driveTrain.mh8_DriveStraight(36, 550, 'b');
  liftClawAuto(true);
  m_driveTrain.mh8_DriveStraight(40, 550, 'f');
  liftClawAuto(false);
}
void rightClaw() {}

void winPoint() { // TEMP SKILLS
  flipoutLift();
  m_driveTrain.mh8_Turn(90, 100, 'r');
  mogoAuto(580, 'd');
  m_driveTrain.mh8_DriveStraight(48, 500, 'f');
  mogoAuto(580, 'u');
  m_driveTrain.mh8_Turn(90, 100, 'l');
  m_driveTrain.mh8_DriveStraight(56, 500, 'f');
  mogoAuto(580, 'd');
  m_driveTrain.mh8_DriveStraight(48, 500, 'b');
  mogoAuto(580, 'u');
}

void skills() {
  liftTask = task (liftAsync); // Start lift task
  liftTarget = 0;
  //liftAsync(LIFT_FLIPOUT);
  mogoAuto(580, 'd');
  m_driveTrain.mh8_DriveStraight(9, 500, 'f');
  mogoAuto(580, 'u');
  mogoLiftTask = task (mogoLiftAsync); // Start mogo lift task
  m_driveTrain.mh8_DriveStraight(9, 500, 'b');
  m_driveTrain.mh8_Turn(500, 100, 'l');
  m_driveTrain.mh8_DriveStraight(24, 500, 'f');
  liftTarget = 0;
  m_driveTrain.mh8_driveToCoord(0.32, -1.01, 293, 500, true);
  liftClawAuto(true);
  wait(250, msec);
  liftTarget = 550;
  wait(250, msec);
  m_driveTrain.mh8_driveToCoord(-0.85, -0.75, 290, 500, true);
  m_driveTrain.mh8_driveToCoord(-0.85, -0.2, 350, 500, true);
  m_driveTrain.mh8_driveToCoord(-0.96, -0.2, 283, 500, true);
  liftTarget = 350;
  wait(250, msec);
  liftClawAuto(false);
  m_driveTrain.mh8_DriveStraight(2, 500, 'f');
  liftTarget = 550;
  wait(100, msec);
  m_driveTrain.mh8_driveToCoord(-0.98, -0.15, 175, 500, true);
  liftTarget = 0;
  mogoLiftTarget = -590;
  wait(250, msec);
  m_driveTrain.mh8_driveToCoord(-0.98, -1.21, 175, 500, true);
  liftClawAuto(true);
  wait(100, msec);
  m_driveTrain.mh8_driveToCoord(-0.98, -1.1, 175, 500, false);
  liftTarget = 550;
  m_driveTrain.mh8_driveToCoord(0.63, 0.76, 210, 500, false);
  m_driveTrain.mh8_DriveStraight(50, 500, 'b');
  //m_driveTrain.mh8_driveToCoord(0.63, 0.76, 95, 500, false);
  //m_driveTrain.mh8_driveToCoord(0.73, -1.18, 315, 500, false);
  liftTask.stop();
  mogoLiftTask.stop();
}

void runAuto() {
  Brain.Screen.printAt(24, 128, "Running Auto");
  switch(currAuto){
    case 0: leftTip(); break;
    case 1: leftClaw(); break;
    case 2: rightTip(); break;
    case 3: rightClaw(); break;
    case 4: winPoint(); break;
    case 5: skills(); break;
  }
}