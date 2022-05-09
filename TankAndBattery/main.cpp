
#include <time.h>
#include "Tank.h"
#include "Matrix33.h"
#include "Vector2D.h"
#include "Calculator.h"

void main() {
	Tank* tank = new Tank();
	Calculator calc;
	int now = clock() / 1000;
	int tAngleTime, tAdvTime, bAngleTime, logTime;
	tAngleTime = tAdvTime = bAngleTime = logTime = now;
	tank->debuglog();
	
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
			tank->BatRotate(calc.Radians(-45));
			bAngleTime = now;
		}
		//íÔ‚ÌŠp“x‚ğ10•bŒã‚É‚P’PˆÊ‘Oi
		if (10 <= (now - tAdvTime)) {
			tank->Advance(1);
			tAdvTime = now;
		}
		if (30 <= (now - logTime)) {
			tank->debuglog();
			logTime = now;
		}
	}
}