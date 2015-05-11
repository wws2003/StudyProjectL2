CC = g++
CCFLAGS = std=c++11
INCLUDE = -I ./include/abstract -I ./include/implement -I ./include/common
SRC = ./src
DST = ./build

#objects = AbstractDelegatingMasterTask.o  RecursiveTaskAssembler.o AbstractDelegatingSlaveTask.o   ResultDelegatePairFactoryImpl.o AbstractRecursiveTask.o ResultSignalDelegate.o AbstractThreadPool.o ResultWaitDelegate.o ObjectPoolFactory.o SimpleChildTask.o ObjectPoolSimpleImpl.o SubTaskDelegateImpl.o PCondVar.o SumMasterTask.o PMutex.o TaskGroup.o PThreadPool.o TaskGroupFactory.o PoolObject.o ThreadPoolFactory.o QuickSortRecursiveTask.o

#objectsInDst = $(addprefix $(DST)/,$(objects))

objectsInSrc = $(notdir $(shell echo $(SRC)/*.cpp))
objectsInDst = $(addprefix $(DST)/,$(objectsInSrc:.cpp=.o))
target = libMyThreadPool.so

all: $(target)

$(target): $(objectsInDst)
	$(CC) -shared -o $(DST)/$(target) $(objectsInDst)

$(objectsInDst): | OUTPUTDIR

$(DST)/%.o: $(SRC)/%.cpp
	$(CC) -c -fPIC -$(CCFLAGS) $(INCLUDE) $< -o $@

OUTPUTDIR: 
	mkdir -p $(DST)

clean:
	rm -rf $(DST)
