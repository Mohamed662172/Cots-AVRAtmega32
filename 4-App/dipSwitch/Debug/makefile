################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
dipSwitch.lss \

FLASH_IMAGE += \
dipSwitch.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: dipSwitch.elf secondary-outputs

# Tool invocations
dipSwitch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,dipSwitch.map -mmcu=atmega32 -o "dipSwitch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

dipSwitch.lss: dipSwitch.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S dipSwitch.elf  >"dipSwitch.lss"
	@echo 'Finished building: $@'
	@echo ' '

dipSwitch.hex: dipSwitch.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex dipSwitch.elf  "dipSwitch.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: dipSwitch.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 dipSwitch.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) dipSwitch.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
