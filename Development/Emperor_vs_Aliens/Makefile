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
	@echo Done "<$(TARGET)>"

# Cleanup
clean:
	@echo clean ...
	@rm -rf $(OBJECTS)


