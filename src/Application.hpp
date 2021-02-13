#pragma once

#include <SDL.h>
#include <GL/glew.h>
#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_sdl.h>
#include <string>
#include <chrono>
#include <memory>
#include "Shader.hpp"

class Application {
private:
	typedef std::chrono::duration<uint32_t, std::milli> milliseconds;
	typedef std::chrono::system_clock::time_point time_point;
	static constexpr milliseconds IDEAL_DELTATIME = milliseconds(16);

public:
	Application() = delete;
	explicit Application(const std::string& title, int width, int height);

	~Application();

	void run();

	[[nodiscard]] float deltatime() const;

	[[nodiscard]] float now() const;

private:
	bool init(const std::string& title, int width, int height);

	void free();

	void render() const;

	void render_gui();

private:
	SDL_Window* _window;
	SDL_GLContext _context;

	struct {
		time_point begin;
		time_point now;
		time_point start;
		milliseconds deltatime = milliseconds(0);
	} _time;
};
