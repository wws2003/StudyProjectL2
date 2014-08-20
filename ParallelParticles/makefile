CC = g++
CCFLAGS = std=c++11
INCLUDE = ../MyThreadPoolLib/include/:ParallelParticles
SRC = ParallelParticles
LIB = ../MyThreadPoolLib/build/
LIBFLAG = MyThreadPoolLib
DST = ./build
objects = AbstractBinningAlgorithm.o ParticleMoveAndDistributeTask.o Bin.o  ParticleMoveTask.o BinApplyForceTask.o ParticleProblem.o BinClearTask.o ParticlesExportResultAssembler.o BinningAlgorimthSerialImpl.o ParticlesExportResultPrintImpl.o BinningAlgorithmMultiThreadImpl.o ParticlesInitiatorAssembler.o BinningAlgorithmMultithreadBatchImpl.o  ParticlesRandomInitiatorImpl.o ParticleDistributeTask.o common.o ParticleMoveAlgorithmAssembler.o main.o
objectsInDst = $(addprefix $(DST)/,$(objects))
target = ParallelParticles

all: $(target)

$(target): $(objectsInDst)
	$(CC) -L $(LIB) -l$(LIBFLAG) -o $(DST)/$(target) $(objectsInDst)

$(objectsInDst): | OUTPUTDIR

$(DST)/%.o: $(SRC)/%.cpp
	$(CC) -c -fPIC -$(CCFLAGS) -I $(INCLUDE) $< -o $@

OUTPUTDIR: 
	mkdir -p $(DST)

clean:
	rm -rf $(DST)
