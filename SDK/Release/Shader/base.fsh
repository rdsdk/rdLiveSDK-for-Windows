#version 330 core
uniform sampler2D tex;
in vec2 vs_tex_coord;
layout(location = 0) out vec4 fColor;
void main() {
	fColor = texture( tex,vs_tex_coord );
};