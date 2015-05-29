# ClangMakefile

CXX        = clang++
CXXFLAGS   = -std=c++11 -O3

none :

test :
	cd testing && make all

distclean :
	cd testing && make deepclean
