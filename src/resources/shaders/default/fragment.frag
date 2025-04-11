#version 330 core
out vec4 FragColor;
in vec3 fragCol;

void main()
{
   FragColor = vec4(fragCol, 1.0f);
}