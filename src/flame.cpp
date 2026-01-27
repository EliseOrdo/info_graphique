#include "flame.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

Flame::Flame(Shader* shader_program, float height, float width)
    : Shape(shader_program), height(height), width(width)
{
    // Get uniform location for time
    loc_time = glGetUniformLocation(this->shader_program_, "time");

    // Create a simple quad for the flame billboard
    std::vector<glm::vec3> vertices = {
        glm::vec3(-width, 0.0f, 0.0f),      // bottom left
        glm::vec3(width, 0.0f, 0.0f),       // bottom right
        glm::vec3(width, height, 0.0f),     // top right
        glm::vec3(-width, height, 0.0f)     // top left
    };

    // Texture coordinates
    std::vector<glm::vec2> texCoords = {
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f)
    };

    // Normals (all pointing forward for billboard)
    std::vector<glm::vec3> normals = {
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f)
    };

    // Indices for two triangles
    std::vector<unsigned int> indices = {
        0, 1, 2,
        2, 3, 0
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(3, &buffers[0]);

    // Vertex positions
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    // Texture coordinates
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(glm::vec2), texCoords.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

    // Index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    num_indices = static_cast<unsigned int>(indices.size());
}

Flame::~Flame() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(3, buffers);
}

void Flame::draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection)
{
    glUseProgram(this->shader_program_);

    // Enable blending for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glDepthMask(GL_FALSE);  // Don't write to depth buffer for transparent objects

    glBindVertexArray(VAO);

    // Pass time uniform for animation
    float time = static_cast<float>(glfwGetTime());
    glUniform1f(loc_time, time);

    Shape::draw(model, view, projection);

    glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, nullptr);

    // Restore default rendering state
    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);

    glUseProgram(0);
}
