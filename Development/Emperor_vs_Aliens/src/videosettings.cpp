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
operator<<(ostream& os, ColorDepth colorDepth)
{
	switch (colorDepth)
	{
		case SYSTEM:
			os << "Same as OS";
			break;

		case INDEXED: 
			os << "Indexed";
			break;

		case HICOLOR: 
			os << "Hicolor";
			break;

		case TRUE_COLOR: 
			os << "True color";
			break;

		case RGBA:
			os << "32-bit";
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
operator<<(ostream& os, RenderingMode renderingMode)
{
	switch (renderingMode)
	{
		case BIDIMENSIONAL: 
			os << "2D";
			break;
		case TRIDIMENSIONAL: 
			os << "3D";
			break;

		case MIXED: 
			os << "Mixed 2D and 3D";
			break;
	}

	return os;
}

ostream& 
operator<<(ostream& os, const VideoSettings settings)
{
	os << "Video buffer location: " << settings.videoBufferLocation << endl;
	os << "Machine architecture: " << settings.machineArchitecture << endl;
	os << "Color depth: " << settings.colorDepth << endl;
	os << "Buffering mode: " << settings.bufferingMode << endl;
	os << "Rendering mode: " << settings.renderingMode << endl;

	return os;	
}
	
VideoSettings::VideoSettings(VideoBufferLocation videoBufferLocation, 
		MachineArchitecture machineArchitecture, ColorDepth colorDepth,
		BufferingMode bufferingMode, RenderingMode renderingMode)
{
	this->videoBufferLocation = videoBufferLocation;
	this->machineArchitecture = machineArchitecture;
	this->colorDepth = colorDepth;
	this->bufferingMode = bufferingMode;
	this->renderingMode = renderingMode;
}

}

