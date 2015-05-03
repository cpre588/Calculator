import "c_double_handshake";

behavior Foward(i_receiver gps_processed, i_receiver alt_processed,
		i_receiver fuel_processed, i_sender forward_data)
{
	
	void main(void)
	{
		gps_processed gps;
		alt_processed alt;
		fuel_processed fuel;	
		forward_data data;	

		while(1)
		{
			gps_processed.receive(&gps, sizeof(gps));
			alt_processed.receive(&alt, sizeof(alt));
			fuel_processed.receive(&fuel, sizeof(fuel));
			
			data.gps_speed = gps.speed;
			data.gps_dir1 = gps.dir1;
			data.gps_dir2 = gps.dir2;
			data.alt_speed = alt.delta_alt;
			data.alt_dir = alt.dir;
			data.fuel_time_left = fuel.time_left;
			data.fuel_fuel_left = fuel.fuel_left;

			forward_data.send(&data, sizeof(data));	
		}

	}

};
