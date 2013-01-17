#version
MAJOR_VERSION=0
MINOR_VERSION=1
MICRO_VERSION=0
VERSION=$(MAJOR_VERSION).$(MINOR_VERSION).$(MICRO_VERSION)

# Compiler
CC=g++
TARGET		:=	$(notdir $(CURDIR))
# Object files
OBJECTS=main.o

LIBS	:=	-lSDL -lSDL_image -lSDL_mixer -lSDL_ttf   
	#		-lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lpng -ljpeg -lvorbisfile -lvorbis -logg -laudio -lmikmod -ltiff -lm -lfreetype -lz -lpixman-1 -lSDLmain -lrt  -lm 
			
# Flags
CPPFLAGS=-Wall -g -W

# Linking flags
LDFLAGS= $(LIBS)

main: 
	@echo building ...
	@$(CC) $(CPPFLAGS)  -c source/main.cpp
	@echo linking ...
	@$(CC) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS) -o $(TARGET)
	@echo "$(TARGET)-$(VERSION)"

# Cleanup
clean:
	@echo clean ...
	@rm -rf $(OBJECTS)


