#ifndef CUBE_H
#define CUBE_H

#include "shape.h"
#include "shader.h"
#include "texture.h"
#include <GL/glew.h>

class Cube : public Shape {
public:
    Cube(Shader *shader_program, Texture* texture, float hauteur=1., float largeur=1., float profondeur=1.);
    void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection);
    void key_handler(int key);
    virtual ~Cube();

private:
    GLuint VAO;
    GLuint buffers[2];

    GLuint loc_diffuse_map;
    Texture* texture;
};

#endif