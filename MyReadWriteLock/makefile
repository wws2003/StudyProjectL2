CC = g++
CCFLAGS = std=c++11
INCLUDE = ./MyReadWriteLock
SRC = ./MyReadWriteLock
DST = ./build
objects = AbstractReadLock.o PThreadWriteLockImpl.o AbstractWriteLock.o	RWCritical.o LockException.o	ReadLockAssembler.o LockScoper.o ReadWriteLockTester.o PThreadMutexLockImpl.o	main.o PThreadReadLockImpl.o

objectsInDst = $(addprefix $(DST)/,$(objects))
target = testMyReadWriteLock

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
