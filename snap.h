typedef struct io_header_1
{
  int      npart[6];
  double   mass[6];
  double   time;
  double   redshift;
  int      flag_sfr;
  int      flag_feedback;
  int      npartTotal[6];
  int      flag_cooling;
  int      num_files;
  double   BoxSize;
  double   Omega0;
  double   OmegaLambda;
  double   HubbleParam; 
  char     fill[256- 6*4- 6*8- 2*8- 2*4- 6*4- 2*4 - 4*8];  /* fills to 256 Bytes */
} Header;

typedef struct particle_data 
{
  float  Pos[3];
  float  Vel[3];
  float  Mass;
  int    Type;

  float  Rho, U, Temp, Ne;
} Particle;

class Snap{
public:
	Snap();
	~Snap();
	void	readSnap(char * snapName);

	double	Time;
	double	Redshift;
	
	double	BoxSize;
	int		NumPart;	
	
	double 	Omega0;
	double	OmegaLambda;
	double	HubbleParam;
	
	Particle *	P;

private:
	int		print_info();
	int		unit_conversion();
	int		load_snapshot(char * fname, int files);
	int		allocate_memory();
	int		reordering();

	Header	header1;
	int		Ngas;
	int *	Id;
};

