################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../EXTI_programe.c \
../GIE_program.c \
../KPAD_program.c \
../LCD_Program.c \
../testINT0.c 

OBJS += \
./DIO_program.o \
./EXTI_programe.o \
./GIE_program.o \
./KPAD_program.o \
./LCD_Program.o \
./testINT0.o 

C_DEPS += \
./DIO_program.d \
./EXTI_programe.d \
./GIE_program.d \
./KPAD_program.d \
./LCD_Program.d \
./testINT0.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


