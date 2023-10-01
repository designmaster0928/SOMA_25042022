################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MP3/bitstream.c \
../MP3/buffers.c \
../MP3/dct32.c \
../MP3/dequant.c \
../MP3/dqchan.c \
../MP3/huffman.c \
../MP3/hufftabs.c \
../MP3/imdct.c \
../MP3/mp3dec.c \
../MP3/mp3tabs.c \
../MP3/polyphase.c \
../MP3/scalfact.c \
../MP3/stproc.c \
../MP3/subband.c \
../MP3/trigtabs.c 

OBJS += \
./MP3/bitstream.o \
./MP3/buffers.o \
./MP3/dct32.o \
./MP3/dequant.o \
./MP3/dqchan.o \
./MP3/huffman.o \
./MP3/hufftabs.o \
./MP3/imdct.o \
./MP3/mp3dec.o \
./MP3/mp3tabs.o \
./MP3/polyphase.o \
./MP3/scalfact.o \
./MP3/stproc.o \
./MP3/subband.o \
./MP3/trigtabs.o 

C_DEPS += \
./MP3/bitstream.d \
./MP3/buffers.d \
./MP3/dct32.d \
./MP3/dequant.d \
./MP3/dqchan.d \
./MP3/huffman.d \
./MP3/hufftabs.d \
./MP3/imdct.d \
./MP3/mp3dec.d \
./MP3/mp3tabs.d \
./MP3/polyphase.d \
./MP3/scalfact.d \
./MP3/stproc.d \
./MP3/subband.d \
./MP3/trigtabs.d 


# Each subdirectory must supply rules for building sources it contributes
MP3/%.o MP3/%.su: ../MP3/%.c MP3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DCONF_PERIPH -DWIFI_PROVISIONING -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../MP3 -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../winc3400 -I../winc3400/bsp/include -I../winc3400/bus_wrapper/include -I../winc3400/common/include -I../winc3400/config -I../winc3400/driver/include -I../winc3400/programmer -I../winc3400/socket/include -I../winc3400/spi_flash/include -I../winc3400/ble/atmel_ble_api/include -I../winc3400/ble/inc -I../winc3400/ble/utils -I../winc3400/winc3400_ble_api/include -I../winc3400/ble/ble_profiles/wifi_provisioning -I../winc3400/ble/ble_services/ble_mgr -I../winc3400/ble/ble_services/wifi_con -I../winc3400/ble/ble_services/wifi_scan -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MP3

clean-MP3:
	-$(RM) ./MP3/bitstream.d ./MP3/bitstream.o ./MP3/bitstream.su ./MP3/buffers.d ./MP3/buffers.o ./MP3/buffers.su ./MP3/dct32.d ./MP3/dct32.o ./MP3/dct32.su ./MP3/dequant.d ./MP3/dequant.o ./MP3/dequant.su ./MP3/dqchan.d ./MP3/dqchan.o ./MP3/dqchan.su ./MP3/huffman.d ./MP3/huffman.o ./MP3/huffman.su ./MP3/hufftabs.d ./MP3/hufftabs.o ./MP3/hufftabs.su ./MP3/imdct.d ./MP3/imdct.o ./MP3/imdct.su ./MP3/mp3dec.d ./MP3/mp3dec.o ./MP3/mp3dec.su ./MP3/mp3tabs.d ./MP3/mp3tabs.o ./MP3/mp3tabs.su ./MP3/polyphase.d ./MP3/polyphase.o ./MP3/polyphase.su ./MP3/scalfact.d ./MP3/scalfact.o ./MP3/scalfact.su ./MP3/stproc.d ./MP3/stproc.o ./MP3/stproc.su ./MP3/subband.d ./MP3/subband.o ./MP3/subband.su ./MP3/trigtabs.d ./MP3/trigtabs.o ./MP3/trigtabs.su

.PHONY: clean-MP3

