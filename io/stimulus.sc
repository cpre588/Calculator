import "i_sender";
import "gps_stim";
import "alt_stim";
import "fuel_stim";

behavior stim(i_sender gps_raw, i_sender fuel_raw, i_sender alt_raw) {

	GPS_stim g_stim(gps_raw, "gps.txt");
	Alt_stim a_stim(alt_raw, "alt.txt");
	Fuel_stim f_stim(fuel_raw, "fuel.txt");
	
	void main(void)
	{
		par {
			g_stim.main();
			a_stim.main();	
			f_stim.main();
		}
	}
};
