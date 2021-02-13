#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include "Texture.hpp"

using std::string;

class Shader {
public:
	static void use_null();

private:
	static GLuint _current_program;

private:
	GLuint _program;

public:
	Shader();

	explicit Shader(const string& vert_file, const string& frag_file);

	~Shader();

	bool load(const string& vert_file, const string& frag_file);

	void use() const;

	void setUniform(const string& name, const glm::mat4x4& mat) const;

	void setUniform(const string& name, const glm::vec3& vec) const;

	void setUniform(const string& name, float v) const;

	void setTexture(const string& name, GLenum target, const Texture& texture);
};