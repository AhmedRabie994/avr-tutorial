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
adc_T_F_DRIVER.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: adc_T_F_DRIVER.elf secondary-outputs

# Tool invocations
adc_T_F_DRIVER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,adc_T_F_DRIVER.map -mmcu=atmega16 -o "adc_T_F_DRIVER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

adc_T_F_DRIVER.lss: adc_T_F_DRIVER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S adc_T_F_DRIVER.elf  >"adc_T_F_DRIVER.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: adc_T_F_DRIVER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 adc_T_F_DRIVER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) adc_T_F_DRIVER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
