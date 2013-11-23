#***********************************************************************
#* Description:                                                        *
#* ------------                                                        *
#*                                                                     *
#* Author: Martin Ettl (ettl[dot]martin78[AT]gmail[dot]com)            *
#* Date  : 2013-11-26                                                  *
#*                                                                     *
#* LINUX-Makefile (gmake): Ubuntu linux                                *
#* Makefile to compile and build all necessary programms.              *
#*                                                                     *
#* Usage and basic features:                                           *
#*                                                                     *
#*  - make build  [creates the whole project]                          *
#*  - make clean  [removes all object and binary files]                *
#*  - make depend [detects header dependencies]                        *
#*                                                                     *
#***********************************************************************

# path settings:
SOURCE_DIR			= ../src
OBJECT_DIR			= ../obj
MAKE_DIR 			= ../make
BIN_DIR 			= ../bin
CONFIG_DIR			= ../config
ICON_DIR			= $(SOURCE_DIR)/image

#######################################################################
# Determine the number cores of the machine, where the makefile is 
# executed. This sets the -j option (from make), to speedup the 
# build process of 'large' projects.  
NPROCS=1
OS:=$(shell uname -s)
ifeq ($(OS),Linux)
    NPROCS:=$(shell grep -c ^processor /proc/cpuinfo) 
endif
#######################################################################

#######################################################################
# c++ - compiler settings
#
CPPCOMPILER_DEFINES     =
CPPCOMPILER_INCLUDES    = 
CPPCOMPILER_WARN_FLAGS  = -O2 -W -Wall -Wshadow -Wno-long-long\
						  -Wno-variadic-macros -pedantic -ansi\
						  -fno-strict-aliasing 
CPPCOMPILER 	     	= g++
CPPCOMPILER_FLAGS    	= `wx-config --cxxflags --version=2.8 --unicode=yes`\
							$(CPPCOMPILER_INCLUDES)\
							$(CPPCOMPILER_DEFINES)\
							$(CPPCOMPILER_WARN_FLAGS)
CPPCOMPILER_CALL     	= $(CPPCOMPILER) -c $(CPPCOMPILER_FLAGS) -o $@ $< 

#######################################################################
# c compiler settings
CCOMPILER 				= gcc
CCOMPILER_FLAGS 		= `wx-config --cxxflags --version=2.8 --unicode=yes` -W -Wall -Wunused -ansi -O2
CCOMPILER_CALL 			= $(CCOMPILER) -c $(CCOMPILER_FLAGS) -o $@ $< 

#######################################################################
# linker settings
LINKER 					= $(CPPCOMPILER)
LINKER_FLAGS 			= `wx-config --libs adv,core,base,aui --version=2.8 --unicode=yes` 
LINKER_CALL 			= $(LINKER) -o $@ $^ $(LINKER_FLAGS)

# Targets
all: $(BIN_DIR)/wxTemplate

# ============================================================
# LINKER-RULES
# ===========================================================
../bin/wxTemplate : $(OBJECT_DIR)/Application.o\
                    $(OBJECT_DIR)/Frame.o
	    
	$(LINKER_CALL)
# 
# ===========================================================
# SOURCES
# ===========================================================
SRCS =  $(SOURCE_DIR)/Application.cpp\
	$(SOURCE_DIR)/Frame.cpp

 
CSRCS =

# ===========================================================
# SUPPORTING-RULES
# ===========================================================
touch:
	touch $(SOURCE_DIR)/*

build: mrproper depend 
	# after generating the dependencies it is necessary to call make again
	make -j$(NPROCS) all 


clean:
	rm -f $(BIN_DIR)/*
	rm -f $(OBJECT_DIR)/*
	rm -f $(SOURCE_DIR)/*.orig
	rm -f $(SOURCE_DIR)/*.bck
	rm -f $(MAKE_DIR)/.Makefile*
	rm -f $(MAKE_DIR)/*.bck
	rm -f $(MAKE_DIR)/*.bak

mrproper: clean
	rm -f $(CONFIG_DIR)/*.bck

style:
	find $(SOURCE_DIR) -name "*.cpp" -type f -exec astyle --style=ansi -S -N -w -Y -p -C -c {} \;
	find $(SOURCE_DIR) -name "*.hpp" -type f -exec astyle --style=ansi -S -N -w -Y -p -C -c {} \;
	find $(SOURCE_DIR) -name "*.c"   -type f -exec astyle --style=ansi -S -N -w -Y -p -C -c {} \;
	find $(SOURCE_DIR) -name "*.h"   -type f -exec astyle --style=ansi -S -N -w -Y -p -C -c {} \;

depend:
	@cat < /dev/null > makedep
	@cat < /dev/null > cmakedep
# First C++
	@for i in ${SRCS}; do \
		 (echo $$i; $(CPPCOMPILER) $(CPPCOMPILER_FLAGS) -MM $$i >> makedep); done
#       Write full path information before each *.o-dependency
	@echo 's/.*\.o:/..\/obj\/&/g' > eddep
	@sed -f eddep makedep > makedep1
	@mv makedep1 makedep
	@rm eddep
#       Add the rule to each dependency
	@echo 'a' > eddep
	@echo '	$$(CPPCOMPILER_CALL)' >> eddep
	@echo '.' >> eddep
	@echo 'g/.*\.o:/i\' >> eddep
	@echo '	$$(CPPCOMPILER_CALL)\' >> eddep
	@echo '.' >> eddep
	@echo '1,1d' >> eddep
	@echo 'w' >> eddep
	@ed - makedep < eddep
	@rm eddep
# Then C
	@for i in ${CSRCS}; do \
		 (echo $$i; $(CCOMPILER) $(CCOMPILER_FLAGS) -MM $$i >> cmakedep); done
#       Write full path information before each *.o-dependency
	@echo 's/.*\.o:/..\/obj\/&/g' > ceddep
	@sed -f ceddep cmakedep > cmakedep1
	@mv cmakedep1 cmakedep
	@rm ceddep
##       Add the rule to each dependency
	@echo 'a' > ceddep
	@echo '	$$(CCOMPILER_CALL)' >> ceddep
	@echo '.' >> ceddep
	@echo 'g/.*\.o:/i\' >> ceddep
	@echo '	$$(CCOMPILER_CALL)\' >> ceddep
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
