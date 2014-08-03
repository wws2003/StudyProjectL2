//#include <stdlib.h>
//#include <stdio.h>
//#include <assert.h>
//#include <math.h>
//#include <pthread.h>
//#include "common.h"
//#include "pthread_barrier.h"
//#include "AbstractThreadPool.h"
//
////
////  global variables
////
//int n, n_threads;
//particle_t *particles;
//FILE *fsave;
//pthread_barrier_t barrier;
//
////
////  check that pthreads routine call was successful
////
//#define P( condition ) {if( (condition) != 0 ) { printf( "\n FAILURE in %s, line %d\n", __FILE__, __LINE__ );exit( 1 );}}
//
////
////  This is where the action happens
////
//void *thread_routine( void *pthread_id )
//{
//    int thread_id = *(int*)pthread_id;
//    
//    int particles_per_thread = (n + n_threads - 1) / n_threads;
//    int first = min(  thread_id    * particles_per_thread, n );
//    int last  = min( (thread_id+1) * particles_per_thread, n );
//    
//    //
//    //  simulate a number of time steps
//    //
//    for( int step = 0; step < NSTEPS; step++ )
//    {
//        //
//        //  compute forces
//        //
//        for( int i = first; i < last; i++ )
//        {
//            particles[i].ax = particles[i].ay = 0;
//            for (int j = 0; j < n; j++ )
//                apply_force( particles[i], particles[j] );
//        }
//        
//        pthread_barrier_wait( &barrier );
//        
//        //
//        //  move particles
//        //
//        for( int i = first; i < last; i++ )
//            move( particles[i] );
//        
//        pthread_barrier_wait( &barrier );
//        
//        //
//        //  save if necessary
//        //
////        if( thread_id == 0 && fsave && (step%SAVEFREQ) == 0 )
////            save( fsave, n, particles );
//    }
//    
//    return NULL;
//}
//
////
////  benchmarking program
////
//int main( int argc, char **argv )
//{
//    //
//    //  process command line
//    //
//    if( find_option( argc, argv, "-h" ) >= 0 )
//    {
//        printf( "Options:\n" );
//        printf( "-h to see this help\n" );
//        printf( "-n <int> to set the number of particles\n" );
//        printf( "-p <int> to set the number of threads\n" );
//        printf( "-o <filename> to specify the output file name\n" );
//        return 0;
//    }
//    
//    n = read_int( argc, argv, "-n", 2000 );
//    n_threads = read_int( argc, argv, "-p", 8 );
//    char *savename = read_string( argc, argv, "-o", NULL );
//    
//    //
//    //  allocate resources
//    //
//    fsave = savename ? fopen( savename, "w" ) : NULL;
//    
//    particles = (particle_t*) malloc( n * sizeof(particle_t) );
//    set_size( n );
//    init_particles( n, particles );
//    
//    pthread_attr_t attr;
//    P( pthread_attr_init( &attr ) );
//    P( pthread_barrier_init( &barrier, NULL, n_threads ) );
//    
//    int *thread_ids = (int *) malloc( n_threads * sizeof( int ) );
//    for( int i = 0; i < n_threads; i++ )
//        thread_ids[i] = i;
//    
//    pthread_t *threads = (pthread_t *) malloc( n_threads * sizeof( pthread_t ) );
//    
//    //
//    //  do the parallel work
//    //
//    double simulation_time = read_timer( );
//    for( int i = 1; i < n_threads; i++ )
//        P( pthread_create( &threads[i], &attr, thread_routine, &thread_ids[i] ) );
//    
//    thread_routine( &thread_ids[0] );
//    
//    for( int i = 1; i < n_threads; i++ )
//        P( pthread_join( threads[i], NULL ) );
//    simulation_time = read_timer( ) - simulation_time;
//    
//    printf( "n = %d, n_threads = %d, simulation time = %g seconds\n", n, n_threads, simulation_time );
//    
//    //
//    //  release resources
//    //
//    P( pthread_barrier_destroy( &barrier ) );
//    P( pthread_attr_destroy( &attr ) );
//    free( thread_ids );
//    free( threads );
//    free( particles );
//    if( fsave )
//        fclose( fsave );
//    
//    return 0;
//}

/*#include <iostream>
#include "RecursiveTaskAssembler.h"
#include "QuickSortRecursiveTask.h"
#include <unistd.h>

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    int array[] = {3, 4, 6, 2, 5, 1, 5, 64, 2, 0, 23, 2, -5, 5, 34, 23, 1, 42, 0, 44, 2, 12, 6, 7};
    int size = sizeof(array) / sizeof(int);
    
    AbstractRecursiveTaskPtr quickSortTask(new QuickSortRecursiveTask(array, size));
    RecursiveTaskAssembler* taskAssembler = new RecursiveTaskAssembler(4);
    taskAssembler->assembleRecursiveTask(quickSortTask);
    
    quickSortTask->execute();
    for (unsigned int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    
    delete taskAssembler;
    TASKPTR_DELETE(quickSortTask);
    return 0;
}*/
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include "PPTypeDefs.h"
#include "ParticleProblem.h"
#include "ParticlesExportResultAssembler.h"
#include "ParticlesInitiatorAssembler.h"
#include "ParticleMoveAlgorithmAssembler.h"

class Timer {
public:
    Timer(){gettimeofday(&m_tv, NULL);};
    virtual ~Timer(){
        struct timeval tv2;
        gettimeofday(&tv2, NULL);
        std::cout << "Run time " << ((tv2.tv_sec - m_tv.tv_sec) * 1e6 + (tv2.tv_usec - m_tv.tv_usec)) << std::endl;
    };
private:
    struct timeval m_tv;
};

int main(int argc, const char * argv[]) {
    ParticlesInitiatorAssembler particlesInitiatorAssembler;
    ParticleMoveAlgorithmAssembler particlesMoveAlgorithmAssembler;
    ParticlesExportResultAssembler particlesExportResultAssembler;
    
    ParticlesInitiatorPtr pParticlesInitiator = particlesInitiatorAssembler.createInitiatorInstance();
    ParticlesExportResultPtr pParticlesExportResult = particlesExportResultAssembler.createInitiatorInstance();
    ParticleMoveAlgorithmPtr pParticleMoveAlgorithm = particlesMoveAlgorithmAssembler.createAlgorithmInstance(ParticleMoveAlgorithmAssembler::SERIAL);
    
    ParticleProblem problem;
    problem.setParticleInitiatorPtr(pParticlesInitiator);
    problem.setParticleExportResult(pParticlesExportResult);
    problem.setParticleMoveAlgorithmPtr(pParticleMoveAlgorithm);
    
    PP_ERR err = ERR_NONE;
    {
        Timer timer; //Just to measure run time
        err = problem.solve();
    }
    std::cout << "Problem solve result " << err << std::endl;
    
    particlesInitiatorAssembler.destroyInitiatorInstance(pParticlesInitiator);
    particlesExportResultAssembler.destroyExportResultInstance(pParticlesExportResult);
    particlesMoveAlgorithmAssembler.destroyAlgorithm(pParticleMoveAlgorithm);
    
    return 0;
}

