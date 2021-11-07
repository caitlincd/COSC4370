
#version 330 core
out vec4 color;

in vec2 UV;
uniform sampler2D myTextureSampler;

void main()
{
    // TODO: pub with your code...
    // color of the texture at the specified UV
    // coordinates map to the lower 2/3 of image when the upper 2/3 is what is needed
    float y_val = UV.y;
    // if coordinates are in the lowest 1/3 section of image, remap to the top 1/3 section
    if (UV.y/0.666 > 1) { y_val = mod(UV.y, 0.666); }
    
    color = texture ( myTextureSampler, vec2(UV.x, y_val) ).rgba;
}
