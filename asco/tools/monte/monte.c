/*
 * Copyright (C) 1999-2011 Joao Ramos
 * Your use of this code is subject to the terms and conditions of the
 * GNU general public license version 2. See "COPYING" or
 * http://www.gnu.org/licenses/gpl.html
 */

#include <stdio.h>
/*#include <ctype.h>*/
/*#include <math.h>*/
/*#include <setjmp.h>*/
/*#include <assert.h>*/
#include <stdlib.h>
#include <string.h>


#include "auxfunc.h"
#include "auxfunc_monte.h"




/***************************************************************/
/*MonteCarlo ***************************************************/
/***************************************************************/




/*##############################################################################*/
/*################      M A I N              P R O G R A M      ################*/
/*##############################################################################*/
int main(int argc, char *argv[])
{
	int ii;
	char fileMC[SHORTSTRINGSIZE];


	/**/
	/*Step1: Check input arguments*/
	if (argc != 4) { /* number of arguments */
		printf("\nUsage : monte -<simulator> <inputfile>.* <configfile>\n");
		printf("\nExamples:\n");
		printf("          monte -eldo    <inputfile>.cir <configfile> \n");
		printf("          monte -hspice  <inputfile>.sp <configfile> \n");
		printf("\n\n\n");
	exit(EXIT_FAILURE);
	}


	/**/
	/*Step2: Initialization of all variables and strucutres*/
	if (1) { /*is it first time the optimization is runned?*/
		if (*argv[1] == 45) /* 45="-" */
			*argv[1]++;

		spice=0;
		switch(*argv[1]) {
			case 'e': /*Eldo*/
				if (!strcmp(argv[1], "eldo"))
					spice=1;
				break;
			case 'h': /*HSPICE*/
				if (!strcmp(argv[1], "hspice"))
					spice=2;
				break;
			case 'l': /*LTspice*/
				printf("monte.c -- Unsupport SPICE simulator: %s\n", argv[1]);
				break;
			case 's': /*Spectre*/
				printf("monte.c -- Unsupport SPICE simulator: %s\n", argv[1]);
				break;
			case 'r': /*rosen*/
				printf("monte.c -- Unsupport SPICE simulator: %s\n", argv[1]);
				break;
			default:
				printf("monte.c -- Unsupport SPICE simulator: %s\n", argv[1]);
				exit(EXIT_FAILURE);
		}
		if (spice==0) {
			printf("monte.c -- Unsupport SPICE simulator: %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}


	/**/
	/*Step3: */
	strcpy(fileMC, argv[2]);
	ii=strpos2(fileMC, ".", 1);
	if (ii) /*filename is "filename.xx.xx"*/
		fileMC[ii-1]='\0';
	strcat(fileMC, ".mc");

	
	/**/
	/*Step4: */
	MonteCarlo(argv[3], argv[2], fileMC);
	exit(EXIT_SUCCESS);
}
