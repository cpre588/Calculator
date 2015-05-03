#include "../include/types.h"

import "c_double_handshake";

behavior Alt_Sensor (i_receiver alt_in, i_sender alt_out)
{
	
	void main(void)
	{
		alt_send_data alt;

		while(1) {
			alt_in.receive(&alt, sizeof(alt));
			alt_out.send(&alt, sizeof(alt));
		}

	}

};
