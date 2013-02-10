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
#include "windowfactory.h"
#include "canvas.h"
#include "exception.h"
#include "image.h"

using namespace std;
using namespace edge;

void video_test() {
    string message;

    Video *video = NULL;

    try {
        video = Video::getInstance();
    } catch (Exception& e) {
        message = "Sem memoria para a alocacao do video (" + e.getMessage() +
                ")";
        BOOST_FAIL(message.c_str());
    }

    Video *instance = Video::getInstance();

    if (video != instance) {
        message = "O video nao e um singleton";
        BOOST_FAIL(message.c_str());
    }

    if (video->isUp() == true) {
        message = "Estado inicial do video invalido";
        BOOST_ERROR(message.c_str());
    }

    try {
        video->init();
    } catch (Exception& e) {
        message = "Erro na inicializacao do video (" + e.getMessage() + ")";
        BOOST_FAIL(message.c_str());
    }

    if (video->isUp() == false) {
        message = "Estado invalido apos inicializacao do video";
        BOOST_ERROR(message.c_str());
    }

    try {
        video->init();
    } catch (Exception& e) {
        message = "Erro na inicializacao dupla do video (" + e.getMessage()
                + ")";
        BOOST_ERROR(message.c_str());
    }

    VideoSettings customSettings;

    customSettings.machineArchitecture = MULTI_CORE;

    try {
        video->changeSettings(customSettings);
    } catch (Exception& e) {
        message = "Erro na mudanca de configuracoes (" + e.getMessage() + ")";
        BOOST_ERROR(message.c_str());
    }

    VideoSettings currentSettings = video->currentSettings();

    if (currentSettings != customSettings) {
        message = "As configuracoes nao foram alteradas corretamente";
        BOOST_ERROR(message.c_str());
    }

    try {
        video->shutdown();
    } catch (Exception& e) {
        message = "Erro no encerramento do video (" + e.getMessage() + ")";
        BOOST_ERROR(message.c_str());
    }

    if (video->isUp() == true) {
        message = "Estado invalido apos encerramento do video";
        BOOST_ERROR(message.c_str());
    }

    try {
        video->shutdown();
    } catch (Exception& e) {
        message = "Erro no encerramento duplo do video (" + e.getMessage()
                + ")";
        BOOST_ERROR(message.c_str());
    }
}

void window_test(WindowSettings& windowSettings, const string& settings) {
    string message;

    Video *video = Video::getInstance();
    video->init();

    Window *window = NULL;

    try {
        window = WindowFactory::create(windowSettings);
    } catch (Exception& e) {
        message = "Estado invalido antes da inicializacao com configuracao "
                + settings + " da janela: (" + e.getMessage() + ")";
        BOOST_FAIL(message.c_str());
    }

    WindowSettings currentSettings = window->currentSettings();

    if (currentSettings != windowSettings
            || window->getWidth() != windowSettings.width
            || window->getHeight() != windowSettings.height) {
        message = "As configuracoes nao foram aplicadas corretamente";
        BOOST_ERROR(message.c_str());
    }

    video->shutdown();
}

