#ifndef __TYPES
#define __TYPES 1

typedef struct gps_send_data {
	unsigned int ts;
	double lat, lon;
	char ns, ew;	
};

typedef struct gps_processed {
	double speed;
	char dir1;
	char dir2;
};

typedef struct alt_send_data {
	unsigned int time;
	double alt;
};

typedef struct alt_processed {
	double delta_alt;
	char dir;
};

typedef struct fuel_send_data {
	unsigned int time;
	double vol;
};

typedef struct fuel_processed {
	double time_left;
	double fuel_left;
};

#endif
