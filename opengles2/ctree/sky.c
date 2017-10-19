/*
 * sky.c
 *
 * Copyright (c) 2007-2012, NVIDIA CORPORATION. All rights reserved.
 *
 * NVIDIA CORPORATION and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA CORPORATION is strictly prohibited.
 */

//
// Sky construction and rendering
//

#include "nvgldemo.h"
#include "vector.h"
#include "sky.h"
#include "shaders.h"


// Parameters used in this module.
#define SKY_HEIGHT (20.0f)
#define SKY_FACETS (24)

static float3 *vertices;
static float2 *tex_coords;
static GLuint texture;

// Constructor and destructor.
void
Sky_initialize(
    GLuint t)
{
    int i;

    texture = t;

    vertices = (float3*)MALLOC(sizeof(float3) * ((SKY_FACETS+1)*2));
    tex_coords = (float2*)MALLOC(sizeof(float2) * ((SKY_FACETS+1)*2));

    for (i=0; i<=SKY_FACETS; ++i) {
        float t = 1.0f/SKY_FACETS*i;

        float s = SIN(PI*2.0f*t);
        float c = COS(PI*2.0f*t);
        float tc;

        set_3(vertices[i*2], c*SKY_RADIUS, s*SKY_RADIUS, 0.0f);
        set_3(vertices[i*2+1], c*SKY_RADIUS, s*SKY_RADIUS, SKY_HEIGHT);

        tc = t * 4;

        set_2(tex_coords[i*2], tc, 0.0f);
        set_2(tex_coords[i*2+1], tc, 0.99f);

    }

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
}

void
Sky_deinitialize(void)
{
    FREE(vertices);
    FREE(tex_coords);
}


void
Sky_draw(void)
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glBindTexture(GL_TEXTURE_2D, texture);

    glUseProgram(prog_simpletex);
    glUniform4f(uloc_simpletexColor, 0.5f, 0.5f, 0.5f, 1.0f);
    glEnableVertexAttribArray(aloc_simpletexVertex);
    glEnableVertexAttribArray(aloc_simpletexTexcoord);

    glVertexAttribPointer(aloc_simpletexVertex,
                          3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(aloc_simpletexTexcoord,
                          2, GL_FLOAT, GL_FALSE, 0, tex_coords);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, (SKY_FACETS+1)*2);
    glDisableVertexAttribArray(aloc_simpletexVertex);
    glDisableVertexAttribArray(aloc_simpletexTexcoord);

    glDisable(GL_CULL_FACE);

    glUseProgram(prog_simplecol);
    glVertexAttrib4f(aloc_simplecolColor,
                     12.0f/255.f, 30.0f/255.f, 52.0f/255.f, 1.0f);
    glEnableVertexAttribArray(aloc_simplecolVertex);
    glVertexAttribPointer(aloc_simplecolVertex,
                          3, GL_FLOAT, GL_FALSE, 3*2*sizeof(float),
                          &vertices[1]);
    glDrawArrays(GL_TRIANGLE_FAN, 0, SKY_FACETS);
    glDisableVertexAttribArray(aloc_simplecolVertex);
}
