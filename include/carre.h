#ifndef CARRE_H
#define CARRE_H

#include "shape.h"
#include "shader.h"
#include "texture.h"
#include <GL/glew.h>

class Carre : public Shape {
public:
    Carre(Shader *shader_program, Texture* texture, float hauteur, float largeur);
    void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection);
    void key_handler(int key);
    virtual ~Carre();

private:
    GLuint VAO;
    GLuint buffers[2];

    GLuint loc_diffuse_map;
    Texture* texture;
};

#endif