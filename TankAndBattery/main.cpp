
#include <time.h>
#include "Tank.h"
#include "Matrix33.h"
#include "Vector2D.h"

void main() {
	Tank* tank = new Tank();
	//tank->SetPos(Vector2D(5.0, 5.0));
	int now = clock() / 1000;
	int tankTime, batTime, logTime;
	tankTime = batTime = logTime = now;
	tank->debuglog();
	
	while (true)
	{
		now = clock() / 1000;
		//��Ԃ̊p�x���T�b��ɂP�x���炷
		if ( 5 < (now - tankTime)) {
			double radian = 1 * 3.14 / 180;
			tank->Rotate(radian);
			tankTime = now;
		}
		//�C��̊p�x��1�b���45�x���炷
		if (1 < (now - batTime)) {
			double radian = 45 * 3.14 / 180;
			batTime = now;
		}
		if (30 < (now - logTime)) {
			tank->debuglog();
			logTime = now;
		}
	}
}