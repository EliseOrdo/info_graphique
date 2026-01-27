#ifndef LIGHT_CYLINDER_H
#define LIGHT_CYLINDER_H

#include <glm/glm.hpp>
#include "shader.h"
#include "cylinder.h"

class Lightcylinder : public Cylinder {
public:
    Lightcylinder(Shader *shader_program, glm::vec3 light_position, glm::vec3 light_color, glm::vec3 object_color,
    float height = 1.0f, float radius = 0.5f, int slices = 16);

    virtual void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection) override;

private:
    glm::vec3 light_position;
    glm::vec3 light_color;
    glm::vec3 object_color;

    // uniform locations
    GLint light_pos_loc;
    GLint light_color_loc;
    GLint object_color_loc;
};

#endif // LIGHT_CYLINDER_H