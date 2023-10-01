################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/audioPlay.c \
../Core/Src/base64.c \
../Core/Src/fatfs_sd.c \
../Core/Src/files.c \
../Core/Src/freertos.c \
../Core/Src/lcdUartComm.c \
../Core/Src/m2m_ble.c \
../Core/Src/main.c \
../Core/Src/sgtl5000.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_hal_timebase_tim.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/audioPlay.o \
./Core/Src/base64.o \
./Core/Src/fatfs_sd.o \
./Core/Src/files.o \
./Core/Src/freertos.o \
./Core/Src/lcdUartComm.o \
./Core/Src/m2m_ble.o \
./Core/Src/main.o \
./Core/Src/sgtl5000.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_hal_timebase_tim.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/audioPlay.d \
./Core/Src/base64.d \
./Core/Src/fatfs_sd.d \
./Core/Src/files.d \
./Core/Src/freertos.d \
./Core/Src/lcdUartComm.d \
./Core/Src/m2m_ble.d \
./Core/Src/main.d \
./Core/Src/sgtl5000.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_hal_timebase_tim.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DCONF_PERIPH -DWIFI_PROVISIONING -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../MP3 -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../winc3400 -I../winc3400/bsp/include -I../winc3400/bus_wrapper/include -I../winc3400/common/include -I../winc3400/config -I../winc3400/driver/include -I../winc3400/programmer -I../winc3400/socket/include -I../winc3400/spi_flash/include -I../winc3400/ble/atmel_ble_api/include -I../winc3400/ble/inc -I../winc3400/ble/utils -I../winc3400/winc3400_ble_api/include -I../winc3400/ble/ble_profiles/wifi_provisioning -I../winc3400/ble/ble_services/ble_mgr -I../winc3400/ble/ble_services/wifi_con -I../winc3400/ble/ble_services/wifi_scan -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/audioPlay.d ./Core/Src/audioPlay.o ./Core/Src/audioPlay.su ./Core/Src/base64.d ./Core/Src/base64.o ./Core/Src/base64.su ./Core/Src/fatfs_sd.d ./Core/Src/fatfs_sd.o ./Core/Src/fatfs_sd.su ./Core/Src/files.d ./Core/Src/files.o ./Core/Src/files.su ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/lcdUartComm.d ./Core/Src/lcdUartComm.o ./Core/Src/lcdUartComm.su ./Core/Src/m2m_ble.d ./Core/Src/m2m_ble.o ./Core/Src/m2m_ble.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/sgtl5000.d ./Core/Src/sgtl5000.o ./Core/Src/sgtl5000.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_hal_timebase_tim.d ./Core/Src/stm32f4xx_hal_timebase_tim.o ./Core/Src/stm32f4xx_hal_timebase_tim.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

