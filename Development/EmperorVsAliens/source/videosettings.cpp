/**
 * \file videosettings.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \date 30/12/2012
 */
#include "videosettings.h"

namespace edge {

ostream& operator<<(ostream& os, VideoBufferLocation videoBufferLocation)
{
	switch (videoBufferLocation) 
	{
		case SYSTEM_MEMORY:
			os << "System Memory";
			break;

		case VIDEO_MEMORY:
			os << "Video Memory";
			break;
	}

	return os;
}

ostream& 
operator<<(ostream& os, MachineArchitecture machineArchitecture)
{
	switch (machineArchitecture)
	{
		case SINGLE_CORE:
			os << "Single Core";
			break;

		case MULTI_CORE:
			os << "Multi Core";
			break;
	}
	
	return os;
}

ostream& 
operator<<(ostream& os, BufferingMode bufferingMode)
{
	switch (bufferingMode)
	{
		case SINGLE_BUFFER:
			os << "Single buffer";
			break;

		case DOUBLE_BUFFER:
			os << "Double buffer";
			break;
	}

	return os;
}

ostream& 
operator<<(ostream& os, const VideoSettings settings)
{
	os << "Video buffer location: " << settings.videoBufferLocation << endl;
	os << "Machine architecture: " << settings.machineArchitecture << endl;
	os << "Buffering mode: " << settings.bufferingMode << endl;

	return os;	
}
	
VideoSettings::VideoSettings(const VideoSettings& settings)
{
	*this = settings;
}

VideoSettings::VideoSettings()
{
	videoBufferLocation = VIDEO_MEMORY;
	machineArchitecture = SINGLE_CORE;
	bufferingMode = DOUBLE_BUFFER;
}

VideoSettings& 
VideoSettings::operator=(const VideoSettings& settings)
{
	videoBufferLocation = settings.videoBufferLocation;
	machineArchitecture = settings.machineArchitecture;
	bufferingMode = settings.bufferingMode;

	return *this;
}

bool 
VideoSettings::operator!=(const VideoSettings& settings)
{
	if (videoBufferLocation != settings.videoBufferLocation)
		return true;

	if (machineArchitecture != settings.machineArchitecture)
		return true;

	if (bufferingMode != settings.bufferingMode)
		return true;

	return false;
}

}

