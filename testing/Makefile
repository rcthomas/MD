
include ../Makefile

# Google Test.

GTEST_DIR=./gtest
CXXFLAGS += -I$(GTEST_DIR)/include -pthread
LDFLAGS  += -L$(GTEST_DIR)/lib
LIBS     += -lgtest

# MD

MD_DIR=..
CXXFLAGS += -I$(MD_DIR)/include

#

TARGETS=$(patsubst %-test.cc,%-test,$(wildcard *-test.cc))

all : gtest $(TARGETS)
	$(foreach target,$(TARGETS),make $(target) && ./$(target);)

%-test : %-test.cc
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $< -o $@ $(LIBS)

gtest : $(GTEST_DIR)/lib/libgtest.a

$(GTEST_DIR)/lib/libgtest.a :
	cd $(GTEST_DIR) && make all

clean :
	rm -rf *.o

realclean : clean
	rm -rf $(TARGETS) core.*

deepclean : realclean
	cd gtest && make realclean
