################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/CAN.c \
../Core/Src/_do_quasar_canopen.c \
../Core/Src/isolation.c \
../Core/Src/main.c \
../Core/Src/stm32f7xx_hal_msp.c \
../Core/Src/stm32f7xx_hal_timebase_tim.c \
../Core/Src/stm32f7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/system_stm32f7xx.c \
../Core/Src/temp.c \
../Core/Src/tps.c 

OBJS += \
./Core/Src/CAN.o \
./Core/Src/_do_quasar_canopen.o \
./Core/Src/isolation.o \
./Core/Src/main.o \
./Core/Src/stm32f7xx_hal_msp.o \
./Core/Src/stm32f7xx_hal_timebase_tim.o \
./Core/Src/stm32f7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/system_stm32f7xx.o \
./Core/Src/temp.o \
./Core/Src/tps.o 

C_DEPS += \
./Core/Src/CAN.d \
./Core/Src/_do_quasar_canopen.d \
./Core/Src/isolation.d \
./Core/Src/main.d \
./Core/Src/stm32f7xx_hal_msp.d \
./Core/Src/stm32f7xx_hal_timebase_tim.d \
./Core/Src/stm32f7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/system_stm32f7xx.d \
./Core/Src/temp.d \
./Core/Src/tps.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"C:/Users/kaush/Desktop/Github/2024-LTU-Formula-Electric-Vehicle-Control-Unit-VCU-Firmware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7" -I"C:/Users/kaush/Desktop/Github/2024-LTU-Formula-Electric-Vehicle-Control-Unit-VCU-Firmware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Users/kaush/Desktop/Github/2024-LTU-Formula-Electric-Vehicle-Control-Unit-VCU-Firmware/ThirdParty/FreeRTOS" -I"C:/Users/kaush/Desktop/Github/2024-LTU-Formula-Electric-Vehicle-Control-Unit-VCU-Firmware/ThirdParty/FreeRTOS/include" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/CAN.cyclo ./Core/Src/CAN.d ./Core/Src/CAN.o ./Core/Src/CAN.su ./Core/Src/_do_quasar_canopen.cyclo ./Core/Src/_do_quasar_canopen.d ./Core/Src/_do_quasar_canopen.o ./Core/Src/_do_quasar_canopen.su ./Core/Src/isolation.cyclo ./Core/Src/isolation.d ./Core/Src/isolation.o ./Core/Src/isolation.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f7xx_hal_msp.cyclo ./Core/Src/stm32f7xx_hal_msp.d ./Core/Src/stm32f7xx_hal_msp.o ./Core/Src/stm32f7xx_hal_msp.su ./Core/Src/stm32f7xx_hal_timebase_tim.cyclo ./Core/Src/stm32f7xx_hal_timebase_tim.d ./Core/Src/stm32f7xx_hal_timebase_tim.o ./Core/Src/stm32f7xx_hal_timebase_tim.su ./Core/Src/stm32f7xx_it.cyclo ./Core/Src/stm32f7xx_it.d ./Core/Src/stm32f7xx_it.o ./Core/Src/stm32f7xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/system_stm32f7xx.cyclo ./Core/Src/system_stm32f7xx.d ./Core/Src/system_stm32f7xx.o ./Core/Src/system_stm32f7xx.su ./Core/Src/temp.cyclo ./Core/Src/temp.d ./Core/Src/temp.o ./Core/Src/temp.su ./Core/Src/tps.cyclo ./Core/Src/tps.d ./Core/Src/tps.o ./Core/Src/tps.su

.PHONY: clean-Core-2f-Src

