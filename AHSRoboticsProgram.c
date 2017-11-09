#pragma config(Motor,  port2,           launcherLockServo, tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           wheelLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           wheelRight,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define LAUNCHER_UNLOCK_POSITION -127
#define LAUNCHER_LOCK_POSITION 0

bool bLauncherIsLocked;
int deadBand;

void UpdateServos();
void UpdateWheels();


int AbsoluteValue(int value)
{
	if (value < 0)
	{
		return value * -1;
	}
	return value;
}

task main()
{
	// Declare variables
	bLauncherIsLocked = false;
	deadBand = 17;

	while (true)
	{
		UpdateServos(); // Run the Code contained within "UpdateServos()"
		UpdateWheels(); // Run the Code contained within "UpdateWheels()"

	}
}


// Function definitions
void UpdateServos()
{
	if (vexRT[Btn8R]) // if Button 8R is pressed
	{
		bLauncherIsLocked = !bLauncherIsLocked; // Toggle the launcher lock
	}

	if (bLauncherIsLocked) // If the launcher is in the locked state
	{
		if (motor[launcherLockServo] != LAUNCHER_LOCK_POSITION) // If it is not already in the lock position
		{
			motor[launcherLockServo] = LAUNCHER_LOCK_POSITION; // Set it to the lock position
		}
	}
	else // Otherwise it isn't in the lock state
	{
		if (motor[launcherLockServo] != LAUNCHER_UNLOCK_POSITION) // If it is not already in the unlock position
		{
			motor[launcherLockServo] = LAUNCHER_UNLOCK_POSITION; // Set it to the unlock position
		}
	}
}

void UpdateWheels()
{
	int channel2 = vexRT[Ch2];
	int channel3 = vexRT[Ch3];

	if (AbsoluteValue(channel2) > deadBand)
	{
		motor[wheelRight] = channel2; // Set the right motor equal to the right joystick h
	}
	if (AbsoluteValue(channel3) > deadBand)
	{
		motor[wheelLeft] = channel3; // Set the left motor equal to the left joystick pitch
	}
}
