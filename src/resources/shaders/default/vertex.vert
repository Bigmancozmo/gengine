#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 fragCol;

uniform mat4 transform;

void main()
{
	fragCol = aColor;
	gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}