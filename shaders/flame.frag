#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform float time;

// Simple noise function
float noise(vec2 p) {
    return fract(sin(dot(p, vec2(12.9898, 78.233))) * 43758.5453);
}

void main()
{
    vec2 uv = TexCoord;
    
    // Animation parameters
    float flicker = sin(time * 8.0 + uv.y * 10.0) * 0.05;
    float flicker2 = sin(time * 12.0 + uv.x * 8.0) * 0.03;
    
    // Deform the flame
    uv.x += flicker + flicker2;
    
    // Flame shape (wider at bottom, pointed at top)
    float width = 0.15 * (1.0 - uv.y * 0.8);
    float shape = smoothstep(width + 0.1, width, abs(uv.x - 0.5));
    shape *= smoothstep(1.0, 0.2, uv.y);
    shape *= smoothstep(0.0, 0.2, uv.y);
    
    // Flame colors (gradient from yellow to orange to red)
    vec3 innerColor = vec3(1.0, 0.95, 0.6);   // Bright yellow
    vec3 middleColor = vec3(1.0, 0.5, 0.1);   // Orange
    vec3 outerColor = vec3(0.8, 0.2, 0.05);   // Red
    
    // Distance from center for color gradient
    vec2 center = vec2(0.5, 0.3);
    float dist = distance(uv, center);
    
    // Mix colors based on distance
    float colorMix = smoothstep(0.0, 0.3, dist);
    vec3 flameColor = mix(innerColor, middleColor, colorMix);
    flameColor = mix(flameColor, outerColor, smoothstep(0.3, 0.5, dist));
    
    // Add noise for realism
    float noiseVal = noise(uv * 10.0 + time);
    flameColor += (noiseVal - 0.5) * 0.1;
    
    // Alpha for transparency
    float alpha = shape;
    
    FragColor = vec4(flameColor, alpha);
}
