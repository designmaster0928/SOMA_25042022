################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../winc3400/winc3400_ble_api/src/dbg_task.c \
../winc3400/winc3400_ble_api/src/error.c \
../winc3400/winc3400_ble_api/src/event.c \
../winc3400/winc3400_ble_api/src/gap.c \
../winc3400/winc3400_ble_api/src/gapc_task.c \
../winc3400/winc3400_ble_api/src/gapm_task.c \
../winc3400/winc3400_ble_api/src/gatt_client.c \
../winc3400/winc3400_ble_api/src/gatt_server.c \
../winc3400/winc3400_ble_api/src/gattc_task.c \
../winc3400/winc3400_ble_api/src/gattm_task.c \
../winc3400/winc3400_ble_api/src/interface.c \
../winc3400/winc3400_ble_api/src/platform.c \
../winc3400/winc3400_ble_api/src/security.c \
../winc3400/winc3400_ble_api/src/wifiprov_task.c 

OBJS += \
./winc3400/winc3400_ble_api/src/dbg_task.o \
./winc3400/winc3400_ble_api/src/error.o \
./winc3400/winc3400_ble_api/src/event.o \
./winc3400/winc3400_ble_api/src/gap.o \
./winc3400/winc3400_ble_api/src/gapc_task.o \
./winc3400/winc3400_ble_api/src/gapm_task.o \
./winc3400/winc3400_ble_api/src/gatt_client.o \
./winc3400/winc3400_ble_api/src/gatt_server.o \
./winc3400/winc3400_ble_api/src/gattc_task.o \
./winc3400/winc3400_ble_api/src/gattm_task.o \
./winc3400/winc3400_ble_api/src/interface.o \
./winc3400/winc3400_ble_api/src/platform.o \
./winc3400/winc3400_ble_api/src/security.o \
./winc3400/winc3400_ble_api/src/wifiprov_task.o 

C_DEPS += \
./winc3400/winc3400_ble_api/src/dbg_task.d \
./winc3400/winc3400_ble_api/src/error.d \
./winc3400/winc3400_ble_api/src/event.d \
./winc3400/winc3400_ble_api/src/gap.d \
./winc3400/winc3400_ble_api/src/gapc_task.d \
./winc3400/winc3400_ble_api/src/gapm_task.d \
./winc3400/winc3400_ble_api/src/gatt_client.d \
./winc3400/winc3400_ble_api/src/gatt_server.d \
./winc3400/winc3400_ble_api/src/gattc_task.d \
./winc3400/winc3400_ble_api/src/gattm_task.d \
./winc3400/winc3400_ble_api/src/interface.d \
./winc3400/winc3400_ble_api/src/platform.d \
./winc3400/winc3400_ble_api/src/security.d \
./winc3400/winc3400_ble_api/src/wifiprov_task.d 


# Each subdirectory must supply rules for building sources it contributes
winc3400/winc3400_ble_api/src/%.o winc3400/winc3400_ble_api/src/%.su: ../winc3400/winc3400_ble_api/src/%.c winc3400/winc3400_ble_api/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DCONF_PERIPH -DWIFI_PROVISIONING -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../MP3 -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../winc3400 -I../winc3400/bsp/include -I../winc3400/bus_wrapper/include -I../winc3400/common/include -I../winc3400/config -I../winc3400/driver/include -I../winc3400/programmer -I../winc3400/socket/include -I../winc3400/spi_flash/include -I../winc3400/ble/atmel_ble_api/include -I../winc3400/ble/inc -I../winc3400/ble/utils -I../winc3400/winc3400_ble_api/include -I../winc3400/ble/ble_profiles/wifi_provisioning -I../winc3400/ble/ble_services/ble_mgr -I../winc3400/ble/ble_services/wifi_con -I../winc3400/ble/ble_services/wifi_scan -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-winc3400-2f-winc3400_ble_api-2f-src

clean-winc3400-2f-winc3400_ble_api-2f-src:
	-$(RM) ./winc3400/winc3400_ble_api/src/dbg_task.d ./winc3400/winc3400_ble_api/src/dbg_task.o ./winc3400/winc3400_ble_api/src/dbg_task.su ./winc3400/winc3400_ble_api/src/error.d ./winc3400/winc3400_ble_api/src/error.o ./winc3400/winc3400_ble_api/src/error.su ./winc3400/winc3400_ble_api/src/event.d ./winc3400/winc3400_ble_api/src/event.o ./winc3400/winc3400_ble_api/src/event.su ./winc3400/winc3400_ble_api/src/gap.d ./winc3400/winc3400_ble_api/src/gap.o ./winc3400/winc3400_ble_api/src/gap.su ./winc3400/winc3400_ble_api/src/gapc_task.d ./winc3400/winc3400_ble_api/src/gapc_task.o ./winc3400/winc3400_ble_api/src/gapc_task.su ./winc3400/winc3400_ble_api/src/gapm_task.d ./winc3400/winc3400_ble_api/src/gapm_task.o ./winc3400/winc3400_ble_api/src/gapm_task.su ./winc3400/winc3400_ble_api/src/gatt_client.d ./winc3400/winc3400_ble_api/src/gatt_client.o ./winc3400/winc3400_ble_api/src/gatt_client.su ./winc3400/winc3400_ble_api/src/gatt_server.d ./winc3400/winc3400_ble_api/src/gatt_server.o ./winc3400/winc3400_ble_api/src/gatt_server.su ./winc3400/winc3400_ble_api/src/gattc_task.d ./winc3400/winc3400_ble_api/src/gattc_task.o ./winc3400/winc3400_ble_api/src/gattc_task.su ./winc3400/winc3400_ble_api/src/gattm_task.d ./winc3400/winc3400_ble_api/src/gattm_task.o ./winc3400/winc3400_ble_api/src/gattm_task.su ./winc3400/winc3400_ble_api/src/interface.d ./winc3400/winc3400_ble_api/src/interface.o ./winc3400/winc3400_ble_api/src/interface.su ./winc3400/winc3400_ble_api/src/platform.d ./winc3400/winc3400_ble_api/src/platform.o ./winc3400/winc3400_ble_api/src/platform.su ./winc3400/winc3400_ble_api/src/security.d ./winc3400/winc3400_ble_api/src/security.o ./winc3400/winc3400_ble_api/src/security.su ./winc3400/winc3400_ble_api/src/wifiprov_task.d ./winc3400/winc3400_ble_api/src/wifiprov_task.o ./winc3400/winc3400_ble_api/src/wifiprov_task.su

.PHONY: clean-winc3400-2f-winc3400_ble_api-2f-src

