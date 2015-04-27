#include <stdio.h>
#include "../include/types.h"

import "i_sender";

behavior GPS_stim (i_sender gps_raw, const char * file_name) {
	
	void main(void) {
	
		FILE * fin = fopen(file_name, "r");
		unsigned int timestamp;
		double latitude, longitude;
		char ns, ew;
		gps_send_data sd;
  
		if (fin == NULL) {
			printf("GPS Input File Missing!\n");
			return -1;
		}

		while (1) {
			fscanf(fin,"%u,%lf,%c,%lf,%c\n", &timestamp, &latitude, &ns, &longitude, &ew);

			sd.ts = timestamp;
			sd.lat = latitude;
			sd.ns = ns;
			sd.lon = longitude;
			sd.ew = ew;

			gpas_raw.send(&sd, sizeof(sd));
		}

		return;
	}

}
