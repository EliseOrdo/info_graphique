#include "viewer.h"
#include "textured_sphere.h"
#include "texture.h"
#include "cylinder.h"
#include "node.h"
#include "shader.h"
#include "cylinder.h"
#include "carre.h"
#include <string>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

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
    general_light.color = glm::vec3(0.5f, 0.5f, 0.5f);

    glm::vec3 candle_light = glm::vec3(0.03f, 0.02f, 0.0f);

    //Light candle
    Light yellox;
    yellox.pos = glm::vec3(1.0f, 1.0f, 0.0f);
    yellox.color = candle_light;

    Light yellox2;
    yellox2.pos = glm::vec3(sqrt(3)/2, 1.0f, 0.5f);
    yellox2.color = candle_light;

    Light yellox4;
    yellox4.pos = glm::vec3(0.5f, 1.0f, sqrt(3)/2);
    yellox4.color = candle_light;

    Light yellox5;
    yellox5.pos = glm::vec3(0.0f, 1.0f, 1.0f);
    yellox5.color = candle_light;

    Light yellox6;
    yellox6.pos = glm::vec3(-0.5f, 1.0f, sqrt(3)/2);
    yellox6.color = candle_light;

    Light yellox8;
    yellox8.pos = glm::vec3(-sqrt(3)/2, 1.0f, 0.5f);
    yellox8.color = candle_light;

    Light yellox9;
    yellox9.pos = glm::vec3(-1.0f, 1.0f, 0.0f);
    yellox9.color = candle_light;

    Light yellox10;
    yellox10.pos = glm::vec3(-0.5f, 1.0f, -sqrt(3)/2);
    yellox10.color = candle_light;

    Light yellox12;
    yellox12.pos = glm::vec3(-sqrt(3)/2, 1.0f, -0.5f);
    yellox12.color = candle_light;

    Light yellox13;
    yellox13.pos = glm::vec3(0.0f, 1.0f, -1.0f);
    yellox13.color = candle_light;

    Light yellox14;
    yellox14.pos = glm::vec3(sqrt(3)/2, 1.0f, -0.5f);
    yellox14.color = candle_light;

    Light yellox16;
    yellox16.pos = glm::vec3(0.5f, 1.0f, -sqrt(3)/2);
    yellox16.color = candle_light;




    std::vector<Light> light_list = {yellox, yellox2, yellox4, yellox5, yellox6, yellox8, yellox9,
         yellox10, yellox12, yellox13, yellox14, yellox16};

    //define textures
    Texture *texture = new Texture("C:/Users/Newteam-Consulting/Documents/infopasgraphique/info_graphique/textures/texture1.png");
        // chemin Elise : /Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture1.png
        // chemin Tiph : C:/Users/tipha/Documents/Projet_info_graphique/textures/texture1.png
        // chemin Lina : C:/Users/Newteam-Consulting/Documents/infopasgraphique/info_graphique/textures/texture1.png

    Texture *texture2 = new Texture("C:/Users/Newteam-Consulting/Documents/infopasgraphique/info_graphique/textures/texture2.jpg");
        //chemin Tiph : C:/Users/tipha/Documents/Projet_info_graphique/textures/texture2.jpg
        //chemin Lina : C:/Users/Newteam-Consulting/Documents/infopasgraphique/info_graphique/textures/texture2.jpg

    Texture *texture3 = new Texture("C:/Users/Newteam-Consulting/Documents/infopasgraphique/info_graphique/textures/texture3.png");

    Texture *texturecaillou = new Texture("C:/Users/Newteam-Consulting/Documents/infopasgraphique/info_graphique/textures/murcaillou.png");

    Texture *texturevitraille = new Texture("C:/Users/Newteam-Consulting/Documents/infopasgraphique/info_graphique/textures/vitraille.png");

    //add lights in the shader
    texlight_shader->use();
    texlight_shader->setInt("lightCount", light_list.size());
    for (int i = 0; i < light_list.size(); i++) {
        texlight_shader->setVec3("light_list[" + std::to_string(i) + "].pos", light_list[i].pos);
        texlight_shader->setVec3("light_list[" + std::to_string(i) + "].color", light_list[i].color);
    }

    Shape* sphere1 = new TexturedSphere(texlight_shader, texture);
    glm::mat4 sphere1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -4.0f));


    float candle_height = 0.0001;
    float candle_radius = 0.025;


    Shape* candle = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);

    glm::mat4 candle_mat = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node = new Node(candle_mat);
    candle_node-> add(candle);
    viewer.scene_root->add(candle_node);


    Shape* candle2 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);
    glm::mat4 candle_mat2 = glm::translate(glm::mat4(1.0f), glm::vec3(sqrt(3)/2, 0.0f, 0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node2 = new Node(candle_mat2);
    candle_node2-> add(candle2);
    viewer.scene_root->add(candle_node2);


    Shape* candle4 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);

    glm::mat4 candle_mat4 = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.0f, sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node4 = new Node(candle_mat4);
    candle_node4-> add(candle4);
    viewer.scene_root->add(candle_node4);


    Shape* candle5 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);

    glm::mat4 candle_mat5 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 1.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node5 = new Node(candle_mat5);
    candle_node5-> add(candle5);
    viewer.scene_root->add(candle_node5);


    Shape* candle6 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);
    glm::mat4 candle_mat6 = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node6 = new Node(candle_mat6);
    candle_node6-> add(candle6);
    viewer.scene_root->add(candle_node6);


    Shape* candle7 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);
    glm::mat4 candle_mat7 = glm::translate(glm::mat4(1.0f), glm::vec3(-sqrt(3)/2, 0.0f, 0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node7 = new Node(candle_mat7);
    candle_node7-> add(candle7);
    viewer.scene_root->add(candle_node7);


    Shape* candle9 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);

    glm::mat4 candle_mat9 = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node9 = new Node(candle_mat9);
    candle_node9-> add(candle9);
    viewer.scene_root->add(candle_node9);




    Shape* candle10 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);
    glm::mat4 candle_mat10 = glm::translate(glm::mat4(1.0f), glm::vec3(sqrt(3)/2, 0.0f, -0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node10 = new Node(candle_mat10);
    candle_node10-> add(candle10);
    viewer.scene_root->add(candle_node10);


    Shape* candle12 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);

    glm::mat4 candle_mat12 = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.0f, -sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node12 = new Node(candle_mat12);
    candle_node12-> add(candle12);
    viewer.scene_root->add(candle_node12);


    Shape* candle13 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);

    glm::mat4 candle_mat13 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node13 = new Node(candle_mat13);
    candle_node13-> add(candle13);
    viewer.scene_root->add(candle_node13);


    Shape* candle14 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);
    glm::mat4 candle_mat14 = glm::translate(glm::mat4(1.0f), glm::vec3(-sqrt(3)/2, 0.0f, -0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node14 = new Node(candle_mat14);
    candle_node14-> add(candle14);
    viewer.scene_root->add(candle_node14);



    Shape* candle16 = new Cylinder(texlight_shader, candle_color, 0.15f, 0.02);

    glm::mat4 candle_mat16 = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, -sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* candle_node16 = new Node(candle_mat16);
    candle_node16-> add(candle16);
    viewer.scene_root->add(candle_node16);



    Shape* carre1 = new Carre(texlight_shader,texturecaillou, 50.0, 50.0);
    glm::mat4 carre1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(-2.0f, -2.0f, 0.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* carre1_node = new Node(carre1_mat);

    carre1_node->add(carre1);
    viewer.scene_root->add(carre1_node);

    viewer.run();
}
