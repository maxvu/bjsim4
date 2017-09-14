CC = g++
CC_FLAGS = -Wall -std=c++11
CC_DEBUG = -g
CC_DEBUG_STRIP = -s
CC_EXT = cpp
CC_HEADER_EXT = hpp

BINDIR = bin
LIBDIR = lib
BLDDIR = build
SRCDIR = src
TSTDIR = test
INCDIR = include

MAIN = Main.$(CC_EXT)
SOURCES = $(shell find $(SRCDIR)/*.$(CC_EXT) ! -name $(MAIN))
HEADERS = $(shell find $(INCDIR)/*.$(CC_HEADER_EXT))
TESTS   = $(shell find $(TSTDIR)/*.$(CC_EXT))

LIBCATCH = $(LIBDIR)/catch

# Main binary, without debugging symbols
$(BINDIR)/bjsim4 : $(SOURCES) $(HEADERS) $(SRCDIR)/$(MAIN)
	$(CC) $(CC_FLAGS) -I$(INCDIR) $(SOURCES) $(SRCDIR)/$(MAIN) $(CC_DEBUG_STRIP) -o $@

# Main binary, with debugging symbols
$(BINDIR)/bjsim4-dbg : $(SOURCES) $(HEADERS) $(SRCDIR)/$(MAIN)
	$(CC) $(CC_FLAGS) $(CC_DEBUG) -I$(INCDIR) $(SOURCES) $(SRCDIR)/$(MAIN) -o $@
debug : $(BINDIR)/bjsim4-dbg

# Test suite
$(BINDIR)/bjsim4-test : $(SOURCES) $(HEADERS) $(TESTS)
	$(CC) $(CC_FLAGS) $(CC_DEBUG) -I$(INCDIR) -I$(LIBCATCH) $(SOURCES) $(TESTS) -o $@
test : $(BINDIR)/bjsim4-test
	$^

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(BLDDIR)/*
