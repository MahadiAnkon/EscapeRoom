//
//  main.cpp
//  3D Object Drawing
//
//  Created by Nazirul Hasan on 4/9/23.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<random>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "camera.h"
#include "basic_camera.h"
#include "pointLight.h"
#include "directionalLight.h"
#include "spotLight.h"
#include "cube.h"
#include "stb_image.h"
#include "curve.h"
#include <iostream>
#include <music/irrKlang.h>
using namespace std;
using namespace irrklang;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax);


// settings
const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 720;
float angle = 0.0;
// modelling transform
float rotateAngle_X = 0.0;
float rotateAngle_Y = 0.0;
float rotateAngle_Z = 0.0;
float rotateAxis_X = 0.0;
float rotateAxis_Y = 0.0;
float rotateAxis_Z = 1.0;
float translate_X = 0.0;
float translate_Y = 0.0;
float translate_Z = 0.0;
float scale_X = 1.0;
float scale_Y = 1.0;
float scale_Z = 1.0;
bool rotate_around = false;
float rotate_fan = 0.0;
float rotatedegree = 0.0;
bool dooropen = false;
bool doortonext = false;
float slide=0;
float ladderx=0.0, ladderz=0.0;
unsigned int wood_tex;
unsigned int sofa_tex1;
unsigned int bed_sofa;
unsigned int sofa_tex2;
unsigned int sofa_tex3;
unsigned int tv_tex;
unsigned int shelf_tex;
unsigned int showcase_tex;
unsigned int showcase_door;
unsigned int shelf_tex2;
unsigned int wall_tex1;
unsigned int wall_tex2;
unsigned int wall_tex3;
unsigned int blacktex;
unsigned int floor_tex;
unsigned int painting_tex;
unsigned int painting_tex2;
unsigned int painting_tex3;
unsigned int bed_frame;
unsigned int bedsheet;
unsigned int bedframe;
unsigned int pillow;
unsigned int table_tex;
unsigned int mirror_tex;
unsigned int rug_tex;
unsigned int brick_wood;
unsigned int fridge_door1;
unsigned int fridge_door2;
unsigned int white1;
int dd=0;
int anim = 0;
const int MAX_ANIM_VALUE = 74;
bool box=false;
bool box2 = false;
bool box3 = false;
bool box4 = false;
float shamne1=0.0;
float shamne2 = 0.0;
float shamne3 = 0.0;
float shamne4 = 0.0;
float aquarium;
bool swing_toogle = false;
float swing_angle = 0.0;
bool is_increasing = true;
float swing_translate = 0.0;
float swing_translatez = 0.0;
float fridge_door_open = 0.0;
float fridge_door_open2 = 0.0;
unsigned int digits;
unsigned int drawerinside;
unsigned int firstdig, secdic, thirdig;
string fdigits;
unsigned int handle;
ISoundEngine* engine = createIrrKlangDevice();
bool keypick=false;
string load_digit;

float shamnet = 0.0;
float shamne2t = 0.0;
float shamne3t = 0.0;
float shamne4t = 0.0;


float shamne1b = 0.0;
float shamne2b = 0.0;
float shamne3b = 0.0;
float shamne4b = 0.0;

float shamne1w = 0.0;
float shamne2w = 0.0;
float shamne3w = 0.0;
float shamne4w = 0.0;
bool fl = false;
bool atoggle = false;
bool tabler1 = false;
bool warer1 = false;
bool beder1 = false;


bool tabler2 = false;
bool warer2 = false;
bool beder2 = false;

bool tabler3 = false;
bool warer3 = false;
bool beder3 = false;

bool tabler4 = false;
bool warer4 = false;
bool beder4 = false;
int start_time;
int current_time;
vector<float>Vase = {
-0.0550, 2.1150, 5.1000,
-0.1800, 2.1350, 5.1000,
-0.2500, 2.1250, 5.1000,
-0.2250, 2.0050, 5.1000,
-0.2700, 1.8500, 5.1000,
-0.3800, 1.6600, 5.1000,
-0.3650, 1.4400, 5.1000,
-0.2950, 1.2250, 5.1000,
-0.2600, 0.9750, 5.1000,
-0.2100, 0.8100, 5.1000,
-0.1700, 0.6550, 5.1000,
};

vector<float>Vase2 = {
0.1050, 0.5700, 5.1000,
-0.0350, 0.5850, 5.1000,
-0.1300, 0.5900, 5.1000,
-0.2500, 0.6850, 5.1000,
-0.3150, 0.8500, 5.1000,
-0.3600, 0.9950, 5.1000,
-0.3750, 1.1400, 5.1000,
-0.3750, 1.3150, 5.1000,
-0.3600, 1.4800, 5.1000,
-0.3550, 1.6450, 5.1000,
-0.2800, 1.8250, 5.1000,
-0.2250, 1.9950, 5.1000,
-0.1950, 2.1800, 5.1000,
-0.1750, 2.3250, 5.1000,
-0.1750, 2.4300, 5.1000,
-0.1600, 2.5350, 5.1000,
};


vector<float>Vase3{
-0.5900, 1.8500, 5.1000,
-0.4950, 1.8050, 5.1000,
-0.3050, 1.7250, 5.1000,
-0.2050, 1.6150, 5.1000,
-0.1700, 1.4200, 5.1000,
-0.1900, 1.2550, 5.1000,
-0.2450, 1.1050, 5.1000,
-0.3200, 0.9700, 5.1000,
-0.4550, 0.8000, 5.1000,
-0.5400, 0.6350, 5.1000,
-0.5950, 0.4450, 5.1000,
-0.6050, 0.2250, 5.1000,
-0.6000, 0.0500, 5.1000,
-0.5650, -0.0400, 5.1000,
-0.5400, -0.1550, 5.1000,
-0.4200, -0.2050, 5.1000,
-0.2650, -0.2550, 5.1000,
-0.1850, -0.2500, 5.1000,
-0.0300, -0.2550, 5.1000,
0.0600, -0.2600, 5.1000,
};

vector<float>Vase4
{
    0.0100, 1.8300, 5.1000,
        -0.1850, 1.8500, 5.1000,
        -0.3600, 1.8500, 5.1000,
        -0.5000, 1.7100, 5.1000,
        -0.5750, 1.5750, 5.1000,
        -0.6200, 1.4100, 5.1000,
        -0.5750, 1.2850, 5.1000,
        -0.4600, 1.1300, 5.1000,
        -0.3850, 0.9650, 5.1000,
        -0.3300, 0.8100, 5.1000,
        -0.2950, 0.6600, 5.1000,
        -0.3250, 0.5150, 5.1000,
        -0.3750, 0.4300, 5.1000,
        -0.4200, 0.3400, 5.1000,
};

vector<float>Vase5
{
-0.2850, 1.8000, 5.1000,
-0.2850, 1.7500, 5.1000,
-0.2700, 1.7250, 5.1000,
-0.2500, 1.6450, 5.1000,
-0.2500, 1.6300, 5.1000,
-0.2400, 1.5850, 5.1000,
-0.2450, 1.5450, 5.1000,
-0.2700, 1.5050, 5.1000,
-0.3000, 1.4700, 5.1000,
-0.3300, 1.3950, 5.1000,
-0.3900, 1.3100, 5.1000,
-0.4050, 1.2350, 5.1000,
-0.4200, 1.1550, 5.1000,
-0.4300, 1.0150, 5.1000,
-0.4300, 0.8950, 5.1000,
-0.4100, 0.7500, 5.1000,
-0.3450, 0.6800, 5.1000,
-0.2950, 0.6150, 5.1000,
-0.2750, 0.5150, 5.1000,
-0.2600, 0.4450, 5.1000,
-0.2800, 0.3000, 5.1000,
-0.2500, 0.1850, 5.1000,
-0.2350, 0.0750, 5.1000,
-0.1600, 0.0300, 5.1000,
-0.0200, 0.0200, 5.1000,
};

vector<float>Bowl
{
-0.7850, 1.4250, 5.1000,
-0.7350, 1.0950, 5.1000,
-0.6200, 0.8350, 5.1000,
-0.5100, 0.6250, 5.1000,
-0.3950, 0.5400, 5.1000,
-0.1900, 0.4900, 5.1000,
-0.0200, 0.4600, 5.1000,
0.0900, 0.4650, 5.1000,
0.2450, 0.4800, 5.1000,
};


vector<float>Circle
{
0.0750, 1.8400, 5.1000,
-1.1200, 1.8450, 5.1000,
};

vector<float>glassp{
    0.0900, 1.8350, 5.1000,
0.0050, 1.8350, 5.1000,
-0.0850, 1.8400, 5.1000,
-0.1650, 1.8300, 5.1000,
-0.2950, 1.8300, 5.1000,
-0.3700, 1.8300, 5.1000,
-0.5400, 1.8350, 5.1000,
-0.4750, 1.7750, 5.1000,
-0.4100, 1.7350, 5.1000,
-0.3550, 1.6950, 5.1000,
-0.3300, 1.6100, 5.1000,
-0.3150, 1.5150, 5.1000,
-0.3200, 1.4400, 5.1000,
-0.3250, 1.3450, 5.1000,
-0.3900, 1.2200, 5.1000,
-0.4400, 1.0550, 5.1000,
-0.5300, 0.9800, 5.1000,
-0.5800, 0.8300, 5.1000,
-0.5750, 0.7000, 5.1000,
-0.6000, 0.6200, 5.1000,
-0.6000, 0.5500, 5.1000,
-0.5950, 0.4350, 5.1000,
-0.5650, 0.3050, 5.1000,
-0.5450, 0.2300, 5.1000,
-0.5300, 0.0300, 5.1000,
-0.5350, 0.1200, 5.1000,
};

