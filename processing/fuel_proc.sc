#include "../include/types.h"

import "c_double_handshake";

#define speed_GPH_ratio 10

behavior Fuel_Proc(i_receiver fuel_raw, i_sender fuel_processed/*, in double shared_speed*/)
{
	void main(void)
	{
		fuel_send_data fraw;
		fuel_processed fproc;
		double currentGPH;
		
		while (1)
		{
			fuel_raw.receive(&fraw, sizeof(fraw));

			currentGPH = /*shared_speed/*/speed_GPH_ratio;
			fproc.time_left = fraw.vol/currentGPH;
			fproc.fuel_left = fraw.vol;
			fproc.up_time = fraw.time;
			
			fuel_processed.send(&fproc, sizeof(fproc));
		}
		
	}
};
