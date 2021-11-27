#ifndef _INTAKE_H_
#define _INTAKE_H_

void intakeOp();

void stopIntake();

void initIntake();
void resetIntake();

void intakeAuto(int deg, int sp);
enum intakeState { INTAKE_IN, INTAKE_OUT, INTAKE_AUTO, INTAKE_OFF };
void intakeAsync(intakeState m_intakeState);

#endif