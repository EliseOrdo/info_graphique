#ifndef FLAME_H
#define FLAME_H

#include "shape.h"
#include "shader.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

class Flame : public Shape {
public:
    Flame(Shader* shader_program, float height = 0.15f, float width = 0.05f);
    ~Flame();

    void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection) override;

private:
    GLuint VAO;
    GLuint buffers[3];
    unsigned int num_indices;
    GLint loc_time;
    float height;
    float width;
};

#endif
