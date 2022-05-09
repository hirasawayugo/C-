
#include <time.h>
#include "Tank.h"
#include "Battery.h"
#include "Matrix33.h"
#include "Vector2D.h"
#include "Calculator.h"

void main() {
	Calculator calc;
	Tank* tank = new Tank(2, 3);
	Battery* battery = new Battery(0.5, 1);
	tank->AddBattery(battery);

	int now = clock() / 1000;
	int tAngleTime, tAdvTime, bAngleTime, logTime;
	tAngleTime = tAdvTime = bAngleTime = logTime = now;
	tank->debuglog();
	battery->debuglog();
	
	while (true)
	{
		now = clock() / 1000;
		//íÔ‚ÌŠp“x‚ğ‚T•bŒã‚É‚P“x‰ñ“]
		if ( 5 <= (now - tAngleTime)) {
			tank->Rotate(calc.Radians(1));
			tAngleTime = now;
		}
		//–C‘ä‚ÌŠp“x‚ğ1•bŒã‚É45“x‰ñ“]
		if (1 <= (now - bAngleTime)) {
			battery->Rotate(calc.Radians(-45));
			bAngleTime = now;
		}
		//íÔ‚ÌŠp“x‚ğ10•bŒã‚É‚P’PˆÊ‘Oi
		if (10 <= (now - tAdvTime)) {
			tank->Forward(1);
			tAdvTime = now;
		}
		if (30 <= (now - logTime)) {
			tank->debuglog();
			battery->debuglog();
			logTime = now;
		}
	}
}