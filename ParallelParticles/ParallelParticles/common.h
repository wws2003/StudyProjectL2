#ifndef __CS267_COMMON_H__
#define __CS267_COMMON_H__

#include <vector>

inline int min( int a, int b ) { return a < b ? a : b; }
inline int max( int a, int b ) { return a > b ? a : b; }

//
//  saving parameters
//
const int NSTEPS = 1000;
const int SAVEFREQ = 10;

//
// particle data structure
//
class particle_t
{
public:
  particle_t(){};
  virtual ~particle_t(){};
  double x;
  double y;
  double vx;
  double vy;
  double ax;
  double ay;
} ;


//
//  timing routines
//
double read_timer( );

//
//  simulation routines
//
void apply_force( particle_t &particle, const particle_t &neighbor );
void move( particle_t &p, double size, unsigned int dt );

//
//  argument processing routines
//
int find_option( int argc, char **argv, const char *option );
int read_int( int argc, char **argv, const char *option, int default_value );
char *read_string( int argc, char **argv, const char *option, char *default_value );

#endif
