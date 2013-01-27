/**
 * \file videosettings.h
 * \brief Representação das opções de vídeo. 
 *
 * Esta classe representa as opções específicas de vídeo. As opções
 * de janela estão na classe WindowsSettings.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 30/12/2012
 */
#ifndef EDGE_VIDEO_SETTINGS_H
#define EDGE_VIDEO_SETTINGS_H

#include <ostream>

using namespace std;

namespace edge {

typedef enum {SYSTEM_MEMORY, VIDEO_MEMORY} VideoBufferLocation;
typedef enum {SINGLE_CORE, MULTI_CORE} MachineArchitecture;
typedef enum {SYSTEM, INDEXED, HICOLOR, TRUE_COLOR, RGBA} ColorDepth;
typedef enum {SINGLE_BUFFER, DOUBLE_BUFFER} BufferingMode;
typedef enum {BIDIMENSIONAL, TRIDIMENSIONAL, MIXED} RenderingMode;

ostream& operator<<(ostream& os, VideoBufferLocation videoBufferLocation);
ostream& operator<<(ostream& os, MachineArchitecture machineArchitecture);
ostream& operator<<(ostream& os, ColorDepth colorDepth);
ostream& operator<<(ostream& os, BufferingMode bufferingMode);
ostream& operator<<(ostream& os, RenderingMode renderingMode);

class VideoSettings {
	friend ostream& operator<<(ostream& os, const VideoSettings settings);
	
public:
	VideoSettings(VideoBufferLocation videoBufferLocation = VIDEO_MEMORY, 
		MachineArchitecture machineArchitecture = SINGLE_CORE, 
		ColorDepth colorDepth = HICOLOR,
		BufferingMode bufferingMode = DOUBLE_BUFFER, 
		RenderingMode renderingMode = BIDIMENSIONAL);

	VideoBufferLocation videoBufferLocation;
	MachineArchitecture machineArchitecture;
	ColorDepth colorDepth;
	BufferingMode bufferingMode;
	RenderingMode renderingMode;
};	

}

#endif

