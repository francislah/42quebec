ifndef SETTINGS_MK
 SETTINGS_MK = 1

## ************************************************************************** ##
##                             Project Variables                              ##
## ************************************************************************** ##

NAME	= diamond

CC = c++
#FLAGS	= $(CFLAGS) #For programs in c
FLAGS	= $(CXXFLAGS) #For programs in c++

ARG = 

SRCS = 	ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

SRC := $(SRCS)
SRC += main.cpp

LDFLAGS	+= 
LIBS 	= 

## ************************************************************************** ##
##                             Pre-Compilation                                ##
## ************************************************************************** ##
all: $(NAME)

endif