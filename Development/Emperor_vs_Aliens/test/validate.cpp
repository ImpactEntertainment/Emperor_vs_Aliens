/**
 * \file validate.cpp
 * \brief Módulo para teste dos componente.
 *
 * Módulo para teste dos componentes. Utiliza a mais simples das opções
 * do módulo de testes da biblioteca Boost. Testa as classes Video e 
 * Window.
 * 
 * \author Edson Alves (edsonalves@unb.br)
 * \date 31/12/2012
 */
#include <string>
#include <boost/test/minimal.hpp>

#include "video.h"
#include "window.h"

using namespace std;
using namespace edge;

void video_test(Video& video, const string& settings)
{
	string message;

	if (video.isUp() == true)
	{
		message = "Estado inicial do video invalido para a configuracao " 
			+ settings + " do video";
		BOOST_ERROR(message.c_str());
	}

	try 
	{
		video.init();
	} catch (Exception& e)
	{
		message = "Erro na inicializacao da configuracao " + settings + 
			" do video";
		BOOST_FAIL(message.c_str());
	}

	if (video.isUp() == false)
	{
		message = "Estado invalido apos inicializacao com a configuracao "
			+ settings + " do video";
		BOOST_ERROR(message.c_str());
	}

	try
	{
		video.init();
	} catch (Exception& e)
	{
		message = "Erro na inicializacao dupla da configuracao " + settings
			+ " do video";
		BOOST_ERROR(message.c_str());
	}
	
	try
	{
		video.shutdown();
	} catch (Exception& e)
	{
		message = "Erro no encerramento do video com a configuracao " 
			+ settings + " do video";
		BOOST_ERROR(message.c_str());
	}
	
	if (video.isUp() == true)
	{
		message = "Estado invalido apos encerramento com a configuracao " 
			+ settings + " do video";
		BOOST_ERROR(message.c_str());
	}
	
	try
	{
		video.shutdown();
	} catch (Exception& e)
	{
		message = "Erro no encerramento duplo do video com a configuracao " 
			+ settings + " do video";
		BOOST_ERROR(message.c_str());
	}
}	

void window_test(Window& window, const string& settings)
{
	string message;

	if (window.isVisible() == true)
	{
		message = "Estado invalido antes da inicializacao com configuracao "
			+ settings + " da janela";
		BOOST_ERROR(message.c_str());
	}

	try 
	{
		window.show();
	} catch (Exception& e)
	{
		message = "Erro na exibicao da configuracao " + settings + 
			" da janela";
		BOOST_FAIL(message.c_str());
	}

	if (window.isVisible() != true)
	{
		message = "Estado invalido apos inicializacao com a configuracao "
			+ settings + " da janela";
		BOOST_ERROR(message.c_str());
	}

	try
	{
		window.show();
	} catch (Exception& e)
	{
		message = "Erro na exibicao dupla da configuracao " + settings
			+ " da janela";
		BOOST_ERROR(message.c_str());
	}
}

int test_main( int, char *[] ) 
{
	Video videoWithDefaultSettings;
	video_test(videoWithDefaultSettings, "padrao");

	VideoSettings customSettings(SYSTEM_MEMORY, MULTI_CORE, RGBA, 
		SINGLE_BUFFER, TRIDIMENSIONAL);
	Video videoWithCustomSettings(customSettings);
	video_test(videoWithCustomSettings, "customizada");

	Window windowWithDefaultSettings(&videoWithDefaultSettings);
	window_test(windowWithDefaultSettings, "padrao, video padrao");

	Window windowWithDefaultSettingsAndCustomVideo(&videoWithCustomSettings);
	window_test(windowWithDefaultSettingsAndCustomVideo, 
		"customizada, video customizado");

	Window windowWithCustomSettings(&videoWithDefaultSettings);
	window_test(windowWithCustomSettings, "padrao, video padrao");

	Window windowWithCustomSettingsAndCustomVideo(&videoWithCustomSettings);
	window_test(windowWithCustomSettingsAndCustomVideo, 
		"customizada, video customizado");

	return 0;
}

