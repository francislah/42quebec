ifndef SETTINGS_MK
 SETTINGS_MK = 1

## ************************************************************************** ##
##                             Project Variables                              ##
## ************************************************************************** ##

NAME	= 28b

CC = c++
#FLAGS	= $(CFLAGS) #For programs in c
FLAGS	= $(CXXFLAGS) #For programs in c++

ARG = 

SRCS = 	Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp

SRC := $(SRCS)
SRC += main.cpp

LDFLAGS	+= 
LIBS 	= 

## ************************************************************************** ##
##                             Pre-Compilation                                ##
## ************************************************************************** ##
all: $(NAME)

endif