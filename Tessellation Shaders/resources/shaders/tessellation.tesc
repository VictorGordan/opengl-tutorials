#version 460 core

// Quads
layout (vertices = 4) out;

in vec2 uvs[];
out vec2 uvsCoord[];

layout(location = 0) uniform vec2 cursor;
vec4 cursorPos = vec4(2.0 * cursor - 1.0, 0.0, 0.0); // get in range [-1, 1]

const int MIN_TES = 2;
const int MAX_TES = 16;
const float MIN_DIST = 0.0;
const float MAX_DIST = 1.5;

void main()
{
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
    uvsCoord[gl_InvocationID] = uvs[gl_InvocationID];

    if (gl_InvocationID == 0)
    {
        vec4 center0 = gl_in[0].gl_Position + (gl_in[3].gl_Position - gl_in[0].gl_Position) / 2.0; // left side
        vec4 center1 = gl_in[1].gl_Position + (gl_in[0].gl_Position - gl_in[1].gl_Position) / 2.0; // bot side
        vec4 center2 = gl_in[2].gl_Position + (gl_in[1].gl_Position - gl_in[2].gl_Position) / 2.0; // right side
        vec4 center3 = gl_in[3].gl_Position + (gl_in[2].gl_Position - gl_in[3].gl_Position) / 2.0; // top side
        
        float dist0 = length(cursorPos - center0);
        float dist1 = length(cursorPos - center1);
        float dist2 = length(cursorPos - center2);
        float dist3 = length(cursorPos - center3);

        int tes0 = int(mix(MAX_TES, MIN_TES, clamp(dist0 / MAX_DIST, 0.0, 1.0)));
        int tes1 = int(mix(MAX_TES, MIN_TES, clamp(dist1 / MAX_DIST, 0.0, 1.0)));
        int tes2 = int(mix(MAX_TES, MIN_TES, clamp(dist2 / MAX_DIST, 0.0, 1.0)));
        int tes3 = int(mix(MAX_TES, MIN_TES, clamp(dist3 / MAX_DIST, 0.0, 1.0)));

        gl_TessLevelOuter[0] = tes0; // left for quads
        gl_TessLevelOuter[1] = tes1; // bot for quads
        gl_TessLevelOuter[2] = tes2; // right for quads
        gl_TessLevelOuter[3] = tes3; // top for quads
        
        gl_TessLevelInner[0] = max(tes1, tes3); // top bot for quads
        gl_TessLevelInner[1] = max(tes0, tes2); // left right for quads
    }
}


// Triangles
//layout (vertices = 3) out;
//
//in vec2 uvs[];
//out vec2 uvsCoord[];
//
//void main()
//{
//    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
//    uvsCoord[gl_InvocationID] = uvs[gl_InvocationID];
//
//    gl_TessLevelOuter[0] = 2; // left for triangles
//    gl_TessLevelOuter[1] = 2; // bot for triangles
//    gl_TessLevelOuter[2] = 2; // right for triangles
//        
//    gl_TessLevelInner[0] = 4; // all inner sides for triangles
//}
