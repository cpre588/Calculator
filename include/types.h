#ifndef __TYPES
#define __TYPES 1

typedef struct gps_send_data {
	unsigned int ts;
	double lat, lon;
	char ns, ew;	
};

typedef struct alt_send_data {
	unsigned int time;
	double alt;
};

typedef struct fuel_send_data {
	unsigned int time;
	double vol;
};

#endif
