#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?=HOST

ifeq ($(PLATFORM),HOST)
CC=gcc
CFLAGS= -DHOST -DCOURSE1 -DVERBOSE
ARCH= corei7
LD=gcc
LDFLAGS = 
else
CC=arm-none-eabi-gcc
CFLAGS= -DMSP432 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
LD= arm-none-eabi-ld
LDFLAGS = -Map $(BASENAME).map -T ../msp432p401r.lds 
# CPU = cortex-m4
ARCH = armv7e-m
endif

# Architectures Specific Flags

# Compiler Flags and Defines
BASENAME= main


# SPECS = nosys.specs



CFLAGS +=  -march=$(ARCH) -Wall -Werror -g -O0 -std=c99  $(INCLUDES)#--specs=$(SPECS) -mcpu=$(CPU)
TARGET= $(BASENAME).out
OBJS = $(SOURCES:.c=.o)
ASEMS=$(SOURCES:.c=.asm)
PREPS=$(SOURCES:.c=.i)
DEPS=$(SOURCES:.c=.dep)

.PHONY:build

build:$(TARGET)

$(TARGET):$(OBJS) 
	$(LD) $(OBJS) -o $(TARGET) $(LDFLAGS) 

.PHONEY:compile-all

compile-all: $(OBJS)

%.o:%.asm
	$(CC) -MM -c $< -MP -MF -MD $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< 

%.asm:%.i 
	$(CC) $(CFLAGS) -o $@ -s $< 

%.i:%.c 
	$(CC) $(CFLAGS) -o $@ -E $< 


.PHONY:clean
clean:
	rm -f $(OBJS) $(TARGET) $(BASENAME).map $(PREPS) $(ASEMS)


