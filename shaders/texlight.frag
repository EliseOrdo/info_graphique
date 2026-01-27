#version 330 core

struct Light {
        vec3 pos;
        vec3 color;
    };

uniform sampler2D diffuse_map;

out vec4 FragColor;

in vec2 frag_tex_coords;

in vec3 FragPos;
in vec3 Normal;



uniform int lightCount;
uniform Light light_list[16];


void main() {
    


    vec3 texColor = texture(diffuse_map, frag_tex_coords).rgb;
    vec3 result = vec3(0.0);

    for(int i = 0;i<lightCount; i++){
        vec3 LightPos = light_list[i].pos;
        vec3 lightColor = light_list[i].color;

    
        // ambient
        // define ambient strength
        vec3 ka = vec3(0.8f);
        vec3 ambient = lightColor*ka;   // calculate corrcet ambient color

        // diffuse 
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(LightPos-FragPos);// calculate light direction
        float kd = 0.5f;
        float diff = kd*(dot(lightDir,norm)); // calculate correct diffuse strength
        vec3 diffuse = diff * lightColor;
    
        // specular
        float specularStrength = 1.0;
        vec3 viewDir = normalize(-FragPos); // the viewer is always at (0,0,0) in view-space, so viewDir is (0,0,0) - Position => -Position
        vec3 reflectDir = reflect(-lightDir, norm);  
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 14.0);//pow 32 � la base
        vec3 specular = lightColor*specularStrength*spec;   // calculate corrcet specular color


        result += (ambient + diffuse+ specular) * texColor ; // apply ambient, diffuse and specular to object color
        
    }
    FragColor = vec4(result, 1.0);


}