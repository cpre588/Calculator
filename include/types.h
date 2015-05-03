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

typedef struct forward_data_t {
	double gps_speed;
	char gps_dir1, gps_dir2;
	double alt_speed;
	char alt_dir;
	double fuel_time_left;
	double fuel_fuel_left;
} forward_data;
