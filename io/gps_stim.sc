#include <stdio.h>
#include "../include/types.h"

import "c_double_handshake";

behavior Gps_Stim (i_sender gpsraw, in const char * filename) {
	
	void main(void) {
	
		FILE * fin;
		unsigned int timestamp;
		double latitude, longitude;
		char ns, ew;
		gps_send_data sd;

		fin = fopen(filename, "r");  

		if (fin == NULL) {
			printf("GPS Input File Missing!\n");
			return;
		}

		while (1) {
			if (fscanf(fin,"%u,%lf,%c,%lf,%c\n", &timestamp, &latitude, &ns, &longitude, &ew) == EOF)
				 break;

			sd.ts = timestamp;
			sd.lat = latitude;
			sd.ns = ns;
			sd.lon = longitude;
			sd.ew = ew;
			gpsraw.send(&sd, sizeof(sd));
		}
		
		printf("WAITING FOR GPS DATA...\n");
	}

};
