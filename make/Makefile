#/***********************************************************************
#* SVN: Version Control with Subversion
#* ---------------------------------------------------------------------
#* $Id$
#***********************************************************************
#* LICENSE AND WARRANTY INFORMATION
#* ================================
#* 
#* Copyright (C) 2011
#* Forschungseinrichtung Satellitengeodaesie, TU Muenchen &
#* Bundesamt fuer Kartographie und Geodaesie
#* Geodetic Observatory Wettzell
#* Sackenrieder Str. 25
#* D-93444 Bad Koetzting
#* Germany
#*
#* This program is FREE SOFTWARE under the terms of GNU Lesser General
#* Public License v3 (or any later version) and may be used following
#* this definitions as published by the Free Software Foundation at
#* http://www.gnu.de/documents/lgpl-3.0.en.html. Software parts which
#* include elements from external software distributions may be under
#* different licenses as the Sun License/BSD License for the ONC/Sun RPC
#* (http://www.opensource.org/licenses/bsd-license.php)
#* and the wxWindows Library Licence for the GUI parts with wxWidgets
#* (http://www.opensource.org/licenses/wxwindows.php).
#* In case of variations to the above licenses each particular developer
#* is responsible for defining the dedicated license conditions and terms.
#*
#* This program is distributed in the hope that it will be useful.
#* IT IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING
#* THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A
#* PARTICULAR PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE
#* OR TRADE PRACTICE.
#*
#* The software is provided with no support and without any obligation
#* on the part of the Geodetic Observatory Wettzell to assist in its
#* use, correction, modification or enhancement. THE Geodetic Observatory
#* Wettzell SHALL HAVE NO LIABILITY WITH RESPECT TO THE INFRINGEMENT OF
#* COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THE SOFTWARE OR ANY PART
#* THEREOF. In no event will the Geodetic Observatory Wettzell be liable
#* for any lost revenue or profits or other special, indirect and
#* consequential damages, even if the Geodetic Observatory Wettzell
#* has been advised of the possibility of such damages.
#*
#* You should have received a copy of the license(s) along with this program.
#**********************************************************************/
 
#***********************************************************************
#* Description:                                                        *
#* ------------                                                        *
#*                                                                     *
#* Author: Martin Ettl (ettl@fs.wettzell.de)                           *
#* Date  : 2011-09-15                                                  *
#*                                                                     *
#* LINUX-Makefile (gmake): Ubuntu linux                                *
#* Makefile to compile and build all necessary programms.              *
#*                                                                     *
#* Usage and basic features:                                           *
#*                                                                     *
#*  - make build  [creates the whole project]                          *
#*  - make clean  [removes all object and binary files]                *
#*  - make depend [detects header dependencies]                        *
#*  - make rpc    [generates files using idl2rpc]                      *
#*                                                                     *
#***********************************************************************

# ============================================================
# DEFINITIONS
# ============================================================

# path settings:
SOURCE_DIR			= ../src
OBJECT_DIR			= ../obj
MAKE_DIR 			= ../make
BIN_DIR 			= ../bin
CONFIG_DIR			= ../config
RPC_DIR 			= ../rpc
ICON_DIR			= $(SOURCE_DIR)/image

#######################################################################
# path to the idl2rpc generated clients
IDL2RPC_CALL 			= idl2rpc.pl
#
#######################################################################
#######################################################################
# Determine the number cores of the machine, where the makefile is executed.
# This helps to set the -j option (from make), to speedup the build
# process of 'large' projects.  
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
CPPCOMPILER_WARN_FLAGS  = -O2 -W -Wall -Wshadow -Wno-long-long -Wno-variadic-macros -pedantic -ansi -fno-strict-aliasing 
CPPCOMPILER 	     	= g++
CPPCOMPILER_FLAGS    	= `wx-config --cxxflags --version=2.8 --unicode=yes`\
		          $(CPPCOMPILER_INCLUDES)\
			  $(CPPCOMPILER_DEFINES)\
			  $(CPPCOMPILER_WARN_FLAGS)
CPPCOMPILER_CALL     	= $(CPPCOMPILER) -c $(CPPCOMPILER_FLAGS) -o $@ $< 

#######################################################################
# c compiler settings
CCOMPILER 	= gcc
CCOMPILER_FLAGS = `wx-config --cxxflags --version=2.8 --unicode=yes` -W -Wall -Wunused -ansi -O2
CCOMPILER_CALL 	= $(CCOMPILER) -c $(CCOMPILER_FLAGS) -o $@ $< 

#######################################################################
# linker settings
LINKER 		= $(CPPCOMPILER)
LINKER_FLAGS 	= `wx-config --libs adv,core,base,aui --version=2.8 --unicode=yes` 
LINKER_CALL 	= $(LINKER) -o $@ $^ $(LINKER_FLAGS)


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

#rpc:
	#$(IDL2RPC_CALL) $(SLR_SCHEDULER_IDL_CONFIG) $(SLR_SCHEDULER_SRC_PATH)/$(SLR_SCHEDULER_IDL_FILE_NAME)

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
