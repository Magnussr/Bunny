#version 130

in vec3 ex_Color;
out vec4 res_Color;

void main() {
	res_Color = vec4(ex_Color, 1.0f);
}