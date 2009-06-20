typedef	float	FLOAT;

typedef	struct	tag_particle_data{
	
	FLOAT	Pos[3];
	FLOAT	Mass;
	FLOAT	Vel[3];
	FLOAT	GravAccel[3];
	FLOAT	GravPM[3];

	int		Ti_endstep;
	int		Ti_begstep;
}PARTICLE;

typedef struct	tag_io_header{

	int		NumPart;
	double	Mass;
	double	Time;
	double	Redshift;
	double	BoxSize;
	double	Omega0;
	double	OmegaLambda;
	double	HubbleParam;
}HEADER;

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
	
	PARTICLE *	P;

private:
	int		print_info();
	int		load_snapshot(char * fname);

	HEADER	header1;
};

