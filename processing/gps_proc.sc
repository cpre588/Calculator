import "c_double_handshake"

behavior Gps_Proc (i_receiver gps_raw, i_sender gps_processed)
{

	void main(void)
	{
		gps_send_data prev, curr;

		prev.ts = 0;
		prev.lat = 0.0;
		prev.lon = 0.0;
		prev.ew = 'n';
		prev.ns	= 'w';
	}
}
