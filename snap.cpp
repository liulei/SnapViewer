#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	"snap.h"

Snap::Snap(){
	Time	=	0.0;
	Redshift=	0.0;

	BoxSize	=	0.0;
	NumPart	=	0;
	
	Omega0	=	0.0;
	OmegaLambda	=	0.0;
	HubbleParam	=	0.0;

	P	=	NULL;
}

Snap::~Snap(){
	free(++P);
}

/* Here we load a snapshot file. It can be distributed
 * onto several files (for files>1).
 * The particles are brought back into the order
 * implied by their ID's.
 * A unit conversion routine is called to do unit
 * conversion, and to evaluate the gas temperature.
 */
void Snap::readSnap(char * snapName)
{
  load_snapshot(snapName);

  print_info();

	Time		=	header1.Time;
	Redshift	=	header1.Redshift;
	BoxSize		=	header1.BoxSize;
	Omega0		=	header1.Omega0;
	OmegaLambda	=	header1.OmegaLambda;
	HubbleParam	=	header1.HubbleParam;
}





/* here the particle data is at your disposal 
 */
int Snap::print_info(void)
{
	printf("Particle Number: %d\n",NumPart);
	printf("Box Size: %f\n",header1.BoxSize);
	printf("Time: %f\n",header1.Time);
	printf("Redshift: %f\n",header1.Redshift);
	printf("Omega0: %f\n",header1.Omega0);
	printf("OmegaLambda: %f\n",header1.OmegaLambda);
	printf("HubbleParam: %f\n",header1.HubbleParam);
	printf("Mass: %f\n", header1.Mass);	

	return(0);
}






int Snap::load_snapshot(char *fname)
{
	FILE *	fp;
	fp	=	fopen(fname, "r");
	fread(&header1, sizeof(HEADER), 1, fp);
	
	NumPart	=	header1.NumPart;
	
	P	=	(PARTICLE *)malloc(sizeof(PARTICLE) * NumPart);
	fread(P, sizeof(PARTICLE), NumPart, fp);
	--P;

	fclose(fp);
	
}





