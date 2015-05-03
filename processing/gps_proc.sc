#include <math.h>

import "c_double_handshake"

#define lat_adjust(x) 111.0000-1.2333*x

const double lat_diff 111.0000;

behavior Gps_Proc (i_receiver gps_raw, i_sender gps_processed, out double shared_speed)
{

	void main(void)
	{
		gps_send_data prev, curr;
		gps_processed gproc;
		double dlat, dlon, ddis, alat; 
		unsigned int dtime;
		double speed;

		prev.ts = 0;
		prev.lat = 0.0;
		prev.lon = 0.0;
		prev.ew = 'n';
		prev.ns	= 'w';
		
		// intialize
		gps_raw.receive(&prev, sizeof(prev));
		gps_raw.receive(&curr, sizeof(curr));

		while (1) {
			dlat = (curr.lat-prev.lat)*(curr.lat-prev.lat); // in degrees
			dlon = (curr.lon-prev.lon)*(curr.lon-prev.lon); // in degrees
			alat = (curr.lat+prev.lat)/2; // average latitude			
			dlat = dlat*lat_diff; // in km
			dlon = dlon*lat_adjust(alat); // in km
			
			dlon = dlat+dlon; // recycle dlon for total dist

			ddis = sqrt(dlon); // distance between two points
	
			dtime = curr.ts-prev.ts;

			gproc.speed = ddis/dtime;
			
			shared_speed = gproc.speed;
			
			if (curr.lat > prev.lat && curr.ns == 'n') {
				gproc.dir1 = 'n';
			}
			else if (curr.lat < prev.lat && curr.ns == 'n') {
				gproc.dir1 = 's';
			}
			else if (curr.lat > prev.lat && curr.ns == 's') {
				gproc.dir1 = 's';
			}
			else {
				gproc.dir1 = 'n';
			}
			
			if (curr.lon < prev.lon && curr.ew == 'w') {
				gproc.dir2 = 'e';
			}
			else if (curr.lon > prev.lon && curr.ew == 'w') {
				gproc.dir2 = 'w';
			}
			else if (curr.lon < prev.lon && curr.ew == 'e') {
				gproc.dir2 = 'w';
			}
			else {
				gproc.dir2 = 'e';
			}
			
			gps_processed.send(&gproc, sizeof(gproc));			
			
			prev = curr;
			gps_raw.receive(&curr, sizeof(curr));

		}
	}
};
