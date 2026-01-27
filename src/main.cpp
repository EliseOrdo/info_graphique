#include "viewer.h"
#include "textured_sphere.h"
#include "lighting_sphere.h"
#include "texture.h"
#include "node.h"
#include "shader.h"
#include <string>

#ifndef SHADER_DIR
#error "SHADER_DIR not defined"
#endif

int main()
{
    // create window, add shaders & scene objects, then run rendering loop
    Viewer viewer;

    // get shader directory
    std::string shader_dir = SHADER_DIR;

    //Shader *texture_shader = new Shader(shader_dir + "texture.vert", shader_dir + "texture.frag");

    Shader *texlight_shader = new Shader(shader_dir + "texlight.vert", shader_dir + "texlight.frag");
    //glUseProgram(texlight_shader->get_id());

    //light
    struct Light {
        glm::vec3 pos;
        glm::vec3 color; //pour régler l'intensité de la lumière, régler la "quantité de couleur"
    };

    //Define all lights (do not forget to add them in the light_list below !)
    Light general_light;
    general_light.pos = glm::vec3(-15.0f, 0.0f, -4.0f);
    general_light.color = glm::vec3(0.5f, 0.0f, 0.0f);
    Light yellox;
    yellox.pos = glm::vec3(15.0f, 0.0f, -4.0f);
    yellox.color = glm::vec3(0.0f, 0.5f, 0.0f);


    std::vector<Light> light_list = {general_light,yellox};

    Texture *texture = new Texture("C:/Users/tipha/Documents/Projet_info_graphique/textures/texture1.png");
        // chemin Elise : /Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture1.png
        // chemin Tiph : C:/Users/tipha/Documents/Projet_info_graphique/textures/texture1.png

    texlight_shader->use();
    texlight_shader->setInt("lightCount", light_list.size());
    for (int i = 0; i < light_list.size(); i++) {
        texlight_shader->setVec3("light_list[" + std::to_string(i) + "].pos", light_list[i].pos);
        texlight_shader->setVec3("light_list[" + std::to_string(i) + "].color", light_list[i].color);
    }

    Shape* sphere1 = new TexturedSphere(texlight_shader, texture);
    glm::mat4 sphere1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -4.0f))
        * glm::scale(glm::mat4(10.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* sphere1_node = new Node(sphere1_mat);

    sphere1_node->add(sphere1);

    viewer.scene_root->add(sphere1_node);

    //Shader *phong_shader = new Shader(shader_dir + "phong.vert", shader_dir + "phong.frag");

    /*Shape* sphere2 = new LightingSphere(texlight_shader, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.01f, 0.0f, 0.01f), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 sphere2_mat = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, -4.0f))
        * glm::scale(glm::mat4(10.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* sphere2_node = new Node(sphere2_mat);

    sphere2_node->add(sphere2);

    viewer.scene_root->add(sphere2_node);*/

    viewer.run();
}
