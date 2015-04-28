#include <stdio.h>
#include "../include/types.h"

#import "i_sender";

behavior Fuel_stim(i_sender fuel_raw, const char * fileName)
{
	void main(void)
	{
		FILE *fin = fopen(fileName, "r");
		unsigned int time;
		double vol;
		fuel_send_data fsd;
		
		if (fin == NULL)
		{
			printf("Fuel Input File Missing!\n");
			return;
		}

		while (1)
		{
			if (fscanf(fin, "%u, %lf", &time, &vol) == EOF)
				break;
			fsd.time = time;
			fsd.vol = vol;
			fuel_raw.send(&fsd, sizeof(fsd));
		}
		
	}
};
