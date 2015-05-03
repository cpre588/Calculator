#include "../include/types.h"

import "c_double_handshake";

behavior Gps_Sensor(i_receiver gps_in, i_sender gps_out)
{
	
	void main(void)
	{
		gps_send_data gps;
		
		while (1) {
			gps_in.receive(&gps, sizeof(gps));
			gps_out.send(&gps, sizeof(gps));
		}
	}
};
