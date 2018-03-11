FILE                    = $(@:$(OBJDIR)/%.o=%.cpp)

ALL_IMPL                = $(OBJDIR)/dsp.o
NATIVE_IMPL             = $(OBJDIR)/native.o
X86_IMPL                = $(OBJDIR)/x86.o
SSE_IMPL                = $(OBJDIR)/sse.o
AVX_IMPL                = $(OBJDIR)/avx.o

SSE_INSTR_FLAGS         = -mmmx -m3dnow -msse
AVX_INSTR_FLAGS         = -mavx

# Form set of object to compile and link
LINK_OBJECTS            = $(NATIVE_IMPL)
ifeq ($(CPU_ARCH), i586)
LINK_OBJECTS           += $(X86_IMPL) $(SSE_IMPL) $(AVX_IMPL)
endif
ifeq ($(CPU_ARCH), x86_64)
LINK_OBJECTS           += $(X86_IMPL) $(SSE_IMPL) $(AVX_IMPL)
endif

.PHONY: all

all: $(ALL_IMPL)

$(ALL_IMPL): $(LINK_OBJECTS)
	@echo "  $(LD) $(notdir $(ALL_IMPL))"
	@$(LD) -r $(LDFLAGS) -o $(ALL_IMPL) $(LINK_OBJECTS)

$(NATIVE_IMPL) $(X86_IMPL):
	@echo "  $(CC) $(FILE)"
	@$(CC) -c $(CPPFLAGS) $(CFLAGS) $(INCLUDE) $(FILE) -o $(@)
	
$(SSE_IMPL):
	@echo "  $(CC) $(FILE)"
	@$(CC) -c $(CPPFLAGS) $(CFLAGS) $(SSE_INSTR_FLAGS) $(INCLUDE) $(FILE) -o $(@)
	
$(AVX_IMPL):
	@echo "  $(CC) $(FILE)"
	@$(CC) -c $(CPPFLAGS) $(CFLAGS) $(AVX_INSTR_FLAGS) $(INCLUDE) $(FILE) -o $(@)
