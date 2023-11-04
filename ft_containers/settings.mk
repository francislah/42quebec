ifndef SETTINGS_MK
 SETTINGS_MK = 1

## ************************************************************************** ##
##                             Project Variables                              ##
## ************************************************************************** ##

NAME = containers
STD = containers_std

CC = c++
FLAGS = $(CXXFLAGS) #For programs in c++
#CC = gcc
#FLAGS = $(CFLAGS) #For programs in c

ARG = 

SRC = 
INCS =	map.hpp pair.hpp make_pair.hpp

MAIN_F = main.cpp
MAIN_STD_F = main_std.cpp

LDFLAGS += 
LIBS = 
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