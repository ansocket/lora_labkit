# name of the application
APPLICATION = app

# If no BOARD is found in the environment, use this default:
BOARD ?= lora_labkit

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= /home/hocok/RIOT_Repo/RIOT
PROGRAMMER ?= bmp

# required features
FEATURES_REQUIRED += periph_uart

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

EXTERNAL_BOARD_DIRS = $(RIOTBASE)/../external_boards

include $(RIOTBASE)/Makefile.include
