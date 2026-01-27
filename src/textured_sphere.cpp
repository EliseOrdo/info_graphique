#include "textured_sphere.h"

TexturedSphere::TexturedSphere(Shader *shader_program, Texture *texture, float radius)
    : Sphere(shader_program, radius), texture(texture)
{
    loc_diffuse_map = glGetUniformLocation(this->shader_program_, "diffuse_map");
}

void TexturedSphere::draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection) {

    //glUseProgram(this->shader_program_);

    // TODO activate, bind the texture

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->texture->getGLid());
    glUniform1i(loc_diffuse_map, 0); // TODO send the correct texture to the shader

    glUseProgram(this->shader_program_);

    Sphere::draw(model, view, projection);

    // TODO Unbind the texture


    glUseProgram(0);
}
