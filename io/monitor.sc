#include "../include/types.h"
#include <stdio.h>
#include <math.h>

import "c_double_handshake";

behavior Monitor(i_receiver forwarddata)
{
	forward_data data;
	FILE *fout;

	void main(void)
	{
		while (1) {
			forwarddata.receive(&data, sizeof(data));
			printf("Speed: %02.2f m/s, Dir: %c%c | Alt RoC: %02.2f m/s, Dir: %c | Fuel Time: %04.2f hrs, Fuel Left: %f%%\n",
			data.gps_speed*1000, data.gps_dir1, data.gps_dir2, fabs(data.alt_speed), data.alt_dir, 
			data.fuel_time_left/1440, data.fuel_fuel_left/5);
		}

		fclose(fout);

		return;
	}

};
