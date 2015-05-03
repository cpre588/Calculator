#include "../include/types.h"

import "c_double_handshake";

behavior Forward(i_receiver gpsprocessed, i_receiver altprocessed,
		i_receiver fuelprocessed, i_sender forwarddata)
{
	
	void main(void)
	{
		gps_processed gps;
		alt_processed alt;
		fuel_processed fuel;	
		forward_data data;	

		while(1)
		{
			gpsprocessed.receive(&gps, sizeof(gps));
			altprocessed.receive(&alt, sizeof(alt));
			fuelprocessed.receive(&fuel, sizeof(fuel));
			
			data.gps_speed = gps.speed;
			data.gps_dir1 = gps.dir1;
			data.gps_dir2 = gps.dir2;
			data.alt_speed = alt.delta_alt;
			data.alt_dir = alt.dir;
			data.fuel_time_left = fuel.time_left;
			data.fuel_fuel_left = fuel.fuel_left;

			forwarddata.send(&data, sizeof(data));	
		}

	}

};
