CURRPATH	= $(abspath .)
CXXFLAGS       += -ggdb
SRCFILES	= $(wildcard *.cc)
TESTFILES	= $(wildcard *.tcc)
TESTEXECUTABLES	= $(patsubst %.tcc,%.texe,$(TESTFILES))
SOFILES		= $(patsubst %.cc,%.so,$(SRCFILES))
RFILES		= $(addprefix Rivet,$(SOFILES))
TESTINCLUDES	= -lboost_unit_test_framework

ifdef BOOST_INC
	TESTINCLUDES += -I$(BOOST_INC)
	BOOSTPRESENT=$(BOOST_INC)
else
	BOOSTPRESENT=$(shell whereis libboost_unit_test_framework.so|cut -d " " -f3)	
endif

ifdef BOOST_LIB
	TESTINCLUDES += -L$(BOOST_LIB)
endif

tests : $(TESTEXECUTABLES)

%.texe : %.tcc configured
	@echo "Building test $(BINDIR)/$@ from $<!\n"
	g++ -x c++ $(CXXFLAGS) $< $(TESTINCLUDES) -o $(CURRPATH)/$@
	@echo "executing $@\n"
	$(CURRPATH)/$@


clean : 
	@echo "Cleaning directory"
	rm -f $(CURRPATH)/*.so $(CURRPATH)/*.exe $(CURRPATH)/*.texe 

configured :
	@if [ -z $(BOOSTPRESENT)  ] ; then echo -e "\n   !!!! ERROR: BOOST not set up properly!\n"; exit 1; fi