vector<float> Table = {
                 0, 1.65, 5.1000,
                 0, 1.72, 5.1000,
                 -0.005, 1.72, 5.1000,
                -0.1600, 1.72, 5.1000,
                -0.2300, 1.72, 5.1000,
                -0.2950, 1.7200, 5.1000,
                -0.3700, 1.7200, 5.1000,
                -0.4500, 1.7200, 5.1000,
                -0.5400, 1.7200, 5.1000,
                -0.6100, 1.7200, 5.1000,
                -0.6900, 1.7200, 5.1000,
                -0.6900, 1.6600, 5.1000,
                -0.6900, 1.6150, 5.1000,
                -0.6900, 1.5600, 5.1000,
                -0.6600, 1.56, 5.1000,
                -0.5950, 1.56, 5.1000,
                -0.5450, 1.56, 5.1000,
                -0.4850, 1.56, 5.1000,
                -0.4200, 1.56, 5.1000,
                -0.3600, 1.56, 5.1000,
                -0.2800, 1.56, 5.1000,
                -0.1900, 1.56, 5.1000,
                -0.1250, 1.56, 5.1000,
                -0.0650, 1.56, 5.1000,
                 0, 1.56, 5.1000,
};
vector<float> Tableleg = {
-0.0750, 1.9300, 5.1000,
-0.0150, 0.0250, 5.1000,
};
//Camera
Camera camera(glm::vec3(0.0f, 0.0f, 1.5f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float eyeX = -2.0, eyeY = 1, eyeZ = -4.0;
float lookAtX = 0.0, lookAtY = 0.0, lookAtZ = 0;
glm::vec3 V = glm::vec3(0.0f, 1.0f, 0.0f);
BasicCamera basic_camera(eyeX, eyeY, eyeZ, lookAtX, lookAtY, lookAtZ, V);

// lights
// positions of the point lights
glm::vec3 LightPositions[] = {
    glm::vec3(1.50f,  1.50f,  -4.0f),
    glm::vec3(1.50f,  1.50f,  1.0f),
    glm::vec3(-5.5f,  1.5f,  -2.0f),
    glm::vec3(-1.5f,  1.5f,  1.0f),
};
DirLight dirlight(
    LightPositions[0].x, LightPositions[0].y, LightPositions[0].z,  // position
    0.05f, 0.05f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    //0.0f, 0.0f, 0.0f,        // emission
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    1       // light number
);
SpotLight spotlight(

    LightPositions[1].x, LightPositions[1].y, LightPositions[1].z,  // position
    0.05f, 0.05f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    //0.0f, 1.0f, 0.0f,        // emission
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    2       // light number
);
PointLight pointlight1(

    LightPositions[2].x, LightPositions[2].y, LightPositions[2].z,  // position
    0.05f, 0.05f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    //0.0f, 1.0f, 0.0f,        // emission
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    1       // light number
);
PointLight pointlight2(

    LightPositions[3].x, LightPositions[3].y, LightPositions[3].z,  // position
    0.05f, 0.05f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    //0.0f, 1.0f, 0.0f,        // emission
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    2       // light number
);


// light settings
bool pointLightOn1 = false;
bool pointLightOn2 = true;
bool dirLightOn = true;
bool spotLightOn = true;
bool ambientToggle = true;
bool diffuseToggle = true;
bool specularToggle = false;
bool emissionToggle = true;




// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;

glm::mat4 transform(float tr_x, float tr_y, float tr_z, int rot_x, int rot_y, int rot_z, float scal_x, float scal_y, float scal_z) {
    // Modelling Transformation
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X + tr_x, translate_Y + tr_y, translate_Z + tr_z));
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_X + rot_x), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + rot_y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z + rot_z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(scale_X * scal_x, scale_Y * scal_y, scale_Z * scal_z));
    model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    return model;
}


glm::mat4 transform2(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, a;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(tx, ty, tz));
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rx), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(ry), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rz), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(sx, sy, sz));
    a = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    return a;
}

void Sofa(Cube& cube, Shader& lightingShader, Shader& lightingShader2,  glm::mat4 model)
{
    cube.setTextureProperty(sofa_tex1,sofa_tex1, 32.0f);
    glm::mat4 a = transform(-0.8, -0.5, -5.5, 0, 0, 0, 4, 0.2, 1.5);
    cube.drawCubeWithTexture(lightingShader, model*a);


    a = transform(-0.8, -0.5 + 0.1, -5.5, 0, 0, 0, 2, 0.25, 1.5);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(.2, -0.5 + 0.1, -5.5, 0, 0, 0, 2, 0.25, 1.5);
    cube.drawCubeWithTexture(lightingShader, model * a);



    a = transform(-0.8, -0.28, -5.5, 0, 0, 0, 4, 1.2, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-0.8, -0.28, -5.4, 0, 0, 0, 0.2, 0.6, 1.3);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-0.8 + 1.9, -0.28, -5.4, 0, 0, 0, 0.2, 0.6, 1.3);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform(-0.8, -0.5, -5.5, 0, 0, 0, 0.1, -0.3, 1.5);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform(-0.8 + 1.95, -.5, -5.5, 0, 0, 0, 0.1, -0.3, 1.5);
    cube.drawCubeWithTexture(lightingShader, model * a);


}

void bedSofa(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(bed_sofa, bed_sofa, 32.0f);
    glm::mat4 a = transform(-0.8, -0.5, -5.5, 0, 0, 0, 4, 0.2, 1.5);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform(-0.8, -0.5 + 0.1, -5.5, 0, 0, 0, 2, 0.25, 1.5);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(.2, -0.5 + 0.1, -5.5, 0, 0, 0, 2, 0.25, 1.5);
    cube.drawCubeWithTexture(lightingShader, model * a);



    a = transform(-0.8, -0.28, -5.5, 0, 0, 0, 4, 1.2, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-0.8, -0.28, -5.4, 0, 0, 0, 0.2, 0.6, 1.3);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-0.8 + 1.9, -0.28, -5.4, 0, 0, 0, 0.2, 0.6, 1.3);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform(-0.8, -0.5, -5.5, 0, 0, 0, 0.1, -0.3, 1.5);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform(-0.8 + 1.95, -.5, -5.5, 0, 0, 0, 0.1, -0.3, 1.5);
    cube.drawCubeWithTexture(lightingShader, model * a);


}



void table(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(sofa_tex2, sofa_tex2, 32.0f);
    glm::mat4 a = transform(-0.45, -.2, -4.045, 0, 0, 0, 2, 0.2, 1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-0.45, -.6, -4.0, 0, 0, 0, 0.06, 0.8, 0.06);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);



    a = transform(-0.45 + 0.95, -.6, -4.0, 0, 0, 0, 0.06, 0.8, 0.06);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-0.45, -.6, -4.0 + 0.4, 0, 0, 0, 0.06, 0.8, 0.06);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-0.45 + 0.965, -.6, -4.0 + 0.4, 0, 0, 0, 0.06, 0.8, 0.06);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);
}

void shelf(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(shelf_tex, shelf_tex, 32.0f);
    glm::mat4 a = transform(-2.44, -.78, -1, 0, 90, 0, 1.7, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, -.78, -1, 0, 00, 0, 0.9, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, -.78, -1.9, 0, 00, 0, 0.9, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    cube.setTextureProperty(shelf_tex2, shelf_tex2, 32.0f);
    a = transform(-2.44, -.7, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform(-2.44, -.2, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, 0.4, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);


    cube.setTextureProperty(shelf_tex, shelf_tex, 32.0f);
    a = transform(-2.44, 0.98, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);
}


void showcase(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(shelf_tex, shelf_tex, 32.0f);
    glm::mat4 a = transform(-2.44, -.78, -1, 0, 90, 0, 1.7, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, -.78, -1, 0, 00, 0, 0.9, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform(-2.40, -.78, -1.44, 0, 00, 0, 0.9, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, -.78, -1.9, 0, 00, 0, 0.9, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, -.7, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, -.2, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, 0.4, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, 0.97, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);
}


void showcase2(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(shelf_tex, shelf_tex, 32.0f);
    glm::mat4 a = transform(-2.44, -.78, -1, 0, 90, 0, 1.7, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, -.78, -1, 0, 00, 0, 0.9, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform(-2.40, -.78, -1.44, 0, 00, 0, 0.9, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.40, -.78, -1.67, 0, 00, 0, 0.9, 3.5, 0.05);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, -.78, -1.9, 0, 00, 0, 0.9, 3.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, -.7, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, -.2, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, 0.4, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.44, 0.97, -1.85, 90, 00, 0, 0.9, 1.7, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);
}




void dooropenclose(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(showcase_door, showcase_door, 32.0f);
    glm::mat4 a = transform(-2.00, -.7, -1.0, 0, 90, 0, 0.78, 3.25, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);
}


void dooropenclose2(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(showcase_door, showcase_door, 32.0f);   
    //glm::mat4 tr = transform(2.00, .7, 1.44, 0,0,0,1,1,1); // to origin
    //glm::mat4 tr2 = transform(0, 0, 0, 0, min(angle, 180.0f), 0, 1, 1, 1); // rotate
   //glm::mat4 tr3 = transform(-2.00, -.7, -1.44, 0, 0, 0, 0.84, 3.25, 0.1); // back
    glm::mat4 a = transform(-2.00, -.7, -1.44, 0, 90, 0, 0.84, 3.25, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);
}

void book(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model, float r, float g, float b)
{
    glm::mat4 a = transform(-2.44, -.21, -2.70, -20, 0, 0, 0.6, 0.8, .2);
    cube.setMaterialisticProperty(glm::vec3(r, g, b));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);
}

void Fan(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, a;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0));
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 0.1f, 0.5f));
    a = scaleMatrix * translateMatrix;
    cube.setMaterialisticProperty(glm::vec3(0.82, 0.51, 0.263));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0));//,translate_X, translate_Y, translate_Z
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 0.1f, 0.5f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    //model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    a = rotateYMatrix * scaleMatrix * translateMatrix;
    //moveMatrix = rotateZMatrix * moveMatrix;
    cube.setMaterialisticProperty(glm::vec3(0.82, 0.51, 0.263));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -0.5f));//,
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 0.1f, 0.5f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(225.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    //model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    a = rotateYMatrix * scaleMatrix * translateMatrix;
    //moveMatrix = rotateZMatrix * moveMatrix;
    cube.setMaterialisticProperty(glm::vec3(0.82, 0.51, 0.263));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    a = transform(-0.1, -0.07, -0.2, 0, 0, 0, 1, 0.4, 1);
    cube.setMaterialisticProperty(glm::vec3(0.678, 0.318, 0.031));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);
}

