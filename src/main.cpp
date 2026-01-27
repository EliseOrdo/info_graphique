#include "viewer.h"
#include "textured_sphere.h"
#include "texture.h"
#include "cylinder.h"
#include "node.h"
#include "shader.h"
#include "cylinder.h"
#include "flame.h"
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

    Shader *reflechissant = new Shader(shader_dir + "phong.vert", shader_dir + "phong.frag");

    Shader *texlight_shader = new Shader(shader_dir + "texlight.vert", shader_dir + "texlight.frag");
    //glUseProgram(texlight_shader->get_id());

    Shader *flame_shader = new Shader(shader_dir + "flame.vert", shader_dir + "flame.frag");


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
    yellox.pos = glm::vec3(1.0f, 0.3f, 0.0f);
    yellox.color = candle_light;

    Light yellox2;
    yellox2.pos = glm::vec3(sqrt(3)/2, 0.3f, 0.5f);
    yellox2.color = candle_light;

    Light yellox4;
    yellox4.pos = glm::vec3(0.5f, 0.3f, sqrt(3)/2);
    yellox4.color = candle_light;

    Light yellox5;
    yellox5.pos = glm::vec3(0.0f, 0.3f, 1.0f);
    yellox5.color = candle_light;

    Light yellox6;
    yellox6.pos = glm::vec3(-0.5f, 0.3f, sqrt(3)/2);
    yellox6.color = candle_light;

    Light yellox8;
    yellox8.pos = glm::vec3(-sqrt(3)/2, 0.3f, 0.5f);
    yellox8.color = candle_light;

    Light yellox9;
    yellox9.pos = glm::vec3(-1.0f, 0.3f, 0.0f);
    yellox9.color = candle_light;

    Light yellox10;
    yellox10.pos = glm::vec3(-0.5f, 0.3f, -sqrt(3)/2);
    yellox10.color = candle_light;

    Light yellox12;
    yellox12.pos = glm::vec3(-sqrt(3)/2, 0.3f, -0.5f);
    yellox12.color = candle_light;

    Light yellox13;
    yellox13.pos = glm::vec3(0.0f, 0.3f, -1.0f);
    yellox13.color = candle_light;

    Light yellox14;
    yellox14.pos = glm::vec3(sqrt(3)/2, 0.3f, -0.5f);
    yellox14.color = candle_light;

    Light yellox16;
    yellox16.pos = glm::vec3(0.5f, 0.3f, -sqrt(3)/2);
    yellox16.color = candle_light;




    std::vector<Light> light_list = {yellox, yellox2, yellox4, yellox5, yellox6, yellox8, yellox9,
         yellox10, yellox12, yellox13, yellox14, yellox16};

    //define textures
    Texture *texture = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture1.png");
        // chemin Elise : /Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture1.png
        // chemin Tiph : C:/Users/tipha/Documents/Projet_info_graphique/textures/texture1.png

    Texture *texture2 = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture2.jpg");
        //chemin Tiph : C:/Users/tipha/Documents/Projet_info_graphique/textures/texture2.jpg
        //chemin Elise : "/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture2.jpg"

    Texture *candle_color = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/candle_color.png");


    //add lights in the shader
    texlight_shader->use();
    texlight_shader->setInt("lightCount", light_list.size());
    for (int i = 0; i < light_list.size(); i++) {
        texlight_shader->setVec3("light_list[" + std::to_string(i) + "].pos", light_list[i].pos);
        texlight_shader->setVec3("light_list[" + std::to_string(i) + "].color", light_list[i].color);
    }

/*     Shape* sphere1 = new TexturedSphere(texlight_shader, texture);
    glm::mat4 sphere1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -4.0f)); */




    Shape* flame1 = new Flame(flame_shader, 0.08f, 0.03f);  // hauteur 0.08, largeur 0.03
    glm::mat4 flame_mat1 = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.15f, 0.0f))  // Position au-dessus de la bougie
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node1 = new Node(flame_mat1);
    flame_node1->add(flame1);
    viewer.scene_root->add(flame_node1);


    Shape* flame2 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat2 = glm::translate(glm::mat4(1.0f), glm::vec3(sqrt(3)/2, 0.15f, 0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node2 = new Node(flame_mat2);
    flame_node2->add(flame2);
    viewer.scene_root->add(flame_node2);


    Shape* flame4 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat4 = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.15f, sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node4 = new Node(flame_mat4);
    flame_node4->add(flame4);
    viewer.scene_root->add(flame_node4);


    Shape* flame5 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat5 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.15f, 1.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node5 = new Node(flame_mat5);
    flame_node5->add(flame5);
    viewer.scene_root->add(flame_node5);


    Shape* flame6 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat6 = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.15f, 0.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node6 = new Node(flame_mat6);
    flame_node6->add(flame6);
    viewer.scene_root->add(flame_node6);


    Shape* flame7 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat7 = glm::translate(glm::mat4(1.0f), glm::vec3(-sqrt(3)/2, 0.15f, 0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node7 = new Node(flame_mat7);
    flame_node7->add(flame7);
    viewer.scene_root->add(flame_node7);


    Shape* flame9 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat9 = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.15f, sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node9 = new Node(flame_mat9);
    flame_node9->add(flame9);
    viewer.scene_root->add(flame_node9);


    Shape* flame10 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat10 = glm::translate(glm::mat4(1.0f), glm::vec3(sqrt(3)/2, 0.15f, -0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node10 = new Node(flame_mat10);
    flame_node10->add(flame10);
    viewer.scene_root->add(flame_node10);


    Shape* flame12 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat12 = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.15f, -sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node12 = new Node(flame_mat12);
    flame_node12->add(flame12);
    viewer.scene_root->add(flame_node12);


    Shape* flame13 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat13 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.15f, -1.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node13 = new Node(flame_mat13);
    flame_node13->add(flame13);
    viewer.scene_root->add(flame_node13);


    Shape* flame14 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat14 = glm::translate(glm::mat4(1.0f), glm::vec3(-sqrt(3)/2, 0.15f, -0.5f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node14 = new Node(flame_mat14);
    flame_node14->add(flame14);
    viewer.scene_root->add(flame_node14); 
        
        
    Shape* flame16 = new Flame(flame_shader, 0.08f, 0.03f);
    glm::mat4 flame_mat16 = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.15f, -sqrt(3)/2))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Node* flame_node16 = new Node(flame_mat16);
    flame_node16->add(flame16);
    viewer.scene_root->add(flame_node16);


    float candle_height = 0.25;
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



    viewer.run();
}
