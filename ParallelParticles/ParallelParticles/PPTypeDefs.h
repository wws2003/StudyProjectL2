//
//  TypeDefs.h
//  ParallelParticles
//
//  Created by wws2003 on 7/28/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ParallelParticles_TypeDefs_h
#define ParallelParticles_TypeDefs_h

#include <vector>
#include <memory>

enum PP_ERR {
    ERR_NONE,
    ERR_INIT_FAILED,
    ERR_EXECUTE_FAILED,
    ERR_INVALID_PARAMS,
    ERR_EXPORT_RESULT_FAILED
};

class particle_t;
typedef particle_t* ParticlePtr;
typedef std::vector<ParticlePtr> ParticlePtrs;

class ParticleProblem;
typedef ParticleProblem* ParticleProblemPtr;

class IParticlesInitiator;
typedef IParticlesInitiator* ParticlesInitiatorPtr;

class IParticlesExportResult;
typedef IParticlesExportResult* ParticlesExportResultPtr;

class IParticleMoveAlgorithm;
typedef IParticleMoveAlgorithm* ParticleMoveAlgorithmPtr;

class AbstractBinningAlgorithm;
typedef AbstractBinningAlgorithm*  AbstractBinningAlgorithmPtr;

#define PP_DELETE(x) delete x

class Bin;
typedef Bin* BinPtr;
typedef std::vector<BinPtr> BinPtrs;

#if SHARED_PTR  == 0

class BinApplyForceTask;
typedef BinApplyForceTask* BinApplyForceTaskPtr;

class BinClearTask;
typedef BinClearTask* BinClearTaskPtr;

class ParticleMoveAndDistributeTask;
typedef ParticleMoveAndDistributeTask* ParticleMoveAndDistributeTaskPtr;

class ParticleMoveTask;
typedef ParticleMoveTask* ParticleMoveTaskPtr;

class ParticleDistributeTask;
typedef ParticleDistributeTask* ParticleDistributeTaskPtr;

#else

class BinApplyForceTask;
typedef std::shared_ptr<BinApplyForceTask> BinApplyForceTaskPtr;

class BinClearTask;
typedef std::shared_ptr<BinClearTask> BinClearTaskPtr;

class ParticleMoveAndDistributeTask;
typedef std::shared_ptr<ParticleMoveAndDistributeTask> ParticleMoveAndDistributeTaskPtr;

class ParticleMoveTask;
typedef std::shared_ptr<ParticleMoveTask> ParticleMoveTaskPtr;

class ParticleDistributeTask;
typedef std::shared_ptr<ParticleDistributeTask> ParticleDistributeTaskPtr;
#endif

#endif
