#include "cube.h"

#include <glm/glm.hpp>
#include "glm/ext.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Cube::Cube(Shader *shader_program, Texture* texture, float hauteur, float largeur, float profondeur) : Shape(shader_program) , texture(texture)
{

    loc_diffuse_map = glGetUniformLocation(this->shader_program_, "diffuse_map");
    GLfloat vertex_buffer_data[] = {
        0.5f*largeur, 0.5f*hauteur, 0.5f*profondeur,
        0.5f*largeur, -0.5f*hauteur, 0.5f*profondeur,
        -0.5f*largeur, -0.5f*hauteur, 0.5f*profondeur,
        -0.5*largeur, 0.5*hauteur, 0.5f*profondeur,
        0.5f*largeur, 0.5f*hauteur, -0.5f*profondeur,
        0.5f*largeur, -0.5f*hauteur, -0.5f*profondeur,
        -0.5f*largeur, -0.5f*hauteur, -0.5f*profondeur,
        -0.5*largeur, 0.5*hauteur, -0.5f*profondeur
    };

    
    GLint indices[] = {
        0, 1, 2,
        0, 2, 3,
        4, 5, 6,
        4, 6, 7,
        0, 5, 4,
        0, 1, 5,
        1, 7, 5,
        1, 7, 3,
        7, 2, 6,
        7, 2, 6,
        6, 0, 2,
        6, 0, 4
    };
    GLfloat normals[] = {
        0,0,1
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(3, &buffers[0]);

    

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    // normal
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ARRAY_BUFFER, 1 * sizeof(glm::vec3), normals, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    // Index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


}

void Cube::draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection)
{   
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->texture->getGLid());
    glUniform1i(loc_diffuse_map, 0);
    glUseProgram(this->shader_program_);

    glBindVertexArray(VAO);
    
    Shape::draw(model, view, projection);

    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
    glUseProgram(0);
}

Cube::~Cube() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &buffers[0]);
}

void Cube::key_handler(int key) {
    return;
}