void wall(Cube& cube, Cube& tiles_cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    //floor
    tiles_cube.setTextureProperty(floor_tex, floor_tex, 32.0f);
    glm::mat4 a = transform(-2.5, -.8, -6, 0, 0, 0, 10, 0.1, 16);
    tiles_cube.drawCubeWithTexture(lightingShader, model * a);

    //1st wall
    a = transform(-2.5, -.8, -6, 0, 0, 0, 10, 5, 0.1);
    cube.setMaterialisticProperty(glm::vec3(0.89, 0.694, 0.694));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.2, 1.45, -5.97, 0, 0, 0, 8.8, .5, 0.8);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    //2nd wall
    a = transform(-2.5, -.8, 2, 0, 0, 0, 10, 5, 0.1);
    cube.setMaterialisticProperty(glm::vec3(0.89, 0.694, 0.694));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.1, 1.45, 1.6, 0, 0, 0, 8.8, 0.5, 0.8);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);


    //3rd wall
    a = transform(-2.5, -.8, -3.5, 0, 0, 0, .1, 5, 11);
    cube.setMaterialisticProperty(glm::vec3(0.941, 0.776, 0.761));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.5, -.8, -6, 0, 0, 0, .1, 5, 3);
    cube.setMaterialisticProperty(glm::vec3(0.941, 0.776, 0.761));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.5, 0.7, -4.5, 0, 0, 0, .1, 1.5, 2);
    cube.setMaterialisticProperty(glm::vec3(0.941, 0.776, 0.761));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.5, 1.45, -6, 0, 0, 0, 0.8, 0.5, 16);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);


    //4th wall
    a = transform(2.5, -.8, -6, 0, 0, 0, .1, 5, 16);
    cube.setMaterialisticProperty(glm::vec3(0.988, 0.796, 0.78));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(2.1, 1.45, -6, 0, 0, 0, 0.8, 0.5, 16);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    //celling
    a = transform(-2.5, 1.7, -6, 0, 0, 0, 10, 0.1, 16);
    cube.setMaterialisticProperty(glm::vec3(0.902, 0.624, 0.408));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

}
void wall2(Cube& cube, Cube& tiles_cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    //floor
    glm::mat4 a = transform(-2.5, -.8, -4.5, 0, 0, 0, 10, 0.1, 13);
    tiles_cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-1.1, -.8, -6, 0, 0, 0, 7.5, 0.1, 13);
    tiles_cube.drawCubeWithTexture(lightingShader, model * a);

    //1st wall

    a = transform(-2.5, -.8, -6, 0, 0, 0, 10, 5, 0.1);
    cube.setMaterialisticProperty(glm::vec3(0.89, 0.694, 0.694));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.2, 1.45, -5.97, 0, 0, 0, 8.8, .5, 0.8);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    //2nd wall
    a = transform(-2.5, -.8, 2, 0, 0, 0, 10, 5, 0.1);
    cube.setMaterialisticProperty(glm::vec3(0.89, 0.694, 0.694));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.1, 1.45, 1.6, 0, 0, 0, 8.8, 0.5, 0.8);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    //3rd wall
    a = transform(-2.5, -.8, -6, 0, 0, 0, .1, 5, 16);
    cube.setMaterialisticProperty(glm::vec3(0.941, 0.776, 0.761));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.5, 1.45, -6, 0, 0, 0, 0.8, 0.5, 16);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    //4th wall


    a = transform(2.1, 1.45, -6, 0, 0, 0, 0.8, 0.5, 16);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);
    //celling

    a = transform(-2.5, 1.7, -6, 0, 0, 0, 10, 0.1, 16);
    cube.setMaterialisticProperty(glm::vec3(0.902, 0.624, 0.408));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);
}

void wall3(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    //floor
    glm::mat4 a = transform(-2.5, -.8, -6, 0, 0, 0, 10, 0.1, 16);
    cube.setMaterialisticProperty(glm::vec3(0.902, 0.624, 0.408));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    //1st wall

    a = transform(-2.5, -.8, -6, 0, 0, 0, 10, 5, 0.1);
    cube.setMaterialisticProperty(glm::vec3(0.89, 0.694, 0.694));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.2, 1.45, -5.97, 0, 0, 0, 8.8, .5, 0.8);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    //2nd wall
    a = transform(-2.5, -.8, 2, 0, 0, 0, 10, 5, 0.1);
    cube.setMaterialisticProperty(glm::vec3(0.89, 0.694, 0.694));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.1, 1.45, 1.6, 0, 0, 0, 8.8, 0.5, 0.8);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    //3rd wall
    a = transform(-2.5, -.8, -6, 0, 0, 0, .1, 5, 16);
    cube.setMaterialisticProperty(glm::vec3(0.941, 0.776, 0.761));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.5, 1.45, -6, 0, 0, 0, 0.8, 0.5, 16);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    //4th wall
    a = transform(2.5, -.8, -6, 0, 0, 0, .1, 5, 16);
    cube.setMaterialisticProperty(glm::vec3(0.988, 0.796, 0.78));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(2.1, 1.45, -6, 0, 0, 0, 0.8, 0.5, 16);
    cube.setMaterialisticProperty(glm::vec3(0.961, 0.596, 0.576));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);


}

void ladder(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    glm::mat4 a = transform(-2.0, -.8, -4, 0, 0, 0, .15, 5.3, .15);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);


    a = transform(-1.4, -.8, -4, 0, 0, 0, .15, 5.3, .15);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.0, -.4, -4, 0, 0, 0, 1.2, 0.15, .15);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.0, 0, -4, 0, 0, 0, 1.2, 0.15, .15);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.0, 0.4, -4, 0, 0, 0, 1.2, 0.15, .15);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.0, 0.8, -4, 0, 0, 0, 1.2, 0.15, .15);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.0, 1.2, -4, 0, 0, 0, 1.2, 0.15, .15);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform(-2.0, 1.6, -4, 0, 0, 0, 1.2, 0.15, .15);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);
}


void studytable(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(table_tex, table_tex, 32.0f);
    glm::mat4 a = transform(-2.0, -.8, -4, 0, 0, 0, 3.5, 2.75, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2.0, -.8, -4, 0, 0, 0, 0.1, 1.25, 1.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-0.3, -.8, -4, 0, 0, 0, 0.1, 1.25, 1.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-1.15, -.8, -4, 0, 0, 0, 0.1, 1.25, 1.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-1.15, -.5, -4, 0, 0, 0, 1.7, 0.1, 1.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform(-2, -.2, -4, 0, 0, 0, 3.5, 0.1, 1.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    //box
    cube.setTextureProperty(sofa_tex2, sofa_tex1, 32.0f);
    a = transform(-1.15+0.05, -.45, -4+shamne1, 0, 0, 0, 1.6, 0.5, 1.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

}

void chair(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(table_tex, table_tex, 32.0f);
    glm::mat4 a = transform2(-6, -2.6, -2.3, 0, 0, 0, 1, 0.1, 1.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-5.525, -2.55, -2.3, 0, 0, 90, 1, 0.1, 1.2);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform2(-5.525, -2.6, -2.3, 0, 0, 0, 0.05, 0.8, 0.05);
    cube.setMaterialisticProperty(glm::vec3(0, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform2(-5.525, -2.6, -2.3+0.575, 0, 0, 0, 0.05, 0.8, 0.05);
    cube.setMaterialisticProperty(glm::vec3(0, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform2(-6, -2.6, -2.3, 90, 0, 0, 0.05, 1.2, 0.05);
    cube.setMaterialisticProperty(glm::vec3(0, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform2(-5.525, -2.6, -2.3, 90, 0, 0, 0.05, 1.2, 0.05);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform2(-5.525, -2.2, -2.3, 90, 0, 0, 0.05, 1.2, 0.05);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);


    a = transform2(-5.525, -2.625, -2.3, 0, 0, 90, 0.05, 0.9, 0.05);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);


    a = transform2(-5.525, -2.625, -1.725, 0, 0, 90, 0.05, 0.9, 0.05);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);


    a = transform2(-6, -3.07, -2.3, 0, 0, 0, 0.05, 0.9, 0.05);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);


    a = transform2(-6, -3.07, -1.725, 0, 0, 0, 0.05, 0.9, 0.05);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform2(-5.525, -3.07, -2.3, 0, 0, 00, 0.05, 0.9, 0.05);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);


    a = transform2(-5.525, -3.07, -1.725, 0, 0, 0, 0.05, 0.9, 0.05);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);



}

void Ladder2(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 alTogether)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.77006, -0.75, 14.1102));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(10.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    ladder(cube, lightingShader, lightingShader2, alTogether * translateMatrix * rotateZMatrix);
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-10.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.77006, 0.62, 14.75));
    ladder(cube, lightingShader, lightingShader2, alTogether * translateMatrix * rotateZMatrix);

}


void bed(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    float baseHeight = 0.6;
    float width = 2.5;
    float length = 5;
    float pillowWidth = 0.3 * 3;
    float pillowLength = 0.15 * 4;
    float blanketWidth = 0.8;
    float blanketLength = 0.7;
    float headHeight = 0.6;

    //base
    cube.setTextureProperty(bed_frame, bed_frame, 32.0f);
    glm::mat4 a = transform(-6, -0.75, 0.6, 0, 0, 0, length, baseHeight, width);
    cube.drawCubeWithTexture(lightingShader, model * a);

    //foam
    cube.setTextureProperty(bedsheet, bedsheet, 32.0f);
    a = transform(-6, -0.45, 0.6, 0, 0, 0, length, baseHeight - 0.3, width);
    cube.drawCubeWithTexture(lightingShader, model * a);

    //pillow 1
    cube.setTextureProperty(pillow, pillow, 32.0f);
    a = transform(-5.9, -0.3, 0.7, 0, 0, 0, pillowLength, 0.1, pillowWidth);
    cube.drawCubeWithTexture(lightingShader, model * a);

    ////pillow 2
    a = transform(-5.9, -0.3, 1.3, 0, 0, 0, pillowLength, 0.1, pillowWidth);
    cube.drawCubeWithTexture(lightingShader, model * a);

    ////blanket
    //model = alTogether * translate2 * scale * translate;
    //drawCube(cubeVAO, lightingShader, model, 0.541, 0.169, 0.886);

    ////head
    cube.setTextureProperty(bed_frame, bed_frame, 32.0f);
    a = transform(-6.05, -0.75, 0.6, 0, 0, 0, 0.1, baseHeight + 0.9, width);
    cube.drawCubeWithTexture(lightingShader, model * a);

}

