#pragma once

#include "shape.h"
#include "texture.h"
#include <vector>

class Cylinder : public Shape {
public:
    Cylinder(Shader *shader_program,Texture* texture, float height = 1.0f, float radius = 0.5f, int slices = 16);
    void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection);

private:
    unsigned int num_indices;
    GLuint VAO;
    GLuint buffers[2];
    
    //glm::vec3 object_color;

    //GLint object_color_loc;

    GLuint loc_diffuse_map;
    Texture* texture;
};