void canvas_test() {
    Video *video = Video::getInstance();
    video->init();

    WindowSettings settings;
    settings.presentationMode = WINDOW;

    Window *window = WindowFactory::create(settings);

    Canvas *canvas = NULL;

    try {
        canvas = window->getCanvas();
    } catch (Exception& e) {
        video->shutdown();
        BOOST_FAIL("Nao foi possivel obter o canvas");
    }

    srand(time(NULL));

    Point position;
    Color color;

    for (int i = 0; i < 1000; i++) {
        position.x = rand() % canvas->width();
        position.y = rand() % canvas->height();

        color.red = rand() % 255;
        color.green = rand() % 255;
        color.blue = rand() % 255;

        canvas->drawPixel(position, color);
        canvas->update();
    }

    char answer;

    cout << "Os pixels foram desenhados? (s/n): ";
    cin >> answer;

    if (answer != 's') {
        BOOST_FAIL("Nao foi possivel desenhar os pixels");
    }

    Color black;
    canvas->erase(black);


    Line line;

    for (int i = 0; i < 1000; i++) {
        line.begin.x = rand() % canvas->width();
        line.begin.y = rand() % canvas->height();

        line.end.x = rand() % canvas->width();
        line.end.y = rand() % canvas->height();

        color.red = rand() % 255;
        color.green = rand() % 255;
        color.blue = rand() % 255;

        canvas->drawLine(line, color);
        canvas->update();
    }

    cout << "As retas foram desenhadas? (s/n): ";
    cin >> answer;

    if (answer != 's') {
        BOOST_FAIL("Nao foi possivel desenhar as retas");
    }

    canvas->erase(black);

    Rectangle rect;

    for (int i = 0; i < 1000; i++) {
        position.x = rand() % canvas->width();
        position.y = rand() % canvas->height();

        rect.width = rand() % canvas->width();
        rect.height = rand() % canvas->height();

        color.red = rand() % 255;
        color.green = rand() % 255;
        color.blue = rand() % 255;

        canvas->drawRectangle(rect, position, color);
        canvas->update();
    }

    cout << "Os retangulos foram desenhados? (s/n): ";
    cin >> answer;

    if (answer != 's') {
        BOOST_FAIL("Nao foi possivel desenhar os retangulos");
    }

    canvas->erase(black);

    for (int i = 0; i < 1000; i++) {
        position.x = rand() % canvas->width();
        position.y = rand() % canvas->height();

        rect.width = rand() % canvas->width();
        rect.height = rand() % canvas->height();

        color.red = rand() % 255;
        color.green = rand() % 255;
        color.blue = rand() % 255;

        canvas->fillRectangle(rect, position, color);
        canvas->update();
    }

    cout << "Os retangulos foram preenchidos? (s/n): ";
    cin >> answer;

    if (answer != 's') {
        BOOST_FAIL("Nao foi possivel preencher os retangulos");
    }

    canvas->erase(black);

    Circle circle;

    for (int i = 0; i < 1000; i++) {
        position.x = rand() % canvas->width();
        position.y = rand() % canvas->height();

        circle.radius = rand() % (canvas->height() / 2);

        color.red = rand() % 255;
        color.green = rand() % 255;
        color.blue = rand() % 255;

        canvas->drawCircle(circle, position, color);
        canvas->update();
    }

    cout << "Os circulos foram desenhados? (s/n): ";
    cin >> answer;

    if (answer != 's') {
        BOOST_FAIL("Nao foi possivel desenhar os circulos");
    }

    canvas->erase(black);

    for (int i = 0; i < 1000; i++) {
        position.x = rand() % canvas->width();
        position.y = rand() % canvas->height();

        circle.radius = rand() % (canvas->height() / 2);

        color.red = rand() % 255;
        color.green = rand() % 255;
        color.blue = rand() % 255;

        canvas->fillCircle(circle, position, color);
        canvas->update();
    }

    cout << "Os circulos foram preenchidos? (s/n): ";
    cin >> answer;

    if (answer != 's') {
        BOOST_FAIL("Nao foi possivel preencher os circulos");
    }

    canvas->erase(black);

    video->shutdown();
}

void image_test()
{
    Video *video = Video::getInstance();
    video->init();
    
    WindowSettings settings;
    settings.presentationMode = WINDOW;

    Window *window = WindowFactory::create(settings);

    Canvas *canvas = window->getCanvas();

    Image *image = NULL;
    
    bool exceptionRaised = false;
    
    try {
        image = Image::load("notfound.bmp");
    } catch (Exception& e) {
        exceptionRaised = true;
        
        if (e.getMessage() != "Image not found")
        {
            BOOST_ERROR("Erro no carregamento de uma imagem inexistente");
        }
    }
    
    if (exceptionRaised != true)
    {
        BOOST_ERROR("Carregamento de imagem nao existente nao lancou excecao");
    }
    
    exceptionRaised = false;
    
    try {
        image = Image::load("invalid.bmp");
    } catch (Exception& e) {
        exceptionRaised = true;
        
        if (e.getMessage() != "Invalid image")
        {
            BOOST_ERROR("Erro no carregamento de uma imagem invalida");
        }
    }
    
    if (exceptionRaised != true)
    {
        BOOST_ERROR("Carregamento de imagem invalida nao lancou excecao");
    }
    
    try {
        image = Image::load("x.png");
    } catch (Exception& e) {
        BOOST_FAIL("Erro no carregamento de uma imagem valida");
    }
    
    if (image->width() != 180 || image->height() != 180) {
        BOOST_FAIL("Dimensao invalida");
    }
    
    Point position;
    
    for (int i = 0; i < 1000; i++) {
        position.x = rand() % canvas->width();
        position.y = rand() % canvas->height();
        
        canvas->drawImage(image, position);
        canvas->update();
    }

    char answer;
    cout << "As imagens foram desenhados? (s/n): ";
    cin >> answer;

    if (answer != 's') {
        BOOST_FAIL("Nao foi possivel desenhar as imagens");
    }

    Image::release(image);
    
    Color black;
    canvas->erase(black);
    video->shutdown();
    
}

int test_main(int, char *[]) {
    /*video_test();

    WindowSettings defaultWindowSettings;
    window_test(defaultWindowSettings, "padrao");

    WindowSettings customWindowSettings;
    customWindowSettings.presentationMode = WINDOW;
    customWindowSettings.windowSize = RESIZABLE;

    window_test(customWindowSettings, "customizada");
*/
    canvas_test();
     
    image_test();
    
    return 0;
}