void doortonextroom(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    glm::mat4 a = transform(-2.45, -0.75, -4.5, 0, 90, 0, 2.0, 2.9, .1);
    cube.setMaterialisticProperty(glm::vec3(1, 0, 0));
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

}



void swing(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(shelf_tex, shelf_tex, 32.0f);
    glm::mat4 a = transform2(-1, -0.4, -2.0, 0.0, 0.0, 0.0, 2.4, 0.03, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-1, -0.4, -2.15, 0.0, 0.0, 0.0, 2.4, 0.03, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-1, -0.4, -2.30, 0.0, 0.0, 0.0, 2.4, 0.03, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-1, -0.4, -2.45, 0.0, 0.0, 0.0, 2.4, 0.03, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-1, -0.4, -2.60, 0.0, 0.0, 0.0, 2.4, 0.03, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.9, -0.415, -2.60, 0.0, 0.0, 0.0, 0.1, 0.03, 1.4);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.1, -0.415, -2.60, 0.0, 0.0, 0.0, 0.1, 0.03, 1.4);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.4, -0.415, -2.60, 0.0, 0.0, 0.0, 0.1, 0.03, 1.4);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform2(-0.9, -0.4, -2.5, 18.0, 0.0, 0.0, 0.02, 1.65, 0.02);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.9, -0.4, -2.01, -18.0, 0.0, 0.0, 0.02, 1.65, 0.02);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.1, -0.4, -2.5, 18.0, 0.0, 0.0, 0.02, 1.65, 0.02);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.1, -0.4, -2.01, -18.0, 0.0, 0.0, 0.02, 1.65, 0.02);
    cube.drawCubeWithTexture(lightingShader, model * a);



}

void swingframe(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{
    cube.setTextureProperty(shelf_tex, shelf_tex, 32.0f);
    glm::mat4 a = transform2(-1.15, -0.75, -2.6, 20.0, 0.0, 0.0, 0.1, 2.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-1.15, -0.75, -1.9, -20.0, 0.0, 0.0, 0.1, 2.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform2(0.3, -0.75, -2.6, 20.0, 0.0, 0.0, 0.1, 2.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.3, -0.75, -1.9, -20.0, 0.0, 0.0, 0.1, 2.5, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-1.2, 0.32, -2.25, -20.0, 0.0, 0.0, 3.2, 0.1, 0.1);
    cube.drawCubeWithTexture(lightingShader, model * a);


}


void waredrove(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model,unsigned int b)
{

    cube.setTextureProperty(b, b, 32.0f);
    glm::mat4 a = transform2(-0.3, -0.75, -2.5, 0, 0, 0, 2.0, 3, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.75, -2, 0, 90, 0, 1.0, 3, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.7, -0.75, -2, 0, 90, 0, 1.0, 3, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);
    
    a = transform2(-0.3, 0.75, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73+0.375, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73+0.75, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73 + 1.125, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);


    /////////////////////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + 0.05 + 0.05, -2.499 + shamne1w, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform2(-0.25, -0.73 + 0.33 - 0.05, +0.05 - 2.499 + shamne1w, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 + 0.05 - 0.05, -2.499 + shamne1w, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);
    /////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + 0.05 + 0.05 + 0.375, -2.499 + shamne2w, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25, -0.73 + 0.33 - 0.05 + 0.05 + 0.375, -2.499 + shamne2w, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 + 0.05 - 0.05 + 0.375, -2.499 + shamne2w, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    ///////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33 + 0.05 + 0.05 - 0.33 + 0.75, -2.499 + shamne3w, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25, -0.73 + 0.33 - 0.05 + 0.05 + 0.75, -2.499 + shamne3w, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 - 0.05 + 0.05 + 0.75, -2.499 + shamne3w, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);
    ////////////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33 + 0.05 - 0.33 + 1.125 + 0.05, -2.499 + shamne4w, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25, -0.73 + 0.33 - 0.05 + 1.125 + 0.05, -2.499 + shamne4w, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 - 0.05 + 0.05 + 1.125, -2.499 + shamne4w, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    cube.setTextureProperty(handle, handle, 32.0);
    ////
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + .3 + 0.05, -2.499 + 0.45 + shamne1w, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model * a);
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + .3 + 0.375 + 0.05, -2.499 + 0.45 + shamne2w, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model * a);
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + .3 + 0.75 + 0.05, -2.499 + 0.45 + shamne3w, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model * a);
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + 1.125 + .3 + 0.05, -2.499 + 0.45 + shamne4w, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model * a);

}

void bedsidetable(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{

    cube.setTextureProperty(bedframe, bedframe, 32.0f);
    glm::mat4 a = transform2(-0.3, -0.75, -2.5, 0, 0, 0, 2.0, 3, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.75, -2, 0, 90, 0, 1.0, 3, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.7, -0.75, -2, 0, 90, 0, 1.0, 3, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, 0.75, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73 + 0.375, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73 + 0.75, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73 + 1.125, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);


    /////////////////////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + 0.05 + 0.05, -2.499 + shamne1b, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform2(-0.25, -0.73 + 0.33 - 0.05, +0.05 - 2.499 + shamne1b, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 + 0.05 - 0.05, -2.499 + shamne1b, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);
    /////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + 0.05 + 0.05 + 0.375, -2.499 + shamne2b, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25, -0.73 + 0.33 - 0.05 + 0.05 + 0.375, -2.499 + shamne2b, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 + 0.05 - 0.05 + 0.375, -2.499 + shamne2b, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    ///////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33 + 0.05 + 0.05 - 0.33 + 0.75, -2.499 + shamne3b, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25, -0.73 + 0.33 - 0.05 + 0.05 + 0.75, -2.499 + shamne3b, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 - 0.05 + 0.05 + 0.75, -2.499 + shamne3b, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);
    ////////////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33 + 0.05 - 0.33 + 1.125 + 0.05, -2.499 + shamne4b, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25, -0.73 + 0.33 - 0.05 + 1.125 + 0.05, -2.499 + shamne4b, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 - 0.05 + 0.05 + 1.125, -2.499 + shamne4b, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    cube.setTextureProperty(handle, handle, 32.0);
    ////
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + .3 + 0.05, -2.499 + 0.45 + shamne1b, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model * a);
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + .3 + 0.375 + 0.05, -2.499 + 0.45 + shamne2b, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model * a);
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + .3 + 0.75 + 0.05, -2.499 + 0.45 + shamne3b, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model * a);
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + 1.125 + .3 + 0.05, -2.499 + 0.45 + shamne4b, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model * a);


}

void table2 (Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{

    cube.setTextureProperty(shelf_tex, shelf_tex, 32.0f);
    glm::mat4 a = transform2(-0.3, -0.75, -2.5, 0, 0, 0, 2.0, 3, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.75, -2, 0, 90, 0, 1.0, 3, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.7, -0.75, -2, 0, 90, 0, 1.0, 3, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, 0.75, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73, -2.5, 90, 0, 0, 2.1, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73 + 0.375, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73 + 0.75, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.3, -0.73 + 1.125, -2.5, 90, 0, 0, 2, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.7, -0.73 + .65 + 0.3, -2.5, 90, 0, 0, 5, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.7, -0.75+.45+ 0.3, -2.5, 0, 0, 0, 5.0, 0.14+0.225, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform2(-0.7+3.85, -0.8 + 0.5-0.5, -2, 0, 90, 0, 1, 2.1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.7, -0.73 + .45 + 0.3, -2.5, 90, 0, 0, 5, 1, .1);
    cube.drawCubeWithTexture(lightingShader, model * a);
    //mirror
    a = transform2(0.7, -0.75 + .65 + 0.3, -2.5, 0, 0, 0, 5.0, 2.3, 0.11);
    cube.drawCubeWithTexture(lightingShader, model * a);


    cube.setTextureProperty(mirror_tex, mirror_tex, 32.0f);
    a = transform2(0.8, -0.75 + .65 + 0.3, -2.42, 0, 0, 0, 4.6, 2.3, 0.01);
    cube.drawCubeWithTexture(lightingShader, model * a);
    
    //mirrorframe
    cube.setTextureProperty(shelf_tex, shelf_tex2, 32.0f);
    a = transform2(0.7, -0.75 + .65 + 0.3, -2.5, 0, 0, 0, 0.2, 2.3, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.7+2.4, -0.75 + .65 + 0.3, -2.5 , 0, 0, 0, 0.2, 2.3, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(0.7, -0.75 + .65+1.15 + 0.3, -2.5, 0, 0, 0, 5, 0.2, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);


    //drawers

    a = transform2(0.7, -0.75 + .45 + 0.3, -2.5+shamnet, 0, 0, 0, 5.0, 0.1, 0.9);
    cube.drawCubeWithTexture(lightingShader, model * a);
    a = transform2(0.7, -0.75 + .45 + 0.3, -2.5 + shamnet, 0, 0, 0, 0.2, 0.12 + 0.225, 0.9);
    cube.drawCubeWithTexture(lightingShader, model * a);
    a = transform2(0.7+2.4, -0.75 + .45 + 0.3, -2.5 + shamnet, 0, 0, 0, 0.2, 0.12 + 0.225, 0.9);
    cube.drawCubeWithTexture(lightingShader, model * a);



    /////////////////////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33-0.33 + 0.05 + 0.05, -2.499 + shamnet, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);


    a = transform2(-0.25, -0.73 + 0.33-0.05, +0.05 -2.499 + shamnet, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25+0.9, -0.73 + 0.33 + 0.05 - 0.05, -2.499 + shamnet, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);
    /////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + 0.05 + 0.05 +0.375, -2.499 + shamne2t, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25, -0.73 + 0.33 - 0.05 + 0.05 + 0.375, -2.499 + shamne2t, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 + 0.05 - 0.05 + 0.375, -2.499 + shamne2t, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    ///////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33 + 0.05 + 0.05 - 0.33 + 0.75, -2.499 + shamne3t, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25, -0.73 + 0.33 - 0.05 + 0.05 + 0.75, -2.499 + shamne3t, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 - 0.05 + 0.05 + 0.75, -2.499 + shamne3t, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);
    ////////////////////////////////////
    a = transform2(-0.25, -0.73 + 0.33+0.05 - 0.33+1.125+0.05, -2.499 + shamne4t, 90, 0, 0, 1.9, 0.9, 0.2);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25, -0.73 + 0.33 - 0.05 + 1.125 + 0.05, -2.499 + shamne4t, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    a = transform2(-0.25 + 0.9, -0.73 + 0.33 - 0.05 + 0.05 + 1.125, -2.499 + shamne4t, 90, 0, 0, 0.1, 0.9, 0.6);
    cube.drawCubeWithTexture(lightingShader, model * a);

    cube.setTextureProperty(handle, handle, 32.0);
    ////
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + .3 + 0.05, -2.499 + 0.45 + shamnet, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model* a);
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + .3 +0.375  + 0.05, -2.499 + 0.45 + shamne2t, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model* a);
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + .3 +0.75  + 0.05, -2.499 + 0.45 + shamne3t, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model* a);
    a = transform2(-0.25, -0.73 + 0.33 - 0.33 + 1.125+.3 + 0.05, -2.499 + 0.45 + shamne4t, 90, 0, 0, 1.9, 0.1, 0.7);
    cube.drawCubeWithTexture(lightingShader, model* a);


    a = transform2(0.7, -0.75 + .45 + 0.3, -2.5 + 0.45 + shamnet, 0, 0, 0, 5, 0.12 + 0.225, 0.1);
    cube.drawCubeWithTexture(lightingShader, model* a);

}

