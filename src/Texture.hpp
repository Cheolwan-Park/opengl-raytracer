#pragma once

#include <GL/glew.h>
#include <string>
#include "common/common.hpp"
#include "SOIL2/SOIL2.h"

using std::string;

class Texture {
public:
	static void bind_null(GLenum target);

private:
	constexpr static unsigned int default_flags =
		SOIL_FLAG_POWER_OF_TWO |
		SOIL_FLAG_MIPMAPS |
		SOIL_FLAG_DDS_LOAD_DIRECT |
		SOIL_FLAG_PVR_LOAD_DIRECT |
		SOIL_FLAG_ETC1_LOAD_DIRECT |
		SOIL_FLAG_COMPRESS_TO_DXT;

private:
	GLuint _id;

public:
	Texture();

	explicit Texture(const string& filename);

	~Texture();

	bool load(const string& filename, unsigned int flags = default_flags);

	void bind(GLenum target) const;
};