//
//  ParticlesRandomInitiatorImpl.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ParticlesRandomInitiatorImpl.h"
#include "common.h"
#include <cmath>
#include <cstdlib>
#include <sys/time.h>

PP_ERR ParticlesRandomInitiatorImpl::initParticles(ParticlePtrs& particles, double& rSpaceWidth, double& rSpaceHeight, double& density) {
    int n = 1000;
    density = 0.005;
    
    double size = sqrt( density * n );
    rSpaceWidth = size;
    rSpaceHeight = size;
    
    srand48( time( NULL ) );
    
    int sx = (int)ceil(sqrt((double)n));
    int sy = (n+sx-1)/sx;
    
    int *shuffle = (int*)malloc( n * sizeof(int) );
    for( int i = 0; i < n; i++ )
        shuffle[i] = i;
    
    for( int i = 0; i < n; i++ )
    {
        ParticlePtr pParticle = new particle_t();
        //
        //  make sure particles are not spatially sorted
        //
        int j = lrand48()%(n-i);
        int k = shuffle[j];
        shuffle[j] = shuffle[n-i-1];
        
        //
        //  distribute particles evenly to ensure proper spacing
        //
        pParticle->x = rSpaceWidth * (1.+(k%sx))/(1+sx);
        pParticle->y = rSpaceHeight * (1.+(k/sx))/(1+sy);
        
        //
        //  assign random velocities within a bound
        //
        pParticle->vx = drand48()*2-1;
        pParticle->vy = drand48()*2-1;
        
        particles.push_back(pParticle);
    }
    free( shuffle );
    return ERR_NONE;
}