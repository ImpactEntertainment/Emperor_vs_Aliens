#version
MAJOR_VERSION=0
MINOR_VERSION=3
MICRO_VERSION=0
VERSION=$(MAJOR_VERSION).$(MINOR_VERSION).$(MICRO_VERSION)

BUILD		:=	build
SOURCES		:=	source
DATA		:=	data
INCLUDES	:=	include


#---------------------------------------------------------------------------------
# automatically build a list of object files for our project
#---------------------------------------------------------------------------------
CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=  $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
sFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.S)))
BINFILES	:=	$(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))



#---------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------

export LD	:=	$(CXX)


export OFILES	:=	 $(addprefix $(BUILD)/,$(CPPFILES:.cpp=.o))
					
					
CPPFILES	:=   $(addprefix $(SOURCES)/,$(CPPFILES))

#---------------------------------------------------------------------------------
# build a list of include paths
#---------------------------------------------------------------------------------
export INCLUDE	:=	$(foreach dir,$(INCLUDES), -I$(CURDIR)/$(dir)) \
					$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
					-I$(CURDIR)/$(BUILD)
										
# Compiler
TARGET		:=	$(notdir $(CURDIR))
# Object files

LIBS	:=	-lSDL -lSDL_image -lSDL_mixer -lSDL_ttf   
			
# Flags
CPPFLAGS=-Wall -g -W -pedantic -ansi

# Linking flags
LDFLAGS= $(LIBS)

main: 
	@echo building ...
	@$(LD) $(CPPFLAGS)  -c $(CPPFILES) $(INCLUDE)
	@mv *.o $(BUILD)
	@echo linking ...
	@$(LD) $(OFILES) $(CPPFLAGS) $(LDFLAGS) -o $(TARGET)
	@echo "$(TARGET)-$(VERSION)"

# Cleanup
clean:
	@echo clean ...
	@rm -rf $(OFILES)
	@rm -f $(TARGET)


