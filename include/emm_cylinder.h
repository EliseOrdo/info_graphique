#pragma once

#include "shape.h"
#include "texture.h"
#include <vector>

class Emm_cylinder : public Shape {
public:
    Emm_cylinder(Shader *shader_program,Texture* texture, glm::vec3 emissiveColor, float height = 1.0f, float radius = 0.5f, int slices = 16);
    void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection);

    glm::vec3 getEmissiveColor() const;

private:
    unsigned int num_indices;
    GLuint VAO;
    GLuint buffers[2];
    
    //glm::vec3 object_color;

    //GLint object_color_loc;

    GLuint loc_diffuse_map;
    GLint loc_emissive_color;
    Texture* texture;
    glm::vec3 emissiveColor_;
};
