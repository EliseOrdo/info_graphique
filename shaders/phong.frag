#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec3 LightPos;   // extra in variable, since we need the light position in view space we calculate this in the vertex shader

uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    // ambient
    // define ambient strength
    vec3 ka = vec3(0.3f);
    vec3 ambient = lightColor*ka; // calculate corrcet ambient color

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = LightPos-FragPos;// TODO calculate light direction
    float kd = 0.3f;
    float diff = kd*(dot(lightDir,norm)); // TODO calculate correct diffuse strength
    vec3 diffuse = diff * lightColor;
    
    // specular
    float specularStrength = 0.3;
    vec3 viewDir = normalize(-FragPos); // the viewer is always at (0,0,0) in view-space, so viewDir is (0,0,0) - Position => -Position
    vec3 reflectDir = reflect(-lightDir, norm);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);

    vec3 specular = lightColor*specularStrength*spec;   // TODO calculate corrcet specular color
    
    vec3 result = (ambient + diffuse + specular) * objectColor; // TODO apply ambient, diffuse and specular to object color

    FragColor = vec4(result, 1.0);
}
