/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

// Mach8 drive library
#include "Mach8Inc/Api.h"
using namespace mh8_Drive;
using namespace mh8_Variables;
using namespace mh8_Sensors;

// Extern drivetrain
extern mh8_Drivetrain m_driveTrain;

// Extern auto nunmber
extern int currAuto;

// Auto task variables
extern double liftTarget;
extern double mogoLiftTarget;
extern double intakeTarget;

// Custom header files
#include "drive.h"
#include "intake.h"
#include "lift.h"
#include "mogolift.h"
#include "autoselector.h"
#include "auto.h"

using namespace std;

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)