void fridge(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{

    cube.setMaterialisticProperty(glm::vec3(0.8, 0.792, 0.792));
    glm::mat4 a = transform2(0, 0, -2.5, 0, 0, 0, 1.8, 3.2, 0.1);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform2(0, 0, -2.5, 0, 0, 0, 0.1, 3.2, 1.8);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform2(0.9, 0, -2.5, 0, 0, 0, 0.1, 3.2, 1.8);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform2(0, 0, -2.5, 0, 0, 0, 1.8, 0.1, 1.8);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform2(0, 1.6, -2.5, 0, 0, 0, 1.9, 0.1, 1.8);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

    a = transform2(0, 1.1, -2.5, 0, 0, 0, 1.8, 0.1, 1.8);
    cube.drawCubeWithMaterialisticProperty(lightingShader2, model * a);

}

void fridgedoor(Cube& cube, Shader& lightingShader, Shader& lightingShader2, glm::mat4 model)
{

    cube.setMaterialisticProperty(glm::vec3(0.8, 0.792, 0.792));
    cube.setTextureProperty(fridge_door2, fridge_door2, 32.0f);
    glm::mat4 a = transform2(0, 0, -1.6, 0, -fridge_door_open, 0, 1.9, 2.2, 0.11);
     cube.drawCubeWithTexture(lightingShader, model * a);



    cube.setTextureProperty(fridge_door1, fridge_door1, 32.0f);
    a = transform2(0, 1.15, -1.6, 0, -fridge_door_open2, 0, 1.9, 1, 0.11);
    cube.drawCubeWithTexture(lightingShader, model * a);


}

void Key(Cube& cube,Curve &curve, Shader& lightingShader, Shader& lightingShader2, glm::mat4 alTogether)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));//,
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 0.2f, 0.5f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = rotateYMatrix * scaleMatrix * translateMatrix;
    cube.setMaterialisticProperty(glm::vec3(0.94f, 0.90f, 0.55f));
    cube.drawCubeWithMaterialisticProperty(lightingShader, alTogether * model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.85569, -0.0340001, 0.424998));//,
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.2f, 0.5f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = rotateYMatrix * scaleMatrix * translateMatrix;
    
    cube.drawCubeWithMaterialisticProperty(lightingShader, alTogether * model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0, 0, 0.3));
    model =  translateMatrix*model;
    cube.drawCubeWithMaterialisticProperty(lightingShader, alTogether * model);
    model = transform(0.1,-1.25,0, 0, 0, 0, 0.5, 0.8, 0.5);
    curve.draw(lightingShader2, alTogether*model, glm::vec3(0.3f, 1.0f, 1.0f));
    
}


