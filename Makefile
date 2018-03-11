ARTIFACT_ID             = simd-utils
OBJDIR                  = ${CURDIR}/.build

# Package version
ifndef VERSION
VERSION                 = 0.0.1
endif

# Directories
export VERSION
export RELEASE_TEXT
export ROOTDIR          = ${CURDIR}
export SRCDIR           = ${CURDIR}/src
export BUILDDIR         = $(OBJDIR)

# Includes
INC_FLAGS               = -I"${CURDIR}/include"

# Build profile
ifeq ($(BUILD_PROFILE),i586)
export CPU_ARCH         = i586
export CC_ARCH          = -m32
export LD_ARCH          = -m elf_i386
export LD_PATH          = /usr/lib:/lib:/usr/local/lib
endif

ifeq ($(BUILD_PROFILE),x86_64)
export CPU_ARCH         = x86_64
export CC_ARCH          = -m64
export LD_ARCH          = -m elf_x86_64
export LD_PATH          = /usr/lib:/lib:/usr/local/lib
endif

ifndef CPU_ARCH
export CPU_ARCH         = x86_64
export CC_ARCH          = -m64
export LD_ARCH          = -m elf_x86_64
export LD_PATH          = /usr/lib:/lib:/usr/local/lib
endif

# Location
export BASEDIR          = ${CURDIR}
export INCLUDE          = ${INC_FLAGS}
export MAKE_OPTS        = -s
export CFLAGS           = $(CC_ARCH) -std=c++98 -fPIC -fdata-sections -ffunction-sections -fno-exceptions -fno-asynchronous-unwind-tables -Wall -pthread -pipe -fno-rtti $(CC_FLAGS) -DLSP_MAIN_VERSION=\"$(VERSION)\"
export CC               = g++
export LDFLAGS          = $(LD_ARCH) -L$(LD_PATH)

# Objects
export OBJ_DSP          = $(OBJDIR)/dsp-utils.o
export BIN_DSP          = $(OBJDIR)/dsp-utils

# Functional variables
FILE                    = $(@:$(OBJDIR)/%.o=%.cpp)

.PHONY: all gdb clean default

default: all

all: export CFLAGS          += -O2
all: $(BIN_DSP)

gdb: export CFLAGS          += -O0
gdb: $(BIN_DSP)

$(BIN_DSP): $(OBJ_DSP) $(OBJDIR)/main.o
	@echo "  $(LD) $(notdir $(BIN_DSP))"
	@$(CC) -o $(BIN_DSP) $(OBJ_DSP) $(OBJDIR)/main.o
	
$(OBJDIR)/main.o:
	@echo "  $(CC) $(FILE)"
	@$(CC) -c $(CPPFLAGS) $(CFLAGS) $(INCLUDE) $(FILE) -o $(@)
 
$(OBJ_DSP):
	@echo "Building binaries"
	@mkdir -p $(OBJDIR)/src
	@$(MAKE) $(MAKE_OPTS) -C src all OBJDIR=$(OBJDIR)/src
	@echo "Build OK"

clean:
	@-rm -rf $(OBJDIR)
	@echo "Clean OK"
