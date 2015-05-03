#include "../include/types.h"
#include <stdio.h>

import "c_double_handshake";

behavior Gps_Sensor(i_receiver gpsin, i_sender gpsout)
{
	
	void main(void)
	{
		gps_send_data gps;
		
		while (1) {
			gpsin.receive(&gps, sizeof(gps));
			gpsout.send(&gps, sizeof(gps));
		}
	}
};