int main()
{

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "CSE 4208: Computer Graphics Laboratory", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    
    Shader lightingShaderWithTexture("vertexShaderForPhongShadingWithTexture.vs", "fragmentShaderForPhongShadingWithTexture.fs");
    Shader lightingShader("vertexShaderForPhongShading.vs", "fragmentShaderForPhongShading.fs");
    Shader ourShader("vertexShader.vs", "fragmentShader.fs");

    string diffuseMapPath = "container2.png";
    string specularMapPath = "container2_specular.png";
    string f_tiles = "floor_tiles.jpg";
    string wood = "wood.png";

    unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    sofa_tex1 = loadTexture("sofatex1.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    sofa_tex2 = loadTexture("sofatex2.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    wood_tex = loadTexture(wood.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    blacktex = loadTexture("black.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    shelf_tex = loadTexture("shelf.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    //shelf_tex2 = loadTexture("shelf2.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    showcase_tex = loadTexture("showcasered.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    showcase_door = loadTexture("showcasedoor.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    floor_tex = loadTexture("floor.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    painting_tex = loadTexture("painting.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    painting_tex2 = loadTexture("painting2.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    painting_tex3 = loadTexture("painting3.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    bed_frame = loadTexture("bed_frame_wood.png", GL_REPEAT, GL_REPEAT, 6, 2);
    bedframe = loadTexture("bedframe.jpeg", GL_REPEAT, GL_REPEAT, 6, 2);
    bedsheet = loadTexture("bedsheet.jpeg", GL_REPEAT, GL_REPEAT, 6, 2);
    pillow = loadTexture("cushion.jpg", GL_REPEAT, GL_REPEAT, 6, 2);
    table_tex = loadTexture("table wood.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    brick_wood = loadTexture("brick_wood.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    bed_sofa = loadTexture("bedsofa.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    mirror_tex = loadTexture("mirror.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    rug_tex = loadTexture("rug.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    fridge_door1 = loadTexture("fridge_door1.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    fridge_door2 = loadTexture("fridge_door2.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    white1 = loadTexture("whiteBackground.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    handle = loadTexture("handle.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    drawerinside = loadTexture("drawer_inside.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    firstdig = loadTexture(fdigits.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    secdic = loadTexture(fdigits.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    thirdig = loadTexture(fdigits.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int gold = loadTexture("gold.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int glass = loadTexture("glass.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int water = loadTexture("water.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube tiles_cube = Cube(floor_tex, floor_tex, 32.0, 0.0f, 0.0f, 20.0f, 20.0f);
    Curve Vase1(Vase, painting_tex, painting_tex, 1.0f);

    Curve Vase22(Vase2, white1, white1, 1.0f);
    Curve Vase33(Vase3, painting_tex, painting_tex, 1.0f);
    Curve Vase44(Vase4, white1, white1, 1.0f);
    Curve Vase55(Vase5, white1, white1, 1.0f);
    Curve bowl(Bowl, white1,white1, 1.0f);
    Curve Glass(glassp, glass, glass, 1.0f);
    Curve circle(Circle, water, water, 1.0f);
    Curve tableleg(Tableleg, water, water, 1.0f);
    Curve Table1(Table, painting_tex, painting_tex, 1.0f);
    Curve Table2(Table, gold, gold, 1.0f);
    //Sphere sphere = Sphere();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    pointlight1.turnOff();
    pointlight1.turnSpecularOff();
    pointlight2.turnSpecularOff();
    dirlight.turnSpecularOff();
    spotlight.turnSpecularOff();


    mt19937 rng(random_device{}());

    // Define the range of the random numbers
    uniform_int_distribution<std::mt19937::result_type> dist(1, 4);

    // Generate a random number
    int randomNumber = dist(rng);

     start_time = glfwGetTime();
    cout << start_time << endl;
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        current_time = glfwGetTime();
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // be sure to activate shader when setting uniforms/drawing objects
        lightingShaderWithTexture.use();
        lightingShaderWithTexture.setVec3("viewPos", camera.Position);

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        lightingShaderWithTexture.setMat4("projection", projection);
        
        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        //glm::mat4 view = basic_camera.createViewMatrix();
        lightingShaderWithTexture.setMat4("view", view);
       
        pointlight1.setUpPointLight(lightingShaderWithTexture);
        pointlight2.setUpPointLight(lightingShaderWithTexture);
        dirlight.setUpPointLight(lightingShaderWithTexture);
        spotlight.setUpPointLight(lightingShaderWithTexture);

        // Modelling Transformation
        glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(2.42, 0.11, 8.18f));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix;

        cube.setTextureProperty(diffMap, specMap, 32.0f);
        cube.drawCubeWithTexture(lightingShaderWithTexture, model);

        

 







        model = transform(-10.2, 0, 2.8, 0, 180, 0, 1.2, 1, 1.6);
        bed(cube, lightingShaderWithTexture, lightingShader, model);

        //fridge
        model = transform2(-5, -3.25, -4, 0, -90, 0, 1, 1, 1);
        fridge(cube, lightingShaderWithTexture, lightingShader, model);
        fridgedoor(cube, lightingShaderWithTexture, lightingShader, model);

        //rug
        tiles_cube.setTextureProperty(rug_tex, rug_tex, 32.0);
        model = transform2(-6.3, -0.75, -3, 0, 0, 0, 4.5, 0.06, 4.5);
        tiles_cube.drawCubeWithTexture(lightingShaderWithTexture, model);


        //room1_wall
        model = transform(0, 0, 0, 0, 0, 0, 1, 1, 1);
        wall(cube,tiles_cube, lightingShaderWithTexture, lightingShader, model);

        //room2_wall
        model = transform(-5.0, 0, 0, 0, 0, 0, 1, 1, 1);
        wall2(cube, tiles_cube, lightingShaderWithTexture, lightingShader, model);

        //room3_wall
        model = transform(-5.0, -2.5, 0, 0, 0, 0, 1, 1, 1);
        wall3(cube, lightingShaderWithTexture, lightingShader, model);

        //sofa
        model = transform(-3.3, -0.1, -0.5, 0, -90, 0, 0.8, 1, 1);
        Sofa(cube, lightingShaderWithTexture, lightingShader, model);

        model = transform(-1.8, -0.1, -1.4, 0, -130, 0, 0.5, 1, 0.8);
        Sofa(cube, lightingShaderWithTexture, lightingShader, model);

        model = transform(-2.0, -0.1, 0.6, 0, 310, 0, 0.5, 1, 0.8);
        Sofa(cube, lightingShaderWithTexture, lightingShader, model);

        model = transform(-8.5, -0.1, -2, 0, -90, 0, 0.8, 1, 1);
        bedSofa(cube, lightingShaderWithTexture, lightingShader, model);

        // Vase //////////////////////////////////////////////////////////////////////
        //model = transform(-4 - 0.2, -0.3, -2, 0, 0, 0, 0.2, 0.2, 0.2);
        //Vase1.draw(lightingShaderWithTexture,  model, glm::vec3(1.0f, 1.0f, 1.0f));

        //model = transform(-4 - 0.2 - 0.2, -0.3, -2, 0, 0, 0, 0.2, 0.2, 0.2);
        //Vase22.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));

        //model = transform(-4, -0.25, -0.6, 0, 0, 0, 0.2, 0.2, 0.2);
        //Vase33.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));


        //model = transform2(-4 - 0.2 - 0.2 - 0.2 - 0.2, -0.3, -2, 180, 0, 0, 0.2, 0.2, 0.2);
        //Vase44.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));

        //model = transform(-4 - 0.2 - 0.2 - 0.2 - 0.2 - 0.2, -0.3, -2, 0, 0, 0, 0.2, 0.2, 0.2);
        //Vase55.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));



        //////////////////////////////////glass///////////////////////////////////////////
        model = transform(-5.2, -0.22, -2, 0, 0, 0, 0.05, 0.13, 0.05);
        circle.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));




        model = transform(-5.2, -0.22 +0.28, -2, 180, 0, 0, 0.1, 0.13, 0.1);
        Glass.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));





        ////////////////////////////////table///////////////////////////////

        model = transform(-5.2, -1.2, -2, 0, 0, 0, 1, 0.6, 1);
        Table1.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));
       
        
        model = transform(-5.2, -0.7, -1.6, -30, 0, 0, 0.4, 0.3, 0.4);
        tableleg.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));

        model = transform(-5.2, -0.7, -2.4, 30, 0, 0, 0.4, 0.3, 0.4);
        tableleg.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));


        model = transform(-5.6, -0.7, -2, 0, 0, -30, 0.4, 0.3, 0.4);
        tableleg.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));

        model = transform(-4.8, -0.7, -2, 0, 0, 30, 0.4, 0.3, 0.4);
        tableleg.draw(lightingShaderWithTexture, model, glm::vec3(1.0f, 1.0f, 1.0f));



        ////Mat
        glm::mat4 a = transform(.7, -.8, -1.2, 0, -90, 0, 3, 0.2, 2);
        //cube.setMaterialisticProperty(glm::vec3(0.89, 0.694, 0.694)); 
        //cube.drawCubeWithMaterialisticProperty(lightingShader, model* a);

        //table
        model = transform(5.0, -0.2, -0.5, 0, 90, 0, 1.5, 1, 1.3);
        table(cube, lightingShaderWithTexture, lightingShader, model);
        a = transform(-2.45, -.4, 1.0, 0, 90, 0, 4.5, 2.2, 0.1);
        if (atoggle)
        {
            anim = (anim == MAX_ANIM_VALUE) ? 0 : ++anim;
            string s = "aquarium/giphy-" + to_string(anim) + ".png";
            aquarium = loadTexture(s.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

             //tv
            cube.setTextureProperty(aquarium, aquarium, 32);

            cube.drawCubeWithTexture(lightingShaderWithTexture, a);
        }
        else
        {
        cube.setMaterialisticProperty(glm::vec3(0, 0, 0));
        cube.drawCubeWithMaterialisticProperty(lightingShader, a);

        }

        /////////////////////////////////////////////////////////////KEY//////////////////////////////////////////////////////////////////////////////
        







        if (randomNumber == 1)
        {
            a = transform2(1.759, -.7, -1.204, 0, 0, 0, 0.2, 0.2, 0.2);
            Key(cube, Table2, lightingShader, lightingShaderWithTexture, a);

            if (abs(camera.Position[0] - (1.819)) < 0.5 && abs(camera.Position[1] - (-.528)) < 1 && abs(camera.Position[2] - (-1.478)) < 0.5&&keypick)
            {
                deltaTime = 0;
                break;
            }
        }
        else if (randomNumber == 2)
        {
            a = transform2(-7, -.2, 1.65 - shamne2w, 0, 0, 0, 0.2, 0.2, 0.2);
            Key(cube, Table2, lightingShader, lightingShaderWithTexture, a);
            if (abs(camera.Position[0] - (-6.926)) < 0.5 && abs(camera.Position[1] - (0.086)) < 2 && abs(camera.Position[2] - (1.142)) < 0.5 && keypick)
            {
                cout << "picked 2" << endl;
                deltaTime = 0;
                break;
            }
        }
        else if (randomNumber == 3)
        {
            a = transform2(-3.3, -2.1, -3.2 - shamne2w, 0, 0, 0, 0.2, 0.2, 0.2);
            Key(cube, Table2, lightingShader, lightingShaderWithTexture, a);
            if (abs(camera.Position[0] - (-3.503)) < 0.5 && abs(camera.Position[1] - (-1.877)) < 2 && abs(camera.Position[2] - (-3.547)) < 0.5 && keypick)
            {
                cout << "picked 3" << endl;
                deltaTime = 0;
                break;
            }
        }
        else
        {
            a = transform2(-2.8, -3.23, 1.9 - shamne2w, 0, 0, 0, 0.2, 0.2, 0.2);
            Key(cube, Table2, lightingShader, lightingShaderWithTexture, a);
            if (abs(camera.Position[0] - (-2.773)) < 0.5 && abs(camera.Position[1] - (-3.083)) < 2 && abs(camera.Position[2] - (1.310)) < 0.5 && keypick)
            {
                cout << "picked 4" << endl;
                break;
            }
        }

        //painting
        cube.setTextureProperty(painting_tex3, painting_tex3, 32.0);
        a = transform(-0.35, 0.2, 1.9, 0, 00, 0, 1.4, 1.8, 0.02);
        cube.drawCubeWithTexture(lightingShaderWithTexture, a);

        //painting2
        cube.setTextureProperty(painting_tex2, painting_tex2, 32.0);
        a = transform(0.4, -.0, 1.9, 0, 00, 0, 1.4, 1.8, 0.02);
        cube.drawCubeWithTexture(lightingShaderWithTexture, a);

        //painting3
        cube.setTextureProperty(painting_tex, painting_tex, 32.0);
        a = transform(-1.1, -.0, 1.9, 0, 00, 0, 1.4, 1.8, 0.02);
        cube.drawCubeWithTexture(lightingShaderWithTexture, a);


        //shelf
        model = transform(0, 0, -1, 0, 0, 0, 1, 1, 1);
        shelf(cube, lightingShaderWithTexture, lightingShader, model);


        //waredrove
        model = transform(-6.5, 0, -0.7, 0, 180, 0, 1, 1, 1);
        waredrove(cube, lightingShaderWithTexture, lightingShader, model,brick_wood);

       
        /////////////////bottom box//////////////////////////////////////
        if (tabler1)
        {
            if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
            {
                shamnet += 0.005;
                shamnet = min(shamnet + 0.0, 0.4);
            }

        }
        else 
        {
            if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
            {
                shamnet -= 0.005;

                shamnet = max(shamnet + 0.0, 0.0);
            }
        }


        if (warer1)
        {
            if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
            {
                shamne1w += 0.005;
                shamne1w = min(shamne1w + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
            {
                shamne1w -= 0.005;

                shamne1w = max(shamne1w + 0.0, 0.0);
            }
        }

        if (beder1)
        {
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                shamne1b += 0.005;
                shamne1b = min(shamne1b + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                shamne1b -= 0.005;

                shamne1b = max(shamne1b + 0.0, 0.0);
            }
        }




        if (tabler2)
        {
            if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
            {
                shamne2t += 0.005;
                shamne2t = min(shamne2t + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
            {
                shamne2t -= 0.005;

                shamne2t = max(shamne2t + 0.0, 0.0);
            }
        }


        if (warer2)
        {
            if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
            {
                shamne2w += 0.005;
                shamne2w = min(shamne2w + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
            {
                shamne2w -= 0.005;

                shamne2w = max(shamne2w + 0.0, 0.0);
            }
        }

        if (beder2)
        {
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                shamne2b += 0.005;
                shamne2b = min(shamne2b + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                shamne2b -= 0.005;

                shamne2b = max(shamne2b + 0.0, 0.0);
            }
        }

        if(box)
        {

            for (int i = 0; i < 10; i++)
            {
                fridge_door_open += 0.1;
                fridge_door_open = min(fridge_door_open+0.0, 120.0);
            }
        }
        else
        {
            for (int i = 0; i<10; i++)
            {
                fridge_door_open -= 0.1;
                fridge_door_open = max(fridge_door_open + 0.0, 0.0);
            }
        }

        if (box2)
        {

            for (int i = 0; i < 10; i++)
            {
                fridge_door_open2 += 0.1;
                fridge_door_open2 = min(fridge_door_open2 + 0.0, 120.0);
            }
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                fridge_door_open2 -= 0.1;
                fridge_door_open2 = max(fridge_door_open2 + 0.0, 0.0);
            }
        }



        if (tabler2)
        {
            if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
            {
                shamne2t += 0.005;
                shamne2t = min(shamne2t + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
            {
                shamne2t -= 0.005;

                shamne2t = max(shamne2t + 0.0, 0.0);
            }
        }


        if (warer2)
        {
            if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
            {
                shamne2w += 0.005;
                shamne2w = min(shamne2w + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
            {
                shamne2w -= 0.005;

                shamne2w = max(shamne2w + 0.0, 0.0);
            }
        }

        if (beder2)
        {
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                shamne2b += 0.005;
                shamne2b = min(shamne2b + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                shamne2b -= 0.005;

                shamne2b = max(shamne2b + 0.0, 0.0);
            }
        }

        
        

        if (tabler3)
        {
            if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
            {
                shamne3t += 0.005;
                shamne3t = min(shamne3t + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
            {
                shamne3t -= 0.005;

                shamne3t = max(shamne3t + 0.0, 0.0);
            }
        }


        if (warer3)
        {
            if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
            {
                shamne3w += 0.005;
                shamne3w = min(shamne3w + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
            {
                shamne3w -= 0.005;

                shamne3w = max(shamne3w + 0.0, 0.0);
            }
        }

        if (beder3)
        {
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                shamne3b += 0.005;
                shamne3b = min(shamne3b + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                shamne3b -= 0.005;

                shamne3b = max(shamne3b + 0.0, 0.0);
            }
        }


        if (tabler4)
        {
            if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
            {
                shamne4t += 0.005;
                shamne4t = min(shamne4t + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
            {
                shamne4t -= 0.005;

                shamne4t = max(shamne4t + 0.0, 0.0);
            }
        }


        if (warer4)
        {
            if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
            {
                shamne4w += 0.005;
                shamne4w = min(shamne4w + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
            {
                shamne4w -= 0.005;

                shamne4w = max(shamne4w + 0.0, 0.0);
            }
        }

        if (beder4)
        {
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                shamne4b += 0.005;
                shamne4b = min(shamne4b + 0.0, 0.4);
            }

        }
        else
        {
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                shamne4b -= 0.005;

                shamne4b = max(shamne4b + 0.0, 0.0);
            }
        }


        //bed_side_table
        model = transform(-4.15, -.45, -0.6, 0, -90, 0, 0.35, 0.4, 0.5);
        bedsidetable(cube, lightingShaderWithTexture, lightingShader, model);

        //door to next room
        if (!doortonext)
        {
            model = transform(0, 0, min(slide,1.0f), 0, 0, 0, 1, 1, 1);
            doortonextroom(cube, lightingShaderWithTexture, lightingShader, model);
        }



        //book
        float r = 0, g = 0, b = 0, x = 0;
        for (int i = 0; i < 7; i++)
        {
            r += 0.2, g += 0.1, b += 0.3;
            model = transform(0, 0, x, 0, 0, 0, 1, 1, 1);
            book(cube, lightingShaderWithTexture, lightingShader, model,r,g,b);
            x += 0.1;
        }
        r = 0, g = 0, b = 0, x = 0;
        for (int i = 0; i < 7; i++)
        {
            r += 0.3, g += 0.2, b += 0.1;
            model = transform(0, -0.9, -0.9 - x, 50, 0, 0, 1, 1, 0.7);
            book(cube, lightingShaderWithTexture, lightingShader, model, r, g, b);
            x += 0.1;
        }
        r = 0, g = 0, b = 0, x = 0;
        for (int i = 0; i < 7; i++)
        {
            r += 0.1, g += 0.2, b += 0.3;
            model = transform(0, -2, -0.9 - x, 50, 0, 0, 1, 1, 0.7);
            book(cube, lightingShaderWithTexture, lightingShader, model, r, g, b);
            x += 0.1;
        }

        //showcase
        model = transform(-5, 0, -3, 0, -90, 0, 1, 1, 3.5);
        showcase(cube, lightingShaderWithTexture, lightingShader, model);


        if (dooropen)
        {
            a = transform(-6.5, 0, -3.5, 0, -90, 0, 1, 1, 1);
            dooropenclose(cube, lightingShaderWithTexture, lightingShader, a*model);
            a = transform(6.5, 0, -3.5, 0, 90, 0, 1, 1, 1);
            dooropenclose2(cube, lightingShaderWithTexture, lightingShader, a*model);

        }
        else
        {

            dooropenclose(cube, lightingShaderWithTexture, lightingShader, model);
            dooropenclose2(cube, lightingShaderWithTexture, lightingShader, model);
        }

        //FAN
        model = transform(-0.1, 1, 0.5, 0, rotate_fan, 0, 0.7, 1, 1);
        Fan(cube, lightingShaderWithTexture, lightingShader, model);
        rotate_fan = rotate_fan + rotatedegree;
        a = transform(-.1, 1.1, 0.5, 0, 0, 0, 0.2, 1.3, 0.2);
        cube.setMaterialisticProperty(glm::vec3(0.451, 0.208, 0.012));
        cube.drawCubeWithMaterialisticProperty(lightingShader,  a);

        //ladder
        model = transform(-4.95, -3.85, -1.43, 20, 0, 0, 1, 1, 1);
        ladder(cube, lightingShaderWithTexture, lightingShader, model);


        //ladder2
        model = transform2(-4.5+ladderx, -0.3, -10+ladderz, 0, 0, 0, 0.7, 0.5, 0.7);
        Ladder2(cube, lightingShaderWithTexture, lightingShader, model);

        
       // //table

        model = transform2(-4.3 , -0.2, -1, 0, 90, 0, 0.4, 0.7, 1.2);
        table2(cube, lightingShaderWithTexture, lightingShader, model);


        //study table
        model = transform(-3.15, -2.44, -3.5, 0, 90, 0, 1, 1, 1);
        studytable(cube, lightingShaderWithTexture, lightingShader, model);

        //chair
        model = transform2(-0.9, -.2, 0.05, 0, 0, 0, 1, 1, 1);
        chair(cube,lightingShaderWithTexture,lightingShader,model);

        //

















        int numb = 120 - (current_time - start_time);
        int i=1;
        if ((current_time - start_time) > i){
            i++;
           // engine->play2D("beep.wav");
            }


        if (numb == 0)
        {
            cout << "------------------------------------------------Game Over------------------------------------------------" << endl;
            cout << "------------------------------------------------You Lost------------------------------------------------" << endl;
            //break;
        }
        int firstDigit = numb / 100;  
        int secondDigit = (numb / 10) % 10; 
        int thirdDigit = numb % 10;  
        string s1= to_string(firstDigit) + ".png";

        firstdig = loadTexture(s1.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
        string s2 = to_string(secondDigit) + ".png";
        secdic = loadTexture(s2.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
        string s3 = to_string(thirdDigit) + ".png";
        thirdig = loadTexture(s3.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
        cube.setTextureProperty(firstdig, firstdig, 32);
        model = transform2(camera.Position[0] + camera.Front[0], camera.Position[1] + camera.Front[1], camera.Position[2] + camera.Front[2] - 2, 0, 0, 0, 0.7, 1, 0.1);
         cube.drawCubeWithTexture(lightingShaderWithTexture, model);
        
         cube.setTextureProperty(secdic, secdic, 32);
         model = transform2(camera.Position[0] + camera.Front[0]+0.35, camera.Position[1] + camera.Front[1], camera.Position[2] + camera.Front[2] - 2, 0, 0, 0, 0.7, 1, 0.1);
         cube.drawCubeWithTexture(lightingShaderWithTexture, model);


         cube.setTextureProperty(thirdig, thirdig, 32);
         model = transform2(camera.Position[0] +0.7+ camera.Front[0], camera.Position[1] + camera.Front[1], camera.Position[2] + camera.Front[2] - 2, 0, 0, 0, 0.7, 1, 0.1);
         cube.drawCubeWithTexture(lightingShaderWithTexture, model);































       // //showcase 2

        model = transform(1.4, -2.4, -0.6, 0, 90, 0, 1, 1.1, 4.5);
        showcase2(cube, lightingShaderWithTexture, lightingShader, model);
        if(swing_toogle)
        {
        swing_angle = min(swing_angle, 10.0f);

        if (is_increasing) {
            swing_angle += 1.0f/10;
            swing_translate -= 0.036/10;
            swing_translatez -= 0.005 / 10;
            if (swing_angle >= 10.0f) {
                is_increasing = false;
            }
        }
        else {
            swing_angle -= 1.0f / 10;
            swing_translate += 0.036 / 10;
            swing_translatez += 0.005 / 10;
            if (swing_angle <= -10.0f) {
                is_increasing = true;
            }
        }
        }

       // //swing

        model = transform2(-3.5, -0.1+swing_translate, -2.52 - 0.5 +swing_translatez, swing_angle, 0, 0, 0.9, 0.9, 0.9);
        swing(cube, lightingShaderWithTexture, lightingShader, model);

       // 



       // //swing frame
        model = transform2(-3.5, -0.1, -2.5-0.5, 0, 0, 0, 0.9, 0.9, 0.9);
        swingframe(cube, lightingShaderWithTexture, lightingShader, model);


        lightingShader.use();
        lightingShader.setMat4("projection", projection);
        lightingShader.setMat4("view", view);
        
        

        pointlight1.setUpPointLight(lightingShader);
        pointlight2.setUpPointLight(lightingShader);
        dirlight.setUpPointLight(lightingShader);
        spotlight.setUpPointLight(lightingShader);

        glm::mat4 modelMatrixForContainer = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0, 0.065, 4.86783));
        
       // Table(cube, lightingShader, translateMatrix);


        

        // also draw the lamp object(s)
        
        ourShader.use();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);
        glm::vec3 LightColor[] = {
        glm::vec3(0.8f, 0.8f, 0.8f),// White - Dir
        glm::vec3(1.0f,  0.0f,  0.0f),//Red - Spot Light
        glm::vec3(0.0f,  1.0f,  0.0f),//Green - Point Light 1
        glm::vec3(0.0f,  0.0f,  1.0f)//Blue - Point Light 1
        };

        for (unsigned int i = 0; i < 4; i++)
        {
            model = glm::mat4(1.0f);
            model = glm::translate(model, LightPositions[i]);
            model = glm::scale(model, glm::vec3(0.5f)); // Make it a smaller cube
            cube.drawCube(ourShader, model);
        }
        
        
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------


    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    engine->drop();
    return 0;
}
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        //glm::vec3 pos = camera.GetPosition();
        //camera.ProcessKeyboard(FORWARD, deltaTime);

        if (abs(camera.Position[0] - (-6.534)) < 0.8 && abs(camera.Position[2] - (-5.133)) < 0.6 && camera.Position[1] > -2.6 && camera.Position[2] > -5.65&&camera.Front[2]<0)
        {
            camera.ProcessKeyboard(DOWN, deltaTime);
            camera.ProcessKeyboard(FORWARD, deltaTime*1.3);
        }
        else if (abs(camera.Position[0] - (-0.845+ladderx)) < 0.4 && abs(camera.Position[2] - (-2.862+ladderz)) < 1&&fl)
        {
            if(camera.Position[1]<1.3)
            {
            camera.ProcessKeyboard(UP, deltaTime);
            camera.ProcessKeyboard(FORWARD, deltaTime/2 );
            }

        }
        else if (abs(camera.Position[0] - (-6.534)) < 0.8 && abs(camera.Position[2] - (-5.133)) < 0.6 && camera.Position[1] < 0.15 && camera.Front[2] >0)
        {
            camera.ProcessKeyboard(UP, deltaTime );
            camera.ProcessKeyboard(FORWARD, deltaTime*1.3);
        }
        else {
            camera.ProcessKeyboard(FORWARD, deltaTime);
        }

    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        if (abs(camera.Position[0] - (-0.845 + ladderx)) < 0.4 && abs(camera.Position[2] - (-2.862 + ladderz)) < 1&&fl)
        {
        if (camera.Position[1] > -0.1)
        {
            camera.ProcessKeyboard(DOWN, deltaTime);
            camera.ProcessKeyboard(FORWARD, deltaTime / 2);

        }
        }
        else
        {
            camera.ProcessKeyboard(BACKWARD, deltaTime);
        }

    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        camera.ProcessKeyboard(UP, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        camera.ProcessKeyboard(DOWN, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
        camera.ProcessKeyboard(P_UP, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
        camera.ProcessKeyboard(P_DOWN, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
        camera.ProcessKeyboard(Y_LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) {
        camera.ProcessKeyboard(Y_RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
        camera.ProcessKeyboard(R_LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        camera.ProcessKeyboard(R_RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
        rotatedegree += 2.0;
        if (rotatedegree == 6.0)
        {
            rotatedegree = 0.0;
            rotate_fan = 0.0;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
        if (!rotate_around) {
            rotate_around = true;
        }
        else {
            rotate_around = false;
        }
    }



}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_1 && action == GLFW_PRESS)
    {
        if (dirLightOn)
        {
            dirlight.turnOff();
            dirLightOn = !dirLightOn;
        }
        else
        {
            dirlight.turnOn();
            dirLightOn = !dirLightOn;
        }
    }
    if (key == GLFW_KEY_2 && action == GLFW_PRESS)
    {
        if (pointLightOn1)
        {
            pointlight1.turnOff();
            pointLightOn1 = !pointLightOn1;
        }
        else
        {
            pointlight1.turnOn();
            pointLightOn1 = !pointLightOn1;
        }
    }
    if (key == GLFW_KEY_3 && action == GLFW_PRESS)
    {
        if (pointLightOn2)
        {
            pointlight2.turnOff();
            pointLightOn2 = !pointLightOn2;
        }
        else
        {
            pointlight2.turnOn();
            pointLightOn2 = !pointLightOn2;
        }
    }
    if (key == GLFW_KEY_4 && action == GLFW_PRESS)
    {
        if (spotLightOn)
        {
            spotlight.turnOff();
            spotLightOn = !spotLightOn;
        }
        else
        {
            spotlight.turnOn();
            spotLightOn = !spotLightOn;
        }
    }
    if (key == GLFW_KEY_5 && action == GLFW_PRESS)
    {
        if (ambientToggle)
        {
            if (pointLightOn1)
                pointlight1.turnAmbientOff();
            if (pointLightOn2)
                pointlight2.turnAmbientOff();
            spotlight.turnAmbientOff();
            if (dirLightOn)
                dirlight.turnAmbientOff();
            ambientToggle = !ambientToggle;
        }
        else
        {
            if (pointLightOn1)
                pointlight1.turnAmbientOn();
            if (pointLightOn2)
                pointlight2.turnAmbientOn();
            if (spotLightOn)
                spotlight.turnAmbientOn();
            if (dirLightOn)
                dirlight.turnAmbientOn();
            ambientToggle = !ambientToggle;
        }
    }
    if (key == GLFW_KEY_6 && action == GLFW_PRESS)
    {
        if (diffuseToggle)
        {
            if (pointLightOn1)
                pointlight1.turnDiffuseOff();
            if (pointLightOn2)
                pointlight2.turnDiffuseOff();
            if (dirLightOn)
                dirlight.turnDiffuseOff();
            if (spotLightOn)
                spotlight.turnDiffuseOff();
            diffuseToggle = !diffuseToggle;
        }
        else
        {
            if (pointLightOn1)
                pointlight1.turnDiffuseOn();
            if (pointLightOn2)
                pointlight2.turnDiffuseOn();
            if (dirLightOn)
                dirlight.turnDiffuseOn();
            if (spotLightOn)
                spotlight.turnDiffuseOn();
            diffuseToggle = !diffuseToggle;
        }
    }
    if (key == GLFW_KEY_7 && action == GLFW_PRESS)
    {
       // engine->play2D("footstep.wav");
        if (specularToggle)
        {
            if (pointLightOn1)
                pointlight1.turnSpecularOff();
            if (pointLightOn2)
                pointlight2.turnSpecularOff();
            if (dirLightOn)
                dirlight.turnSpecularOff();
            if (spotLightOn)
                spotlight.turnSpecularOff();
            specularToggle = !specularToggle;
        }
        else
        {
            if (pointLightOn1)
                pointlight1.turnSpecularOn();
            if (pointLightOn2)
                pointlight2.turnSpecularOn();
            if (dirLightOn)
                dirlight.turnSpecularOn();
            if (spotLightOn)
                spotlight.turnSpecularOn();
            specularToggle = !specularToggle;
        }
    }
    if (key == GLFW_KEY_8 && action == GLFW_PRESS)
    {
        camera.printcamera();
    }

    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    {

        if (abs(camera.Position[0] - (-0.080)) < 2 && abs(camera.Position[1] - (0.343)) < 2 && abs(camera.Position[2] - (-3.482)) < 1)
        {
            if (!dooropen) {
                dooropen = true;
            }
            else {
                dooropen = false;
            }
        }

        if (abs(camera.Position[0] - (-3.865)) < 1 && abs(camera.Position[1] - (0.139)) < 2 && abs(camera.Position[2] - (-3.768)) < 1)
        {
            swing_angle = 0;
            swing_translate = 0;
            swing_translatez = 0;
            if (!swing_toogle) {
                swing_toogle = true;
            }
            else {
                swing_toogle = false;
            }
        }

        if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
        {
            if (!tabler1) {

                tabler1 = true;
            }
            else {
                tabler1 = false;
            }
        }
        if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
        {
            if (!warer1) {

                warer1 = true;
            }
            else {
                warer1 = false;
            }
        }
        if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
        {
            if (!beder1) {

                beder1 = true;
            }
            else {
                beder1 = false;
            }
        }
        if (abs(camera.Position[0] - (-4.153)) < 0.7 && abs(camera.Position[1] - (-2.096)) < 2 && abs(camera.Position[2] - (-3.446)) < 1)
        {
            if (!box) {

                box = true;
            }
            else {
                box = false;
            }
        }
    }


    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    {
        if (abs(camera.Position[0] - (-4.153)) < 0.7 && abs(camera.Position[1] - (-2.096)) < 2 && abs(camera.Position[2] - (-3.446)) < 1)
        {
            if (!box2) {

                box2 = true;
            }
            else {
                box2 = false;
            }
        }
        if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
        {
            if (!tabler2) {

                tabler2 = true;
            }
            else 
            {
                tabler2 = false;
            }
        }
        if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
        {
             if (!warer2) 
             {

                    warer2 = true;
             }
             else
             {
                    warer2 = false;
             }
        }
            if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
            {
                if (!beder2) 
                {

                    beder2 = true;
                }
                else 
                {
                    beder2 = false;
                }
            }
        
    }

    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
    {
        if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
        {
            if (!tabler3) {

                tabler3 = true;
            }
            else
            {
                tabler3 = false;
            }
        }
        if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
        {
            if (!warer3)
            {

                warer3 = true;
            }
            else
            {
                warer3 = false;
            }
        }
        if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
        {
            if (!beder3)
            {

                beder3 = true;
            }
            else
            {
                beder3 = false;
            }
        }
    }

    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    {
        if (abs(camera.Position[0] - (-6.539)) < 0.7 && abs(camera.Position[1] - (0.000)) < 2 && abs(camera.Position[2] - (-1.298)) < 1)
        {
            if (!tabler4) {

                tabler4 = true;
            }
            else
            {
                tabler4 = false;
            }
        }
        if (abs(camera.Position[0] - (-6.652)) < 0.7 && abs(camera.Position[1] - (0.030)) < 2 && abs(camera.Position[2] - (-0.455)) < 1)
        {
            if (!warer4)
            {

                warer4 = true;
            }
            else
            {
                warer4 = false;
            }
        }
        if (abs(camera.Position[0] - (-3.778)) < 0.7 && abs(camera.Position[1] - (-0.149)) < 2 && abs(camera.Position[2] - (-0.468)) < 1)
        {
            if (!beder4)
            {

                beder4 = true;
            }
            else
            {
                beder4 = false;
            }
        }
    }
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
    {
        if (!atoggle)
        {

            atoggle = true;
        }
        else
        {
            atoggle = false;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
    {
        if (!fl)
        {

            fl = true;
        }
        else
        {
            fl = false;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        ladderx += 0.1;
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        ladderx -= 0.1;
    }


    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        ladderz -= 0.1;
    }


    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        ladderz += 0.1;
    }
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
    {
        if (!keypick)
        {

            keypick = true;
        }
        else
        {
            keypick = false;
        }
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll Vase1 scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrappingModeS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureWrappingModeT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureFilteringModeMin);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureFilteringModeMax);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}



