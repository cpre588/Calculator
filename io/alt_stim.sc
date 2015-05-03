#include <stdio.h>
#include "../include/types.h"

import "i_sender";

behavior Alt_Stim(i_sender altraw, in const char * fileName)
{
	void main(void)
	{
		FILE *fin;
		unsigned int time;
		double alt;
		alt_send_data asd;
		
		fin = fopen(fileName, "r");	

		if (fin == NULL)
		{
			printf("Fuel Input File Missing!\n");
			return;
		}

		while (1)
		{
			if (fscanf(fin, "%u, %lf", &time, &alt) == EOF)
				break;
			asd.time = time;
			asd.alt = alt;
			printf("before alt send\n");
			altraw.send(&asd, sizeof(asd));
			printf("after alt send\n");
		}

	}
};
