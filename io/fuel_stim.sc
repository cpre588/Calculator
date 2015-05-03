#include <stdio.h>
#include "../include/types.h"

import "i_sender";

behavior Fuel_Stim(i_sender fuelraw, in const char * fileName)
{
	void main(void)
	{
		FILE *fin;
		unsigned int time;
		double vol;
		fuel_send_data fsd;
		
		fin = fopen(fileName, "r");

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
			fuelraw.send(&fsd, sizeof(fsd));
		}
		printf("WAITING FOR FUEL DATA...\n");
	}
};
