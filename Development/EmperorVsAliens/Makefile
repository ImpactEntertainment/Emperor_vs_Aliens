#version
MAJOR_VERSION=0
MINOR_VERSION=9
MICRO_VERSION=20
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
					-I$(CURDIR)/$(BUILD)
										
# Compiler
TARGET		:=	$(notdir $(CURDIR))
# Object files

LIBS	:=	-lSDL -lSDL_image -lSDL_mixer -lSDL_ttf   
			
# Flags
CPPFLAGS=-Wall -g -W -pedantic -ansi

# Linking flags
LDFLAGS= $(LIBS)

$(BUILD)/%.o:$(SOURCES)/%.cpp
	@mkdir -p $(BUILD)
	@echo building $^ ...
	@$(LD) $(CPPFLAGS) -c $^ -o $@ $(INCLUDE)

main:$(OFILES)
	@mkdir -p $(BUILD)
	@echo linking ...
	@$(LD) $(OFILES) $(CPPFLAGS) $(LDFLAGS) -o $(TARGET)
	@echo "$(TARGET)-$(VERSION)"

# Cleanup
clean:
	@echo clean ...
	@rm -rf $(BUILD)
	@rm -f $(TARGET)

install:
	@sudo mkdir -p /opt/$(TARGET)
	@sudo cp -Rf data /opt/$(TARGET)/
	@sudo cp -f $(TARGET) /opt/$(TARGET)/$(TARGET)
	@sudo ln -sf /opt/$(TARGET)/$(TARGET) /usr/local/bin/$(TARGET)

uninstall:
	@sudo rm -rf /opt/$(TARGET)
	@sudo rm -f /usr/local/bin/$(TARGET)
