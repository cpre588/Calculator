typedef struct gps_send_data_t {
	unsigned int ts;
	double lat, lon;
	char ns, ew;	
} gps_send_data;

typedef struct gps_processed_t {
	double speed;
	char dir1;
	char dir2;
} gps_processed;

typedef struct alt_send_data_t {
	unsigned int time;
	double alt;
} alt_send_data;

typedef struct alt_processed_t {
	double delta_alt;
	char dir;
} alt_processed;

typedef struct fuel_send_data_t {
	unsigned int time;
	double vol;
} fuel_send_data;

typedef struct fuel_processed_t {
	double time_left;
	double fuel_left;
} fuel_processed;
