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
			printf("GPS:  Speed=%f, %c%c\n", 
			data.gps_speed, data.gps_dir1, data.gps_dir2);
			printf("ALT:  RoC=%f, %c\n", data.alt_speed, data.alt_dir);
			printf("FUEL: %f min, %f percent\n", 
			data.fuel_time_left, data.fuel_fuel_left); 
			printf("Speed: %f m/s, Dir: %c%c | Alt RoC %f m/s, Dir:	%c | Fuel Time: %f min, Fuel Left: %f%%\n",
			data.gps_speed*1000, data.gps_dir1, data.gps_dir2, data.alt_speed, data.alt_dir, 
			data.fuel_time_left, data.fuel_fuel_left);
		}

		fclose(fout);

		return;
	}

};
