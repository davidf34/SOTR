################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/AppTypes.c" \
"../Sources/Queue.c" \
"../Sources/RTOS.c" \
"../Sources/main.c" \
"../Sources/portable.c" \
"../Sources/scheduller.c" \
"../Sources/task.c" \

ASM_SRCS += \
../Sources/asm_main.asm \

C_SRCS += \
../Sources/AppTypes.c \
../Sources/Queue.c \
../Sources/RTOS.c \
../Sources/main.c \
../Sources/portable.c \
../Sources/scheduller.c \
../Sources/task.c \

ASM_SRCS_QUOTED += \
"../Sources/asm_main.asm" \

OBJS += \
./Sources/AppTypes_c.obj \
./Sources/Queue_c.obj \
./Sources/RTOS_c.obj \
./Sources/asm_main_asm.obj \
./Sources/main_c.obj \
./Sources/portable_c.obj \
./Sources/scheduller_c.obj \
./Sources/task_c.obj \

ASM_DEPS += \
./Sources/asm_main_asm.d \

OBJS_QUOTED += \
"./Sources/AppTypes_c.obj" \
"./Sources/Queue_c.obj" \
"./Sources/RTOS_c.obj" \
"./Sources/asm_main_asm.obj" \
"./Sources/main_c.obj" \
"./Sources/portable_c.obj" \
"./Sources/scheduller_c.obj" \
"./Sources/task_c.obj" \

C_DEPS += \
./Sources/AppTypes_c.d \
./Sources/Queue_c.d \
./Sources/RTOS_c.d \
./Sources/main_c.d \
./Sources/portable_c.d \
./Sources/scheduller_c.d \
./Sources/task_c.d \

ASM_DEPS_QUOTED += \
"./Sources/asm_main_asm.d" \

C_DEPS_QUOTED += \
"./Sources/AppTypes_c.d" \
"./Sources/Queue_c.d" \
"./Sources/RTOS_c.d" \
"./Sources/main_c.d" \
"./Sources/portable_c.d" \
"./Sources/scheduller_c.d" \
"./Sources/task_c.d" \

OBJS_OS_FORMAT += \
./Sources/AppTypes_c.obj \
./Sources/Queue_c.obj \
./Sources/RTOS_c.obj \
./Sources/asm_main_asm.obj \
./Sources/main_c.obj \
./Sources/portable_c.obj \
./Sources/scheduller_c.obj \
./Sources/task_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/AppTypes_c.obj: ../Sources/AppTypes.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/AppTypes.args" -ObjN="Sources/AppTypes_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Queue_c.obj: ../Sources/Queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Queue.args" -ObjN="Sources/Queue_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/RTOS_c.obj: ../Sources/RTOS.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/RTOS.args" -ObjN="Sources/RTOS_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/asm_main_asm.obj: ../Sources/asm_main.asm
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Assembler'
	"$(HC08ToolsEnv)/ahc08" -ArgFile"Sources/asm_main.args" -Objn"Sources/asm_main_asm.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.asm
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/portable_c.obj: ../Sources/portable.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/portable.args" -ObjN="Sources/portable_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/scheduller_c.obj: ../Sources/scheduller.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/scheduller.args" -ObjN="Sources/scheduller_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/task_c.obj: ../Sources/task.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/task.args" -ObjN="Sources/task_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


