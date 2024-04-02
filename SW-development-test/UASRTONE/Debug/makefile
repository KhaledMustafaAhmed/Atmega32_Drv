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
UASRTONE.lss \

FLASH_IMAGE += \
UASRTONE.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: UASRTONE.elf secondary-outputs

# Tool invocations
UASRTONE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,UASRTONE.map -mmcu=atmega32 -o "UASRTONE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

UASRTONE.lss: UASRTONE.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S UASRTONE.elf  >"UASRTONE.lss"
	@echo 'Finished building: $@'
	@echo ' '

UASRTONE.hex: UASRTONE.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex UASRTONE.elf  "UASRTONE.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: UASRTONE.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 UASRTONE.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) UASRTONE.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
