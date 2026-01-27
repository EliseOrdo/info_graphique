#include "carre.h"

Carre::Carre(Shader *shader_program) : Shape(shader_program) {

    GLfloat vertex_buffer_data1[] = {
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
    };

    glGenVertexArrays(1, &VAO1);
    glBindVertexArray(VAO1);

    glGenBuffers(1, &VBO1);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data1), vertex_buffer_data1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);    
    
    GLfloat vertex_buffer_data2[] = {
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
    };

    glGenVertexArrays(1, &VAO2);
    glBindVertexArray(VAO2);

    glGenBuffers(1, &VBO2);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data2), vertex_buffer_data2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);   
}

Carre::~Carre() {
    glDeleteVertexArrays(1, &VAO1);
    glDeleteBuffers(1, &VBO1);
    glDeleteVertexArrays(1, &VAO2);
    glDeleteBuffers(1, &VBO2);
}

void Carre::draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection) {

    glUseProgram(this->shader_program_);

    glBindVertexArray( VAO1 );
    glBindVertexArray( VAO2 );

    Shape::draw(model, view, projection);

    /* draw points 0-3 from the currently bound VAO with current in-use shader */
    glDrawArrays( GL_TRIANGLES, 0, 3 );
}

void Carre::key_handler(int key) {
    return;
}