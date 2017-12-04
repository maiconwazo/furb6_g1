#pragma once
#include <glew.h>
#include <freeglut.h>

const GLfloat C_BASE_X = 0.0f;
const GLfloat C_BASE_Y = 0.0f;
const GLfloat C_BASE_Z = 0.0f;

const GLfloat C_ALT_TAB = 0.3f + C_BASE_Y;
const GLfloat C_LADO_TAB_X = 9.0f + C_BASE_X;
const GLfloat C_LADO_TAB_Z = 9.0f + C_BASE_Z;

const GLfloat C_COR_FUNDO[] = { 0.2f, 0.2f, 0.5f, 1.0f };

/* Definições de iluminação */
const GLfloat whiteAmb[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat whiteDif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat whiteSpe[] = { 0.6f, 0.6f, 0.6f, 1.0f };

const GLfloat blackAmb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat blackDif[] = { 0.2f, 0.2f, 0.2f, 1.0f };
const GLfloat blackSpe[] = { 0.1f, 0.1f, 0.1f, 1.0f };

const GLfloat purpleAmb[] = { 0.3f, 0.0f, 0.3f, 1.0f };
const GLfloat purpleDif[] = { 0.3f, 0.0f, 0.3f, 1.0f };
const GLfloat purpleSpe[] = { 0.2f, 0.0f, 0.2f, 1.0f };

const GLfloat blueAmb[] = { 0.0f, 0.0f, 0.3f, 1.0f };
const GLfloat blueDif[] = { 0.0f, 0.0f, 0.6f, 1.0f };
const GLfloat blueSpe[] = { 0.0f, 0.0f, 0.4f, 1.0f };

const GLfloat grayAmb[] = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat grayDif[] = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat graySpe[] = { 0.1f, 0.1f, 0.1f, 1.0f };

const GLfloat brownAmb[] = { 0.2f, 0.0f, 0.0f, 1.0f };
const GLfloat brownDif[] = { 0.9f, 0.0f, 0.0f, 1.0f };
const GLfloat brownSpe[] = { 0.4f, 0.0f, 0.0f, 1.0f };

const GLfloat blackChessAmb[] = { 0.16f, 0.06f, 0.05f, 1.0f };
const GLfloat blackChessDif[] = { 0.33f, 0.12f, 0.10f, 1.0f };
const GLfloat blackChessSpe[] = { 0.10f, 0.02f, 0.02f, 1.0f };

const GLfloat whiteChessAmb[] = { 0.5f, 0.45f, 0.30f, 1.0f };
const GLfloat whiteChessDif[] = { 1.0f, 0.90f, 0.60f, 1.0f };
const GLfloat whiteChessSpe[] = { 0.3f, 0.25f, 0.10f, 1.0f };

const GLfloat blueTranspAmb[] = { 0.0f, 0.0f, 0.6f, 0.4f };
const GLfloat blueTranspDif[] = { 0.0f, 0.0f, 0.8f, 0.4f };
const GLfloat blueTranspSpe[] = { 0.0f, 0.0f, 0.5f, 0.4f };

const GLfloat darkBlueTranspAmb[] = { 0.0f, 0.0f, 0.1f, 0.6f };
const GLfloat darkBlueTranspDif[] = { 0.0f, 0.0f, 0.3f, 0.6f };
const GLfloat darkBlueTranspSpe[] = { 0.0f, 0.0f, 0.1f, 0.6f };

const GLfloat redTranspAmb[] = { 0.8f, 0.0f, 0.8f, 0.6f };
const GLfloat redTranspDif[] = { 1.0f, 0.0f, 1.0f, 0.6f };
const GLfloat redTranspSpe[] = { 0.6f, 0.0f, 0.6f, 0.6f };

const GLfloat darkRedTranspAmb[] = { 0.1f, 0.0f, 0.1f, 0.8f };
const GLfloat darkRedTranspDif[] = { 0.3f, 0.0f, 0.3f, 0.8f };
const GLfloat darkRedTranspSpe[] = { 0.1f, 0.0f, 0.1f, 0.8f };