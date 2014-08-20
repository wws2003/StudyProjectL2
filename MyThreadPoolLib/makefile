CC = g++
CCFLAGS = std=c++11
INCLUDE = ./include
SRC = ./src
DST = ./build
objects = AbstractDelegatingMasterTask.o  RecursiveTaskAssembler.o AbstractDelegatingSlaveTask.o   ResultDelegatePairFactoryImpl.o AbstractRecursiveTask.o ResultSignalDelegate.o AbstractThreadPool.o ResultWaitDelegate.o ObjectPoolFactory.o SimpleChildTask.o ObjectPoolSimpleImpl.o SubTaskDelegateImpl.o PCondVar.o SumMasterTask.o PMutex.o TaskGroup.o PThreadPool.o TaskGroupFactory.o PoolObject.o ThreadPoolFactory.o QuickSortRecursiveTask.o
objectsInDst = $(addprefix $(DST)/,$(objects))
target = libMyThreadPool.so

all: $(target)

$(target): $(objectsInDst)
	$(CC) -shared -o $(DST)/$(target) $(objectsInDst)

$(objectsInDst): | OUTPUTDIR

$(DST)/%.o: $(SRC)/%.cpp
	$(CC) -c -fPIC -$(CCFLAGS) -I $(INCLUDE) $< -o $@

OUTPUTDIR: 
	mkdir -p $(DST)

clean:
	rm -rf $(DST)
