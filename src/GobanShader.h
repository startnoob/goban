//
// Created by jan on 7.5.17.
//

#include <string>
#include "glyphy/demo-font.h"
#include "Metrics.h"
#include "GobanModel.h"

class GobanView;

#ifndef GOBAN_GOBANSHADER_H
#define GOBAN_GOBANSHADER_H

#include "ShellOpenGL.h"
#include "Board.h"
#include "GobanModel.h"
#include "Camera.h"

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "spdlog/spdlog.h"

#define OPTIMIZE_SHADERS
#undef OPTIMIZE_SHADERS

#define NOT_OPTIMIZED

#ifdef OPTIMIZE_SHADERS
#include <glsl/glsl_optimizer.h>
    const bool OPTIMIZE = true;
    #define FRAGMENT_FILE "data/glsl/fragment.2D.glsl"
    #define VERTEX_FILE "data/glsl/vertex.glsl"
#else
const bool OPTIMIZE = false;
#ifdef NOT_OPTIMIZED
#define FRAGMENT_FILE "data/glsl/fragment.2D.glsl"
#define VERTEX_FILE "data/glsl/vertex.glsl"
#else
#define FRAGMENT_FILE "data/glsl/fragment.glsl.opt"
        #define VERTEX_FILE "data/glsl/vertex.glsl.opt"
#endif
#endif

GLuint shaderCompileFromString(GLenum type, const std::string& source);

void shaderAttachFromString(GLuint program, GLenum type, const std::string& source);

GLuint make_buffer(GLenum target, const void *, GLsizei);

#ifdef OPTIMIZE_SHADERS

bool replace(std::string& str, const std::string& from, const std::string& to);

std::string createShader(const std::string& fname, bool optimize, glslopt_ctx* ctx, glslopt_shader_type shaderType);

#else
std::string createShader(const std::string& fname, bool optimize);
#endif


class GobanShader {
public:
    GobanShader(const GobanView& view): shadersReady(false), shaderChanged(false),
        currentProgram(-1), ww(-1.0f), stoneh(-1.0f),
        width(0), height(0), gamma(1.0f), contrast(0.0f),
	view(view), animT(0.5f)
    {
        console = spdlog::get("console");
    }
    void initProgram(int which);
    void setMetrics(const Metrics &);
    void init();
    void destroy();
    void draw(const GobanModel&, const DDG::Camera&, int, float);
    void cycleShaders();
    void use();
    void unuse();
    void setTime(float);
    void setPan(glm::vec3);
    void setRotation(glm::mat4x4);
    void setResolution(float, float);
    void setGamma(float);
    void setContrast(float);
    float getGamma(){ return gamma;}
    float getContrast(){ return contrast;}
    bool isReady() { return shadersReady;}
    float getStoneHeight() const { return currentProgramH; }
    void setReady() { shadersReady = true; }
    int getCurrentProgram() const {return currentProgram;}
private:
    std::shared_ptr<spdlog::logger> console;
    GLuint gobanProgram = 0;
    GLuint iVertex = 0;
    GLint iMouse;
    GLint iDim;
    GLint iModelView;
	GLint iStone;
    GLint iResolution;
    GLint iStones;
    GLuint bufStones;
    GLuint uBlockIndex;
    GLuint blockBindingPoint = 1;
    GLuint vertexBuffer, elementBuffer;
    GLint iGamma;
    GLint iContrast;
    GLint fsu_fNDIM;
    GLint fsu_boardaa;
    GLint fsu_boardbb;
    GLint fsu_boardcc;
    GLint fsu_ww;
    GLint fsu_iww;
    GLint fsu_w;
    GLint fsu_h;
    GLint fsu_stoneRadius;
    GLint fsu_d;
    GLint fsu_stoneradius2;
    GLint fsu_dn;
    GLint fsu_b;
    GLint fsu_y;
    GLint fsu_px;
    GLint fsu_pxs;
    GLint fsu_r1;
    GLint fsu_r2;
    GLint fsu_r123r123;
    GLint fsu_rrr;
    GLint fsu_r1r1ir2ir2;
    GLint fsu_maxBound;
    GLint fsu_dw;
    GLint fsu_iscale;
    GLint fsu_bowlRadius;
    GLint fsu_bowlRadius2;
    GLint fsu_cc;

    GLint iWhiteCapturedCount;
    GLint iBlackCapturedCount;
    GLint iddc;


    int AA;

    static const std::array<GLfloat, 16> vertexBufferData;
    static const GLushort elementBufferData[];
    static const std::array<float, 4> programH;

    GLint iTranslate;
    GLint iTime;
    GLint iAnimT;
    GLint iAA;

    bool shadersReady;
    bool shaderChanged;

    int currentProgram;
    float currentProgramH;

    float ww, stoneh;
    float width, height;
    float gamma, contrast;

    const GobanView& view;
public:
    const float animT;
};

#endif //GOBAN_GOBANSHADER_H
