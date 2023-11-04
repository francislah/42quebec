ifndef SETTINGS_MK
 SETTINGS_MK = 1

## ************************************************************************** ##
##                             Project Variables                              ##
## ************************************************************************** ##

NAME = easy

CC = c++
#CC = gcc
#FLAGS = $(CFLAGS) #For programs in c
FLAGS = $(CXXFLAGS) #For programs in c++

ARG = 

SRCS = 
INCS = easyfind.hpp

SRC := $(SRCS)
SRC += main.cpp

LDFLAGS += 
LIBS  = 

## ************************************************************************** ##
##                             Pre-Compilation                                ##
## ************************************************************************** ##

all: $(NAME)

endif