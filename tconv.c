/* implementation of functions prototyped in tconv.h */

#include <stdio.h>
#include <stdlib.h>

double convert_temp (double temp, int from_c_to_f)
{
	/*
		description: convert and return temperature from celsis to farenheit
		and vice versa based on the boolean from_c_to_f 
	*/
	if (from_c_to_f)
	{
		return 32.0 + (9.0 / 5.0) * temp;
	}
	return (5.0 / 9.0) * (temp - 32.0);
}

void print_usage (char *prgname, int type_of_error, char opt1, char opt2)
{
/* description: print correct usage and exit 
   params:
   		1. prgname = name of the program collected from main
   		2. type_of_error = to handle multiple error types:
   		    0 = getting help
   		    1 = conflicting options
   		    2 = unrecognised options 
   		    3 = invalid parguments
   		3. opt1, opt2 = misused options collected from main (used when incorrect
		   arguments are passed 
*/
	switch (type_of_error)
	{
		case 1:
			fprintf (stderr, "%s: conflicting options -- '%c' and '%c'\n",
					prgname, opt1, opt2);
			break;
		case 2:
			fprintf (stderr, "%s: unrecognised option -- '%c'\n", prgname, opt1);
			break;
		case 3:
			fprintf (stderr, "%s: invalid argument\n", prgname);
			break;
		case 0: 
			/* always print usage due to fall through */
			fprintf (stderr, "%s (" VERSION
					"): convert temperature between celsius and farenheit\n", prgname);
			fprintf (stderr, "Usage: %s [-c|-f][-v][-h] [TEMPERATURE]...\n", prgname);
			fprintf (stderr, "Options:\n" 
					"\t-c\tconvert to celsius\n" 
					"\t-f\tconvert to farenheit (default)\n"
					"\t-v\tbe verbose about the conversion\n"
					"\t-h\tprint this message and exit\n");
			break;
	}
	/* good idea to exit from here or should you always exit from main ? */
	exit(EXIT_FAILURE);
}
