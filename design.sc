import "c_double_handshake";

behavior Design(i_receiver gps_stim, i_receiver alt_stim, i_receiver fuel_stim, i_sender to_monitor)
{
	c_double_handshake gps_sensor_proc, gps_proc_forward;
	c_double_handshake alt_sensor_proc, alt_proc_forward;
	c_double_handshake fuel_sensor_proc, fuel_proc_forward;
	double shared_speed;

	Gps_Sensor B3(gps_stim_sensor, gps_sensor_proc);
	Alt_Sensor B4(alt_stim_sensor, alt_sensor_proc);
	Fuel_Sensor B5(fuel_stim_sensor, fuel_sensor_proc);

	Gps_Proc B6(gps_sensor_proc, gps_proc_forward, shared_speed);
        Alt_Proc B7(alt_sensor_proc, alt_proc_forward);
        Fuel_Proc B8(fuel_sensor_proc, fuel_proc_forward, shared_speed);
	
	Forward B9(gps_proc_forward, alt_proc_forward, fuel_proc_forward, to_monitor);
        
	void main(void)
	{
		par {
			B3.main();
			B4.main();
			B5.main();
			B6.main();
			B7.main();
			B8.main();
			B9.main();
		}
	}
};
