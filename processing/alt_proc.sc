#include "../include/types.h"

import "c_double_handshake";

behavior Alt_Proc(i_receiver alt_raw, i_sender alt_processed)
{
	
	void main(void) 
	{
		alt_send_data curr, prev;
		alt_processed aproc;
		double dalt, speed;
		unsigned int dtime; 
		char dir;

		//initialize
		alt_raw.receive(&prev, sizeof(prev));
		alt_raw.receive(&curr, sizeof(curr));

		while (1) {
		
			dalt = curr.alt - prev.alt;
			dtime = curr.time - prev.time;

			aproc.delta_alt = dalt/dtime; // actually rate of change
			
			if (curr.alt > prev.alt) {
				aproc.dir = 'u'; // up
			}
			else if (curr.alt < prev.alt) {
				aproc.dir = 'd'; // down
			}
			else {
				aproc.dir = 's'; // steady
			}

			alt_processed.send(&aproc, sizeof(aproc));

			prev = curr;
			alt_raw.receive(&curr, sizeof(curr));
		}
	}

};
