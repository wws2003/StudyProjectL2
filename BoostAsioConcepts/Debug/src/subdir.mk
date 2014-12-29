################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BoostAsioConcepts.cpp \
../src/CounterWorker.cpp \
../src/QueuedTCPServer.cpp \
../src/SynchronizeServer.cpp \
../src/TCPAsyncServer.cpp \
../src/TCPConnection.cpp \
../src/TimerServer.cpp \
../src/Worker.cpp 

OBJS += \
./src/BoostAsioConcepts.o \
./src/CounterWorker.o \
./src/QueuedTCPServer.o \
./src/SynchronizeServer.o \
./src/TCPAsyncServer.o \
./src/TCPConnection.o \
./src/TimerServer.o \
./src/Worker.o 

CPP_DEPS += \
./src/BoostAsioConcepts.d \
./src/CounterWorker.d \
./src/QueuedTCPServer.d \
./src/SynchronizeServer.d \
./src/TCPAsyncServer.d \
./src/TCPConnection.d \
./src/TimerServer.d \
./src/Worker.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/admini/workspace4/BoostAsioConcepts/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


