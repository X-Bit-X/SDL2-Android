#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <CustomLibrary/CustomSDL/C_Engine.h>
#include <CustomLibrary/CustomSDL/Renderer/C_Image.h>
#include <CustomLibrary/CustomSDL/Audio/C_Music.h>
#include <CustomLibrary/CustomSDL/Renderer/C_Text.h>

class Window1 : public ctl::Window
{
public:
	Window1()
		: Window("Test"),
		m_i(this),
		m_t(this)
	{
		m_i.loadFromFile("e.png");
		m_m.loadFromWAV("Tetris song.wav");
		m_t.font().loadFont("lazy.ttf", 50);

		m_m.play(-1);
		m_m.volume(128);
		m_t.loadBlended("Test 12345");
	}
	~Window1()
	{
		m_m.stop();
	}

	void event(const SDL_Event &e) override
	{

	}
	void render() override
	{
		m_i.texture().render({ 100, 100 });
		m_t.texture().render({ 100, 120 });
	}

private:
	ctl::Image m_i;
	ctl::Music m_m;
	ctl::Text m_t;
};

class Test : public ctl::SDL
{
public:
	Test()
		: SDL(30)
	{
	}

private:
	Window1 m_w1;

	void handleEvent(const SDL_Event &e) override
	{

	}
	void renderOrder() override
	{
		m_w1.pollRender();
	}
};

int main(int argc, char* args[])
{
	try
	{
		Test test;
		test.run();
	}
	catch (const std::exception &e) { SDL_Log(e.what()); }

	return 0;
}