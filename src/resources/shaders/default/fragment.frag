#version 330 core
out vec4 FragColor;
in vec3 fragCol;

void main()
{
   FragColor = vec4(fragCol, 1.0f); // 1.0f, 0.5f, 0.2f
}