import "io/gps_stim";
import "io/alt_stim";
import "io/fuel_stim";
import "sensors/gps_sensor";
import "sensors/alt_sensor";
import "sensors/fuel_sensor";
import "processing/gps_proc";
import "processing/alt_proc";
import "processing/fuel_proc";
import "communication/forward";
import "io/monitor";
import "c_double_handshake";

behavior Main
{
	c_double_handshake gps_stim_sensor, gps_sensor_proc, gps_proc_forward;
	c_double_handshake alt_stim_sensor, alt_sensor_proc, alt_proc_forward;
	c_double_handshake fuel_stim_sensor, fuel_sensor_proc, fuel_proc_forward;
	c_double_handshake forward_monitor;
	//double shared_speed;
	
	Gps_Stim B0(gps_stim_sensor, "io/gps.txt");
	Alt_Stim B1(alt_stim_sensor, "io/alt.txt");
	Fuel_Stim B2(fuel_stim_sensor, "io/fuel.txt");
	
	Gps_Sensor B3(gps_stim_sensor, gps_sensor_proc);
	Alt_Sensor B4(alt_stim_sensor, alt_sensor_proc);
	Fuel_Sensor B5(fuel_stim_sensor, fuel_sensor_proc);
	
	Gps_Proc B6(gps_sensor_proc, gps_proc_forward/*, shared_speed*/);
	Alt_Proc B7(alt_sensor_proc, alt_proc_forward);
	Fuel_Proc B8(fuel_sensor_proc, fuel_proc_forward/*, shared_speed*/);

	Forward B9(gps_proc_forward, alt_proc_forward, fuel_proc_forward, forward_monitor);
	
	Monitor B10(forward_monitor);
	
	int main(void)
	{
		par {
			B0.main();
			B1.main();
			B2.main();
			B4.main();
			B5.main();
			B6.main();
			B7.main();
			B8.main();
			B9.main();
			B10.main();
		}
		return 0;
	}
};
