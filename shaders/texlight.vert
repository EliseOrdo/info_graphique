//Applies both texture and light

#version 330 core

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
//uniform vec3 lightPos; // we now define the uniform in the vertex shader and pass the 'view space' lightpos to the fragment shader. lightPos is currently in world space.
//in vec3 position;

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 aNormal;

out vec3 FragPos;
out vec3 Normal;
out vec2 frag_tex_coords;

void main() {
    gl_Position = projection * view * model * vec4(position, 1);
    frag_tex_coords = position.xy;
    FragPos = vec3(model * vec4(position, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;
}

