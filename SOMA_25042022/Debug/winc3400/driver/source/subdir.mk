################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../winc3400/driver/source/m2m_ate_mode.c \
../winc3400/driver/source/m2m_crypto.c \
../winc3400/driver/source/m2m_flash.c \
../winc3400/driver/source/m2m_hif.c \
../winc3400/driver/source/m2m_ota.c \
../winc3400/driver/source/m2m_periph.c \
../winc3400/driver/source/m2m_ssl.c \
../winc3400/driver/source/m2m_wifi.c \
../winc3400/driver/source/nmasic.c \
../winc3400/driver/source/nmbus.c \
../winc3400/driver/source/nmdrv.c \
../winc3400/driver/source/nmi2c.c \
../winc3400/driver/source/nmspi.c \
../winc3400/driver/source/nmuart.c 

OBJS += \
./winc3400/driver/source/m2m_ate_mode.o \
./winc3400/driver/source/m2m_crypto.o \
./winc3400/driver/source/m2m_flash.o \
./winc3400/driver/source/m2m_hif.o \
./winc3400/driver/source/m2m_ota.o \
./winc3400/driver/source/m2m_periph.o \
./winc3400/driver/source/m2m_ssl.o \
./winc3400/driver/source/m2m_wifi.o \
./winc3400/driver/source/nmasic.o \
./winc3400/driver/source/nmbus.o \
./winc3400/driver/source/nmdrv.o \
./winc3400/driver/source/nmi2c.o \
./winc3400/driver/source/nmspi.o \
./winc3400/driver/source/nmuart.o 

C_DEPS += \
./winc3400/driver/source/m2m_ate_mode.d \
./winc3400/driver/source/m2m_crypto.d \
./winc3400/driver/source/m2m_flash.d \
./winc3400/driver/source/m2m_hif.d \
./winc3400/driver/source/m2m_ota.d \
./winc3400/driver/source/m2m_periph.d \
./winc3400/driver/source/m2m_ssl.d \
./winc3400/driver/source/m2m_wifi.d \
./winc3400/driver/source/nmasic.d \
./winc3400/driver/source/nmbus.d \
./winc3400/driver/source/nmdrv.d \
./winc3400/driver/source/nmi2c.d \
./winc3400/driver/source/nmspi.d \
./winc3400/driver/source/nmuart.d 


# Each subdirectory must supply rules for building sources it contributes
winc3400/driver/source/%.o winc3400/driver/source/%.su: ../winc3400/driver/source/%.c winc3400/driver/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DCONF_PERIPH -DWIFI_PROVISIONING -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../MP3 -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../winc3400 -I../winc3400/bsp/include -I../winc3400/bus_wrapper/include -I../winc3400/common/include -I../winc3400/config -I../winc3400/driver/include -I../winc3400/programmer -I../winc3400/socket/include -I../winc3400/spi_flash/include -I../winc3400/ble/atmel_ble_api/include -I../winc3400/ble/inc -I../winc3400/ble/utils -I../winc3400/winc3400_ble_api/include -I../winc3400/ble/ble_profiles/wifi_provisioning -I../winc3400/ble/ble_services/ble_mgr -I../winc3400/ble/ble_services/wifi_con -I../winc3400/ble/ble_services/wifi_scan -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-winc3400-2f-driver-2f-source

clean-winc3400-2f-driver-2f-source:
	-$(RM) ./winc3400/driver/source/m2m_ate_mode.d ./winc3400/driver/source/m2m_ate_mode.o ./winc3400/driver/source/m2m_ate_mode.su ./winc3400/driver/source/m2m_crypto.d ./winc3400/driver/source/m2m_crypto.o ./winc3400/driver/source/m2m_crypto.su ./winc3400/driver/source/m2m_flash.d ./winc3400/driver/source/m2m_flash.o ./winc3400/driver/source/m2m_flash.su ./winc3400/driver/source/m2m_hif.d ./winc3400/driver/source/m2m_hif.o ./winc3400/driver/source/m2m_hif.su ./winc3400/driver/source/m2m_ota.d ./winc3400/driver/source/m2m_ota.o ./winc3400/driver/source/m2m_ota.su ./winc3400/driver/source/m2m_periph.d ./winc3400/driver/source/m2m_periph.o ./winc3400/driver/source/m2m_periph.su ./winc3400/driver/source/m2m_ssl.d ./winc3400/driver/source/m2m_ssl.o ./winc3400/driver/source/m2m_ssl.su ./winc3400/driver/source/m2m_wifi.d ./winc3400/driver/source/m2m_wifi.o ./winc3400/driver/source/m2m_wifi.su ./winc3400/driver/source/nmasic.d ./winc3400/driver/source/nmasic.o ./winc3400/driver/source/nmasic.su ./winc3400/driver/source/nmbus.d ./winc3400/driver/source/nmbus.o ./winc3400/driver/source/nmbus.su ./winc3400/driver/source/nmdrv.d ./winc3400/driver/source/nmdrv.o ./winc3400/driver/source/nmdrv.su ./winc3400/driver/source/nmi2c.d ./winc3400/driver/source/nmi2c.o ./winc3400/driver/source/nmi2c.su ./winc3400/driver/source/nmspi.d ./winc3400/driver/source/nmspi.o ./winc3400/driver/source/nmspi.su ./winc3400/driver/source/nmuart.d ./winc3400/driver/source/nmuart.o ./winc3400/driver/source/nmuart.su

.PHONY: clean-winc3400-2f-driver-2f-source

