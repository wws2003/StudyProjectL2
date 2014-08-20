CC = g++
CCFLAGS = std=c++11
INCLUDE1 = ../MyThreadPoolLib/include/
INCLUDE2 = ./ParallelParticles
SRC = ./ParallelParticles
LIB = ../MyThreadPoolLib/build/
LIBFLAG = MyThreadPool
DST = ./build
objects = AbstractBinningAlgorithm.o ParticleMoveAndDistributeTask.o Bin.o  ParticleMoveTask.o BinApplyForceTask.o ParticleProblem.o BinClearTask.o ParticlesExportResultAssembler.o BinningAlgorimthSerialImpl.o ParticlesExportResultPrintImpl.o BinningAlgorithmMultiThreadImpl.o ParticlesInitiatorAssembler.o BinningAlgorithmMultithreadBatchImpl.o  ParticlesRandomInitiatorImpl.o ParticleDistributeTask.o common.o ParticleMoveAlgorithmAssembler.o main.o
objectsInDst = $(addprefix $(DST)/,$(objects))
target = ParallelParticles

all: $(target)

$(target): $(objectsInDst)
	$(CC) -o $(DST)/$(target) $(objectsInDst) -L $(LIB) -l$(LIBFLAG)

$(objectsInDst): | OUTPUTDIR

$(DST)/%.o: $(SRC)/%.cpp
	$(CC) -c -fPIC -$(CCFLAGS) -I $(INCLUDE1) -I $(INCLUDE2) $< -o $@

OUTPUTDIR: 
	mkdir -p $(DST)

clean:
	rm -rf $(DST)
