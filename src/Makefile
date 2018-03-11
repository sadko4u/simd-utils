FILE                    = $(@:$(OBJDIR)/%.o=%.cpp)

.PHONY: all target

target: all

all: $(OBJ_DSP)

$(OBJ_DSP): $(OBJDIR)/dsp.o $(OBJDIR)/dsp/dsp.o
	@echo "  $(LD) $(notdir $(OBJ_DSP))"
	@$(LD) -r $(LDFLAGS) -o $(OBJ_DSP) $(OBJDIR)/dsp.o $(OBJDIR)/dsp/dsp.o

$(OBJDIR)/dsp.o:
	@echo "  $(CC) $(FILE)"
	@$(CC) -c $(CPPFLAGS) $(CFLAGS) $(INCLUDE) $(FILE) -o $(@)

$(OBJDIR)/dsp/dsp.o:
	@echo "Building $(@)..."
	@mkdir -p $(OBJDIR)/dsp
	@$(MAKE) $(MAKE_OPTS) -C dsp all OBJDIR=$(OBJDIR)/dsp
