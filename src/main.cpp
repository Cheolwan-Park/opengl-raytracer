#include "Application.hpp"

int main(int argc, char** argv) {
	Application app("opengl raytracer", 960, 540);

	app.run();

	return 0;
}