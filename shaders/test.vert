#version 130

uniform mat4 projection_matrix;
uniform mat4 modelview_matrix;

in  vec3 in_Position;
out vec3 ex_Color;

void main() {
   vec4 pos = vec4(in_Position, 1.0);
	gl_Position = projection_matrix * modelview_matrix * pos;
	ex_Color = vec3(0.5f, 0.5f, 1.0f);
}