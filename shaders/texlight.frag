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


uniform vec3 viewPos;
uniform int lightCount;
uniform Light light_list[16];


void main() {
    

    vec3 texColor = texture(diffuse_map, frag_tex_coords).rgb;
    vec3 result = vec3(0.0);

    for(int i = 0;i<lightCount; i++){
        vec3 LightPos = light_list[i].pos;
        vec3 lightColor = light_list[i].color;

        float dist = length(LightPos - FragPos);
        // Atténuation: la lumière diminue avec la distance
        float attenuation = 1.0 / (1.0 + 0.04 * dist + 0.01 * dist * dist);

        // ambient
        // define ambient strength
        vec3 ka = vec3(0.1f);
        vec3 ambient = lightColor * ka * attenuation;  

        // diffuse 
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(LightPos-FragPos);// calculate light direction
        float kd = 0.5f;

        float diff = kd*max(dot(lightDir,norm), 0.0f); // calculate correct diffuse strength
        vec3 diffuse = diff * lightColor * attenuation;
    
        // specular
        float specularStrength = 1.0;
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);  
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 14.0);//pow 32 � la base
        vec3 specular = lightColor*specularStrength*spec*attenuation;   // calculate corrcet specular color


        result += (ambient + diffuse+ specular) * texColor ; // apply ambient, diffuse and specular to object color
        
    }
    FragColor = vec4(result, 1.0);


}