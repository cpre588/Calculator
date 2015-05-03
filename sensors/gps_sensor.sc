#include "../include/types.h"
#include <stdio.h>

import "c_double_handshake";

behavior Gps_Sensor(i_receiver gpsin, i_sender gpsout)
{
	
	void main(void)
	{
		gps_send_data gps;
		
		while (1) {
			printf("SOMETHING ELSE\n");
			gpsin.receive(&gps, sizeof(gps));
			printf("DONT GET FUCKED\n");
			gpsout.send(&gps, sizeof(gps));
			printf("GET FUCKED\n");
		}
	}
};
