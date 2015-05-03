#include "../include/types.h"

import "c_double_handshake";

#define speed_GPH_ratio 10

behavior Fuel_Proc(i_receiver fuelraw, i_sender fuelprocessed, in double sharedspeed)
{
	void main(void)
	{
		fuel_send_data fraw;
		fuel_processed fproc;
		double currentGPH;
		
		while (1)
		{
			fuelraw.receive(&fraw, sizeof(fraw));

			currentGPH = sharedspeed/speed_GPH_ratio;
			fproc.time_left = fraw.vol/currentGPH;
			fproc.fuel_left = fraw.vol;
			fproc.up_time = fraw.time;
			
			fuelprocessed.send(&fproc, sizeof(fproc));
		}
		
	}
};
