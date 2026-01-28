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

    glm::vec3 candle_light = glm::vec3(0.3f, 0.2f, 0.0f);

    //Light candle
    Light yellox;
    yellox.pos = glm::vec3(1.0f, -0.2f, 0.0f);
    yellox.color = candle_light;

    Light yellox2;
    yellox2.pos = glm::vec3(sqrt(3)/2, -0.2f, 0.5f);
    yellox2.color = candle_light;

    Light yellox4;
    yellox4.pos = glm::vec3(0.5f, -0.2f, sqrt(3)/2);
    yellox4.color = candle_light;

    Light yellox5;
    yellox5.pos = glm::vec3(0.0f, -0.2f, 1.0f);
    yellox5.color = candle_light;

    Light yellox6;
    yellox6.pos = glm::vec3(-0.5f, -0.2f, sqrt(3)/2);
    yellox6.color = candle_light;

    Light yellox8;
    yellox8.pos = glm::vec3(-sqrt(3)/2, -0.2f, 0.5f);
    yellox8.color = candle_light;

    Light yellox9;
    yellox9.pos = glm::vec3(-1.0f, -0.2f, 0.0f);
    yellox9.color = candle_light;

    Light yellox10;
    yellox10.pos = glm::vec3(-0.5f, -0.2f, -sqrt(3)/2);
    yellox10.color = candle_light;

    Light yellox12;
    yellox12.pos = glm::vec3(-sqrt(3)/2, -0.2f, -0.5f);
    yellox12.color = candle_light;

    Light yellox13;
    yellox13.pos = glm::vec3(0.0f, -0.2f, -1.0f);
    yellox13.color = candle_light;

    Light yellox14;
    yellox14.pos = glm::vec3(sqrt(3)/2, -0.2f, -0.5f);
    yellox14.color = candle_light;

    Light yellox16;
    yellox16.pos = glm::vec3(0.5f, -0.2f, -sqrt(3)/2);
    yellox16.color = candle_light;



     // lumiere vitraille

    glm::vec3 vitraille_light_green = glm::vec3(0.25f, 0.25f, 0.25f);

    Light vitrox;
    vitrox.pos = glm::vec3(1.0f, 10.0f, 0.0f);
    vitrox.color = vitraille_light_green;

    Light vitrox2;
    vitrox2.pos = glm::vec3(sqrt(3)/2, 10.0f, 0.5f);
    vitrox2.color = vitraille_light_green;

    Light vitrox4;
    vitrox4.pos = glm::vec3(0.5f, 10.0f, sqrt(3)/2);
    vitrox4.color = vitraille_light_green;

    Light vitrox5;
    vitrox5.pos = glm::vec3(0.0f, 10.0f, 1.0f);
    vitrox5.color = vitraille_light_green;

    Light vitrox6;
    vitrox6.pos = glm::vec3(-0.5f, 10.0f, sqrt(3)/2);
    vitrox6.color = vitraille_light_green;

    Light vitrox8;
    vitrox8.pos = glm::vec3(-sqrt(3)/2, 10.0f, 0.5f);
    vitrox8.color = vitraille_light_green;

    Light vitrox9;
    vitrox9.pos = glm::vec3(-1.0f, 10.0f, 0.0f);
    vitrox9.color = vitraille_light_green;

    Light vitrox10;
    vitrox10.pos = glm::vec3(-0.5f, 10.0f, -sqrt(3)/2);
    vitrox10.color = vitraille_light_green;

    Light vitrox12;
    vitrox12.pos = glm::vec3(-sqrt(3)/2, 10.0f, -0.5f);
    vitrox12.color = vitraille_light_green;

    Light vitrox13;
    vitrox13.pos = glm::vec3(0.0f, 10.0f, -1.0f);
    vitrox13.color = vitraille_light_green;

    Light vitrox14;
    vitrox14.pos = glm::vec3(sqrt(3)/2, 1.0f, -0.5f);
    vitrox14.color = vitraille_light_green;

    Light vitrox16;
    vitrox16.pos = glm::vec3(0.5f, 1.0f, -sqrt(3)/2);
    vitrox16.color = vitraille_light_green;

    std::vector<Light> light_list = {yellox, yellox2, yellox4, yellox5, yellox6, yellox8, yellox9,
         yellox10, yellox12, yellox13, yellox14, yellox16,vitrox, vitrox2, vitrox4, vitrox5, vitrox6, vitrox8, vitrox9,
         vitrox10, vitrox12, vitrox13, vitrox14, vitrox16};

    //yellox2, yellox4, yellox5, yellox6, yellox8, yellox9,
         //yellox10, yellox12, yellox13, yellox14, yellox16
    

    //define textures
    Texture *texture = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture1.png");
        // chemin Elise : /Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture1.png
        // chemin Tiph : C:/Users/tipha/Documents/Projet_info_graphique/textures/texture1.png
        // chemin Lina : C:/Users/Newteam-Consulting/Documents/infopasgraphique/info_graphique/textures/texture1.png

    Texture *texture2 = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture2.jpg");
        //chemin Tiph : C:/Users/tipha/Documents/Projet_info_graphique/textures/texture2.jpg
        //chemin Lina : C:/Users/Newteam-Consulting/Documents/infopasgraphique/info_graphique/textures/texture2.jpg

    Texture *texture3 = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texture3.png");

    Texture *candle_color = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/candle_color.png");

    Texture *texturecaillou = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/murcaillou.png");

    Texture *texturevitraille = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/vitrail.png");

    Texture *texturesol = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/texturesol.png");

    Texture *text_blanc = new Texture("/Users/eliseordoquy/Programmation/OpenGL/info_graphique/textures/blanc.png");

    //add lights in the shader 
    texlight_shader->use();
    texlight_shader->setInt("lightCount", light_list.size());
    for (int i = 0; i < light_list.size(); i++) {
        texlight_shader->setVec3("light_list[" + std::to_string(i) + "].pos", light_list[i].pos);
        texlight_shader->setVec3("light_list[" + std::to_string(i) + "].color", light_list[i].color);
    }

    // Passer la position de la caméra au shader
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.25f, 0.0f);
    texlight_shader->setVec3("viewPos", cameraPos);


    Shape* sphere1 = new TexturedSphere(texlight_shader, texture);
    glm::mat4 sphere1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -4.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));


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



    Shape* mur1 = new Carre(texlight_shader,texturecaillou, 50.0, 50.0);
    glm::mat4 mur1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* mur1_node = new Node(mur1_mat);

    mur1_node->add(mur1);
    viewer.scene_root->add(mur1_node);

    Shape* mur3 = new Carre(texlight_shader, texturecaillou, 50.0, 50.0);
    glm::mat4 mur3_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 5.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* mur3_node = new Node(mur3_mat);

    mur3_node->add(mur3);
    viewer.scene_root->add(mur3_node);

    Shape* mur4 = new Carre(texlight_shader, texturecaillou, 50.0, 50.0);
    glm::mat4 mur4_mat = glm::translate(glm::mat4(1.0f), glm::vec3(5.0f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    Node* mur4_node = new Node(mur4_mat);

    mur4_node->add(mur4);
    viewer.scene_root->add(mur4_node);

    Shape* mur2 = new Carre(texlight_shader, texturecaillou, 50.0, 50.0);
    glm::mat4 mur2_mat = glm::translate(glm::mat4(1.0f), glm::vec3(-5.0f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    Node* mur2_node = new Node(mur2_mat);

    mur2_node->add(mur2);
    viewer.scene_root->add(mur2_node);

        Shape* sol1 = new Carre(texlight_shader,texturesol, 50.0, 50.0);
    glm::mat4 sol1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* sol1_node = new Node(sol1_mat);

    sol1_node->add(sol1);
    viewer.scene_root->add(sol1_node);


    Shape* plafond1 = new Carre(texlight_shader, texturesol, 50.0, 50.0);
    glm::mat4 plafond1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 6.1f, 0.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* plafond1_node = new Node(plafond1_mat);

    plafond1_node->add(plafond1);
    viewer.scene_root->add(plafond1_node);


    Shape* vitraux = new Cylinder(texlight_shader, texturevitraille, 0.001f, 0.5f);

    glm::mat4 vitraux_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 6.0f, 0.0f))
        * glm::scale(glm::mat4(0.05f), glm::vec3(5.0f, 1.0f, 5.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* vitraux_node = new Node(vitraux_mat);
    vitraux_node->add(vitraux);
    viewer.scene_root->add(vitraux_node);



   


    viewer.run();
}
