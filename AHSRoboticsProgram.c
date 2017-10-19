#pragma config(Motor,  port2,           launcherLockServo, tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//



#define LAUNCHER_UNLOCK_POSITION -127
#define LAUNCHER_LOCK_POSITION 0

bool bLauncherIsLocked;

task main()
{
	// Declare variables
	bLauncherIsLocked = false;

	while (true)
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

}
