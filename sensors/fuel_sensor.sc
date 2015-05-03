import "c_double_handshake";

behavior Fuel_Sensor(i_receiver fuel_in, i_sender fuel_out)
{
	void main(void)
	{
		fuel_send_data fuel;

		while (1) {
			fuel_in.receive(&fuel, sizeof(fuel));
			fuel_out.send(&fuel, sizeof(fuel));
		}
	}

}
