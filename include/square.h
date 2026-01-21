#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
#include "shader.h"
#include <GL/glew.h>

class Square : public Shape {
public:
    Square(Shader *shader_program, float longueur, float largeur);
    void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection);
    void key_handler(int key);
    virtual ~Square();

private:
    GLuint VAO;
    GLuint buffers[2];
};

#endif