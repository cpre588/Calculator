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
import "design";
import "c_double_handshake";

behavior Main
{
	c_double_handshake gps_stim_sensor;
	c_double_handshake alt_stim_sensor;
	c_double_handshake fuel_stim_sensor;
	c_double_handshake forward_monitor;
	
	Gps_Stim B0(gps_stim_sensor, "io/gps.txt");
	Alt_Stim B1(alt_stim_sensor, "io/alt.txt");
	Fuel_Stim B2(fuel_stim_sensor, "io/fuel.txt");
	
	Design B11(gps_stim_sensor, alt_stim_sensor, fuel_stim_sensor, forward_monitor);

	Monitor B10(forward_monitor);
	
	int main(void)
	{
		par {
			B0.main();
			B1.main();
			B2.main();
			B10.main();
			B11.main();
		}
		return 0;
	}
};
