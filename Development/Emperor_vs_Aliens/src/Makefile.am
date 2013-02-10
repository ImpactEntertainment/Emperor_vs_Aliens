# Author: Edson Alves - edsonalves@unb.br
# Date: 21/12/2012

# Library description
lib_LTLIBRARIES = libedge.la 

# Programs excluded from instalation
bin_PROGRAMS = EmperorVsAliens

# Library flags
libedge_la_LDFLAGS = -static

# Library sources
libedge_la_SOURCES =	draw.cpp \
						videosettings.cpp \
						windowsettings.cpp \
						sdlvideo.cpp \
						sdlwindow.cpp \
						sdlvideosettings.cpp \
						sdlwindowfactory.cpp \
						sdlwindowsettings.cpp \
						sdlcanvas.cpp \
						point.cpp \
						color.cpp \
						rectangle.cpp \
						line.cpp \
						circle.cpp \
						sdlimage.cpp \
						boundingrectangle.cpp \
						element.cpp \
						game.cpp

# Libraries needed to build our library
libedge_la_LIBADD = -lSDL 

# Program description
EmperorVsAliens_SOURCES =	EmperorVsAliens.cpp

# Libraries needed to build program
EmperorVsAliens_LDADD = libedge.la -lSDL -lSDL_image

# Include flags
INCLUDES = -I./include -Wall -Wno-long-long -W -pedantic -ansi

