ifndef SETTINGS_MK
 SETTINGS_MK = 1

## ************************************************************************** ##
##                             Project Variables                              ##
## ************************************************************************** ##

NAME = mutated

CC = c++
FLAGS = $(CXXFLAGS) #For programs in c++
#CC = gcc
#FLAGS = $(CFLAGS) #For programs in c

ARG = 

SRCS = 
INCS = MutantStack.hpp

SRC := $(SRCS)
SRC += main.cpp

LDFLAGS += 
LIBS  = 

LEAKS = valgrind $(LEAK-F) $(LEAK-A) $(LEAK-C)
LEAK-F = --leak-check=full
LEAK-A = --show-leak-kinds=all
LEAK-C = --trace-children=yes

#LEAKS = leaks --atExit --

## ************************************************************************** ##
##                             Pre-Compilation                                ##
## ************************************************************************** ##

all: $(NAME)

endif