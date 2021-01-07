/* 
   This is where you put a license 
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "tconv.h"

int main (int argc, char **argv)
{
	int cflag = 0 , fflag = 0, verbose = 0;
	const char *options_list = "cfvh";
	int option;
	opterr = 0;  /* do not print default errors */
	double temp, conv_temp;
	int index; 

	/* get options and set flags */
	while ((option = getopt (argc, argv, options_list)) != -1)
	{
		switch (option)
		{
			case 'c':
				if (fflag) { /* mutually exclusive flags */
					print_usage (argv[0], 1, 'f', 'c');
				} 
				cflag = 1;
				break;

			case 'f':
				if (cflag) { /* mutually exclusive flags */
					print_usage (argv[0], 1, 'c', 'f');
				}
				fflag = 1;
				break;

			case 'v':
				verbose = 1;
				break;

			case 'h':
				print_usage (argv[0], 0, '\0', '\0');

			case '?': /* none of the options expect args so this must be a 
						 case of unrecognised option !*/
				print_usage (argv[0], 2, optopt, '\0');

			default: /* something went wrong with getopt, abort! */
				abort ();
		}
	}

	/* if args are passed read from stdin */
	if (optind == argc)
	{
		char *lineptr = NULL;
		size_t n = 0;
		ssize_t nread;
		while ( (nread = getline (&lineptr, &n, stdin)) != -1 )
		{
			if ( !sscanf (lineptr, "%lf", &temp) )
			{
				print_usage (argv[0], 3, '\0', '\0');
			}

			conv_temp = convert_temp (temp, !cflag);

			if (verbose) 
				printf ("%.3f %c = %.3f %c\n", 
						temp, cflag ? 'F' : 'C', conv_temp, cflag ? 'C' : 'F');
			else
				printf ("%.3f\n", conv_temp);
		} 
		free (lineptr); 
		return EXIT_SUCCESS;
	}

	/* for all arguments on the command line do the same processing */
	for (index = optind; index < argc; index++)
	{ 
		/* get non option arguments */ 
		if (sscanf (argv[index], "%lf", &temp) != 1) 
		{
			/* skip to the next argument ? */
			print_usage (argv[0], 3, '\0', '\0');
		} 
		/* calculate based on flags */ 
		conv_temp = convert_temp (temp, !cflag);

		/* print(to stdout) based on verbose flag */
		if (verbose) 
			printf ("%.3f %c = %.3f %c\n", 
					temp, cflag ? 'F' : 'C', conv_temp, cflag ? 'C' : 'F');
		else
			printf ("%.3f\n", conv_temp);
	}
	return EXIT_SUCCESS;
}
