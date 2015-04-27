#include <stdio.h>
#include "../include/types.h"

#import "i_sender";

behavior Fuel_stim(i_sender fuel_raw, const char * fileName)
{
	void main(void)
	{
		FILE *fin = fopen(fileName);
		int time;
		double vol;
		fuel_send_data fsd;
		int f_flag = 1;
		
		if (fin == NULL)
		{
			printf("Fuel Input File Missing!\n");
			return -1;
		}

		while (f_flag != EOF)
		{
			f_flag = fscanf(fin, "%u, %lf", &time, &vol);
			fsd.time = time;
			fsd.vol = vol;
			fuel_raw.send(&fsd, sizeof(fsd));
		}
		
	}
}
