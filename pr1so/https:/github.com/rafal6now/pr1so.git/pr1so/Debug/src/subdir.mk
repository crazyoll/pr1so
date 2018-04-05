################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/arg_parser.cpp \
../src/deamon_file.cpp \
../src/log_handling.cpp \
../src/pr1so.cpp 

OBJS += \
./src/arg_parser.o \
./src/deamon_file.o \
./src/log_handling.o \
./src/pr1so.o 

CPP_DEPS += \
./src/arg_parser.d \
./src/deamon_file.d \
./src/log_handling.d \
./src/pr1so.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


