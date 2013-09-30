################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AsyncStaticWebServer.cpp \
../src/SocketWrapper.cpp \
../src/WebServer.cpp 

OBJS += \
./src/AsyncStaticWebServer.o \
./src/SocketWrapper.o \
./src/WebServer.o 

CPP_DEPS += \
./src/AsyncStaticWebServer.d \
./src/SocketWrapper.d \
./src/WebServer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/admini/workspace4/AsyncStaticWebServer/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


