#include "viewer.h"
#include "textured_sphere.h"
#include "texture.h"
#include "node.h"
#include "shader.h"
#include "cylinder.h"
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
        glm::vec3 color; //pour r�gler l'intensit� de la lumi�re, r�gler la "quantit� de couleur"
    };

    //Define all lights (do not forget to add them in the light_list below !)
    Light general_light;
    general_light.pos = glm::vec3(-15.0f, 0.0f, -4.0f);
    general_light.color = glm::vec3(0.5f, 0.0f, 0.0f);
    Light yellox;
    yellox.pos = glm::vec3(5.0f, 0.0f, -4.0f);
    yellox.color = glm::vec3(0.0f, 1.0f, 0.0f);


    std::vector<Light> light_list = {general_light,yellox};

    Texture *texture = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture1.png");
        // chemin Elise : /Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture1.png
        // chemin Tiph : C:/Users/tipha/Documents/Projet_info_graphique/textures/texture1.png

    texlight_shader->use();
    texlight_shader->setInt("lightCount", light_list.size());
    for (int i = 0; i < light_list.size(); i++) {
        texlight_shader->setVec3("light_list[" + std::to_string(i) + "].pos", light_list[i].pos);
        texlight_shader->setVec3("light_list[" + std::to_string(i) + "].color", light_list[i].color);
    }

    Shape* sphere1 = new TexturedSphere(texlight_shader, texture);
    glm::mat4 sphere1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -4.0f));


    float candle_height = 0.25;
    float candle_radius = 0.025;


    Shape* candle = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);
    glm::mat4 candle_mat = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node = new Node(candle_mat);
    candle_node-> add(candle);
    viewer.scene_root->add(candle_node);


    Shape* candle2 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);
    glm::mat4 candle_mat2 = glm::translate(glm::mat4(1.0f), glm::vec3(sqrt(3)/2, 0.0f, 0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node2 = new Node(candle_mat2);
    candle_node2-> add(candle2);
    viewer.scene_root->add(candle_node2);


    Shape* candle3 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);

    glm::mat4 candle_mat3 = glm::translate(glm::mat4(1.0f), glm::vec3(sqrt(2)/2, 0.0f, sqrt(2)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node3 = new Node(candle_mat3);
    candle_node3-> add(candle3);
    viewer.scene_root->add(candle_node3);


    Shape* candle4 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);

    glm::mat4 candle_mat4 = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.0f, sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node4 = new Node(candle_mat4);
    candle_node4-> add(candle4);
    viewer.scene_root->add(candle_node4);


    Shape* candle5 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);

    glm::mat4 candle_mat5 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 1.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node5 = new Node(candle_mat5);
    candle_node5-> add(candle5);
    viewer.scene_root->add(candle_node5);


    Shape* candle6 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);
    glm::mat4 candle_mat6 = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node6 = new Node(candle_mat6);
    candle_node6-> add(candle6);
    viewer.scene_root->add(candle_node6);


    Shape* candle7 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);
    glm::mat4 candle_mat7 = glm::translate(glm::mat4(1.0f), glm::vec3(-sqrt(3)/2, 0.0f, 0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node7 = new Node(candle_mat7);
    candle_node7-> add(candle7);
    viewer.scene_root->add(candle_node7);


    Shape* candle8 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);

    glm::mat4 candle_mat8 = glm::translate(glm::mat4(1.0f), glm::vec3(-sqrt(2)/2, 0.0f, sqrt(2)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node8 = new Node(candle_mat8);
    candle_node3-> add(candle8);
    viewer.scene_root->add(candle_node8);


    Shape* candle9 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);

    glm::mat4 candle_mat9 = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node9 = new Node(candle_mat9);
    candle_node9-> add(candle9);
    viewer.scene_root->add(candle_node9);




    Shape* candle10 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);
    glm::mat4 candle_mat10 = glm::translate(glm::mat4(1.0f), glm::vec3(sqrt(3)/2, 0.0f, -0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node10 = new Node(candle_mat10);
    candle_node10-> add(candle10);
    viewer.scene_root->add(candle_node10);


    Shape* candle11 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);

    glm::mat4 candle_mat11 = glm::translate(glm::mat4(1.0f), glm::vec3(sqrt(2)/2, 0.0f, -sqrt(2)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node11 = new Node(candle_mat11);
    candle_node11-> add(candle11);
    viewer.scene_root->add(candle_node11);


    Shape* candle12 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);

    glm::mat4 candle_mat12 = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.0f, -sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node12 = new Node(candle_mat12);
    candle_node12-> add(candle12);
    viewer.scene_root->add(candle_node12);


    Shape* candle13 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);

    glm::mat4 candle_mat13 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node13 = new Node(candle_mat13);
    candle_node13-> add(candle13);
    viewer.scene_root->add(candle_node13);


    Shape* candle14 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);
    glm::mat4 candle_mat14 = glm::translate(glm::mat4(1.0f), glm::vec3(-sqrt(3)/2, 0.0f, -0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node14 = new Node(candle_mat14);
    candle_node14-> add(candle14);
    viewer.scene_root->add(candle_node14);


    Shape* candle15 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);

    glm::mat4 candle_mat15 = glm::translate(glm::mat4(1.0f), glm::vec3(-sqrt(2)/2, 0.0f, -sqrt(2)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node15 = new Node(candle_mat15);
    candle_node15-> add(candle15);
    viewer.scene_root->add(candle_node15);


    Shape* candle16 = new Cylinder(texlight_shader, glm::vec3(0.2, 0.6, 0), 0.15f, 0.02);

    glm::mat4 candle_mat16 = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, -sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node16 = new Node(candle_mat16);
    candle_node16-> add(candle16);
    viewer.scene_root->add(candle_node16);



    viewer.run();
}
