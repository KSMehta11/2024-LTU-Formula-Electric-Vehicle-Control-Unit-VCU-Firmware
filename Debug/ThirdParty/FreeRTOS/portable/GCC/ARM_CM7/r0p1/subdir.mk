################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.c 

OBJS += \
./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.o 

C_DEPS += \
./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/%.o ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/%.su ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/%.cyclo: ../ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/%.c ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"C:/Users/kaush/Desktop/Github/2024-LTU-Formula-Electric-Vehicle-Control-Unit-VCU-Firmware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7" -I"C:/Users/kaush/Desktop/Github/2024-LTU-Formula-Electric-Vehicle-Control-Unit-VCU-Firmware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Users/kaush/Desktop/Github/2024-LTU-Formula-Electric-Vehicle-Control-Unit-VCU-Firmware/ThirdParty/FreeRTOS" -I"C:/Users/kaush/Desktop/Github/2024-LTU-Formula-Electric-Vehicle-Control-Unit-VCU-Firmware/ThirdParty/FreeRTOS/include" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM7-2f-r0p1

clean-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM7-2f-r0p1:
	-$(RM) ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.cyclo ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.d ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.o ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.su

.PHONY: clean-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM7-2f-r0p1

