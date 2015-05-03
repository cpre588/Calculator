#include "../include/types.h"
#include <stdio.h>

import "c_double_handshake";

behavior Monitor(i_receiver forwarddata)
{
	forward_data data;
	FILE *fout;

	void main(void)
	{
		while (1) {
			forwarddata.receive(&data, sizeof(data));
			printf("Speed: %f m/s, Dir: %c%c | Alt RoC %f m/s, Dir:	%c | Fuel Time: %f min, Fuel Left: %f%%\n",
			data.gps_speed*1000, data.gps_dir1, data.gps_dir2, data.alt_speed, data.alt_dir, 
			data.fuel_time_left, data.fuel_fuel_left/500);
		}

		fclose(fout);

		return;
	}

};
