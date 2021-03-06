#include "vex.h"

// Used for drive toggle
bool driveReversed = false;

double x;
double y;

void revDrive() { driveReversed = !driveReversed; }

void driveOp() {
  // Store the x and y joystick values to their respective variable
  x = Controller1.Axis4.value();
  y = Controller1.Axis3.value();

  // Prevent drift
  if (fabs(x) < 0.15)
    x = 0;
  if (fabs(y) < 0.15)
    y = 0;
  
  // Flip the y input if necessary
  if (driveReversed)
    y = -y;

    // Convert controller values to volts
  x *= 240; // multiplies by 12, the proportion of max mvolts to max axis value
  y *= 240; // multiplies by 12, the proportion of max mvolts to max axis value

  // Determine the brake mode to use
  if (fabs(y) >= 80 && fabs(x) <= 25) { // If mostly going straight, use "coast"
    m_driveTrain.mh8_setBrake('c'); // Set brake mode to coast
  } else if (fabs(x) > 25 && fabs(y) < 80) { // If mostly going straight, use "brake"
    m_driveTrain.mh8_setBrake('b'); // Set brake mode to brake
  }

  // Make the drivetrain move
  m_driveTrain.mh8_arcadeDrive(x, y);
}