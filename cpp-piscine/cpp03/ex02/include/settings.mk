ifndef SETTINGS_MK
 SETTINGS_MK = 1

## ************************************************************************** ##
##                             Project Variables                              ##
## ************************************************************************** ##

NAME	= frag

CC = c++
#FLAGS	= $(CFLAGS) #For programs in c
FLAGS	= $(CXXFLAGS) #For programs in c++

ARG = 

SRCS = 	ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

SRC := $(SRCS)
SRC += main.cpp

LDFLAGS	+= 
LIBS 	= 

## ************************************************************************** ##
##                             Pre-Compilation                                ##
## ************************************************************************** ##
all: $(NAME)

endif