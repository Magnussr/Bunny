#version 130

uniform mat4 projection_matrix;
uniform mat4 modelview_matrix;
uniform mat3 normal_matrix;

in  vec3 in_Position;
in  vec3 in_Normal;
out vec3 ex_Color;
out vec3 ex_Normal;
out vec3 ex_View;
out vec3 ex_Light;

void main() {
	vec4 pos = modelview_matrix * vec4(in_Position, 1.0);
	gl_Position = projection_matrix * pos;
	ex_Color = vec3(0.5f, 0.5f, 1.0f);
	ex_Normal = normal_matrix*in_Normal;
	ex_View = -pos.rgb;
	ex_Light = vec3(0.0f, 0.0f, 0.0f) - pos.rgb;
}