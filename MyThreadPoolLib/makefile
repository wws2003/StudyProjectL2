CC = g++
CCFLAGS = std=c++11
INCLUDE = ./include
SRC = ./src
objects = AbstractDelegatingMasterTask.o  RecursiveTaskAssembler.o AbstractDelegatingSlaveTask.o   ResultDelegatePairFactoryImpl.o AbstractRecursiveTask.o ResultSignalDelegate.o AbstractThreadPool.o ResultWaitDelegate.o ObjectPoolFactory.o SimpleChildTask.o ObjectPoolSimpleImpl.o SubTaskDelegateImpl.o PCondVar.o SumMasterTask.o PMutex.o TaskGroup.o PThreadPool.o TaskGroupFactory.o PoolObject.o ThreadPoolFactory.o QuickSortRecursiveTask.o

all: libMyThreadPool.so

libMyThreadPool.so: $(objects)
	$(CC) -shared -o libMyThreadPool.so $(objects)

$(objects): %.o: $(SRC)/%.cpp
	$(CC) -c -fPIC -$(CCFLAGS) -I $(INCLUDE) $< -o $@

clean:
	rm -rf *.o
