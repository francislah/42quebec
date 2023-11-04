ifndef SETTINGS_MK
 SETTINGS_MK = 1

## ************************************************************************** ##
##                             Project Variables                              ##
## ************************************************************************** ##

NAME = btc

CC = c++
FLAGS = $(CXXFLAGS) #For programs in c++

ARG = input.txt

SRCS = BitcoinExchange.cpp
INCS = BitcoinExchange.hpp

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