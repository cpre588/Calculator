import "c_double_handshake";

behavior Monitor(i_receiver foward_data)
{
	forward_data data;
	FILE *fout;

	void main(void)
	{
		while (1) {
			forward_data.receive(&data, sizeof(data));
			printf("GPS:  Speed=%f, %c%c\n", 
			data.gps_speed, data.gps_dir1, data.gps_dir2);
			printf("ALT:  RoC=%f, %c\n", data.alt_speed, data.alt_dir);
			printf("FUEL: %f min, %f\%\n", 
			data.fuel_time_left, data.fuel_fuel_left); 
		}

		fclose(fout);

		return;
	}

};
