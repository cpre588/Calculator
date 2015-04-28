#include <stdio.h>
#include "../include/types.h"

#import "i_sender";

behavior Alt_stim(i_sender alt_raw, const char * fileName)
{
	void main(void)
	{
		FILE *fin = fopen(fileName, "r");
		unsigned int time;
		double alt;
		alt_send_data asd;
		
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
			alt_raw.send(&asd, sizeof(asd));
		}

	}
};
