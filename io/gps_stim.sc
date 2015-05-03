#include <stdio.h>
#include "../include/types.h"

import "i_sender";

behavior Gps_Stim (i_sender gps_raw, const char * file_name) {
	
	void main(void) {
	
		FILE * fin;
		unsigned int timestamp;
		double latitude, longitude;
		char ns, ew;
		gps_send_data sd;

		fin = fopen(file_name, "r");  

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

			gps_raw.send(&sd, sizeof(sd));
		}

	}

};
