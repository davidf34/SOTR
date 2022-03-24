################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Project_Settings/Startup_Code/start08.cpp \

CPP_SRCS_QUOTED += \
"../Project_Settings/Startup_Code/start08.cpp" \

OBJS += \
./Project_Settings/Startup_Code/start08_cpp.obj \

OBJS_QUOTED += \
"./Project_Settings/Startup_Code/start08_cpp.obj" \

CPP_DEPS_QUOTED += \
"./Project_Settings/Startup_Code/start08_cpp.d" \

CPP_DEPS += \
./Project_Settings/Startup_Code/start08_cpp.d \

OBJS_OS_FORMAT += \
./Project_Settings/Startup_Code/start08_cpp.obj \


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/start08_cpp.obj: ../Project_Settings/Startup_Code/start08.cpp
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Project_Settings/Startup_Code/start08.args" -ObjN="Project_Settings/Startup_Code/start08_cpp.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Project_Settings/Startup_Code/%.d: ../Project_Settings/Startup_Code/%.cpp
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


