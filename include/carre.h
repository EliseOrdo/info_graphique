#ifndef CARRE_H
#define CARRE_H

#include "shape.h"
#include "shader.h"
#include <GL/glew.h>

class Carre : public Shape {
public:
    Carre(Shader *shader_program);
    void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection);
    void key_handler(int key);
    virtual ~Carre();

private:
    GLuint VAO;
    GLuint buffers[2];
};

#endif