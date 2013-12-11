#***********************************************************************
#* Description:                                                        *
#* ------------                                                        *
#*                                                                     *
#* Author: Martin Ettl (ettl[dot]martin78[AT]gmail[dot]com)            *
#* Date  : 2013-11-26                                                  *
#*                                                                     *
#* LINUX-Makefile (gmake): Ubuntu Linux                                *
#* A makefile to compile wxWidgets programms.              		   	   *
#*                                                                     *
#* Usage and basic features:                                           *
#*                                                                     *
#*  - make build  [creates the whole project]                          *
#*  - make clean  [removes all object and binary files]                *
#*  - make depend [detects header dependencies]                        *
#*                                                                     *
#***********************************************************************

# ----------------------------------------------------------------------
# Path settings:
SRC_DIR				= ../src
SRC_EXT_DIR         = ../srcext
SRC_TEST            = ../src-test
OBJ_DIR				= ../obj
MAKE_DIR 			= ../make
BIN_DIR 			= ../bin
CONFIG_DIR			= ../config
ICON_DIR			= $(SOURCE_DIR)/image
APP_NAME			= wxTemplate

# ----------------------------------------------------------------------
# Determine the number cores of the machine, where the makefile is 
# executed. This sets the -j option (from make), to speedup the 
# build process of 'large' projects.  
NPROCS=1
OS:=$(shell uname -s)
ifeq ($(OS),Linux)
    NPROCS:=$(shell grep -c ^processor /proc/cpuinfo) 
endif

# ----------------------------------------------------------------------
# Configure wxWidgets build
WXVERSION = 2.8
WXCONFIG_CALL = `wx-config --cxxflags --unicode=yes --version=$(WXVERSION)`
WXCONFIG_LINKER_CALL = `wx-config --version=$(WXVERSION) --libs adv,aui,core,base,html,richtext,xml`

# ----------------------------------------------------------------------
# C++ compiler settings:
CXX 		= g++
CXX_OPT		= -O2 
CXX_INCLUDE	= -I$(SRC_DIR) -I$(SRC_EXT_DIR) -I$(SRC_TEST) 
CXX_WFLAGS  = -W -Wall -Wunused -Wshadow -Wconversion -Wsign-conversion\
			  -Wextra -ansi -pedantic -Wno-write-strings -fno-strict-aliasing
CXXFLAGS 	= $(WXCONFIG_CALL)\
			  $(CXX_WFLAGS)\
			  $(CXX_INCLUDE)\
			  $(CXX_OPT)
CXX_CALL    = $(CXX) -c $(CXXFLAGS) -o $@ $< 

# ----------------------------------------------------------------------
# C compiler settings:
CC	        = gcc
CC_INCLUDE  = 
CC_OPT      = -O2
CC_WFLAGS   = -W -Wall -Wunused -Wextra -Wconversion -ansi -pedantic
CFLAGS 	    = $(WXCONFIG_CALL) -I$(CC_INCLUDE) $(CC_OPT) $(CC_WFLAGS)
CC_CALL     = $(CC) -c $(CFLAGS) -o $@ $< 

# ----------------------------------------------------------------------
# Linker settings:
LINKER      = $(CXX) 
LDFLAGS     = $(WXCONFIG_LINKER_CALL) 
LINKER_CALL = $(LINKER) -o $@ $^ $(LDFLAGS)

# Targets
all: $(BIN_DIR)/$(APP_NAME)

# ----------------------------------------------------------------------
# Linker rules:
$(BIN_DIR)/$(APP_NAME) : $(OBJ_DIR)/Application.o\
						 $(OBJ_DIR)/Frame.o
	    
	$(LINKER_CALL)

# ----------------------------------------------------------------------
# C++ sources:
SRCS =  $(SRC_DIR)/Application.cpp\
	    $(SRC_DIR)/Frame.cpp

# ----------------------------------------------------------------------
# C sources: 
CSRCS =

# ----------------------------------------------------------------------
# Supported rules: 
touch:
	/bin/touch $(SRC_DIR)/*

build: mrproper depend 
	# after generating the dependencies it is necessary to call make again
	/usr/bin/make -j$(NPROCS) all 

clean:
	/bin/rm -f $(BIN_DIR)/$(APP_NAME)
	/bin/rm -f $(OBJ_DIR)/*
	/bin/rm -f $(SRC_DIR)/*.orig
	/bin/rm -f $(SRC_DIR)/*.bck
	/bin/rm -f $(MAKE_DIR)/.Makefile*
	/bin/rm -f $(MAKE_DIR)/*.bck
	/bin/rm -f $(MAKE_DIR)/*.bak

mrproper: clean
	/bin/rm -f $(CONFIG_DIR)/*.bck

style:
	/usr/bin/find $(SRC_DIR) -name "*.cpp" -type f -exec astyle --style=ansi -S -N -w -Y -p -C -c {} \;
	/usr/bin/find $(SRC_DIR) -name "*.hpp" -type f -exec astyle --style=ansi -S -N -w -Y -p -C -c {} \;
	/usr/bin/find $(SRC_DIR) -name "*.c"   -type f -exec astyle --style=ansi -S -N -w -Y -p -C -c {} \;
	/usr/bin/find $(SRC_DIR) -name "*.h"   -type f -exec astyle --style=ansi -S -N -w -Y -p -C -c {} \;

depend:
	@cat < /dev/null > makedep
	@cat < /dev/null > cmakedep
# First C++
	@for i in ${SRCS}; do \
		 (echo $$i; $(CXX) $(CXXFLAGS) -MM $$i >> makedep); done
# Write full path information before each *.o-dependency
	@echo 's/.*\.o:/..\/obj\/&/g' > eddep
	@sed -f eddep makedep > makedep1
	@mv makedep1 makedep
	@rm eddep
# Add the rule to each dependency
	@echo 'a' > eddep
	@echo '	$$(CXX_CALL)' >> eddep
	@echo '.' >> eddep
	@echo 'g/.*\.o:/i\' >> eddep
	@echo '	$$(CXX_CALL)\' >> eddep
	@echo '.' >> eddep
	@echo '1,1d' >> eddep
	@echo 'w' >> eddep
	@ed - makedep < eddep
	@rm eddep
# Then C
	@for i in ${CSRCS}; do \
		 (echo $$i; $(CC_CALL) $(CFLAGS) -MM $$i >> cmakedep); done
# Write full path information before each *.o-dependency
	@echo 's/.*\.o:/..\/obj\/&/g' > ceddep
	@sed -f ceddep cmakedep > cmakedep1
	@mv cmakedep1 cmakedep
	@rm ceddep
# Add the rule to each dependency
	@echo 'a' > ceddep
	@echo '	$$(CC_CALL)' >> ceddep
	@echo '.' >> ceddep
	@echo 'g/.*\.o:/i\' >> ceddep
	@echo '	$$(CC_CALL)\' >> ceddep
	@echo '.' >> ceddep
	@echo '1,1d' >> ceddep
	@echo 'w' >> ceddep
	@ed - cmakedep < ceddep
	@rm ceddep
	@cat < cmakedep >> makedep
	@rm cmakedep
	@echo '# DO NOT EDIT THIS FILE HERE.' > .Makefile.dep
	@cat < makedep >> .Makefile.dep
	@echo '# DO NOT EDIT THIS FILE HERE.' >> .Makefile.dep
	@rm makedep

.Makefile.dep: 
	@cat < /dev/null > .Makefile.dep

include .Makefile.dep
