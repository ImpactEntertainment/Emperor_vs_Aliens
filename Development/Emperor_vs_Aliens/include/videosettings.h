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
typedef enum {SINGLE_BUFFER, DOUBLE_BUFFER} BufferingMode;

ostream& operator<<(ostream& os, VideoBufferLocation videoBufferLocation);
ostream& operator<<(ostream& os, MachineArchitecture machineArchitecture);
ostream& operator<<(ostream& os, BufferingMode bufferingMode);

class VideoSettings {
	friend ostream& operator<<(ostream& os, const VideoSettings settings);
	
public:
	VideoSettings();
	VideoSettings(const VideoSettings& settings);

	VideoSettings& operator=(const VideoSettings& settings);
	bool operator!=(const VideoSettings& settings);

	VideoBufferLocation videoBufferLocation;
	MachineArchitecture machineArchitecture;
	BufferingMode bufferingMode;
};	

}

#endif

