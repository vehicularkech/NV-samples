/*
 * Copyright (c) 2014, NVIDIA Corporation.  All Rights Reserved.
 *
 * BY INSTALLING THE SOFTWARE THE USER AGREES TO THE TERMS BELOW.
 *
 * User agrees to use the software under carefully controlled conditions
 * and to inform all employees and contractors who have access to the software
 * that the source code of the software is confidential and proprietary
 * information of NVIDIA and is licensed to user as such.  User acknowledges
 * and agrees that protection of the source code is essential and user shall
 * retain the source code in strict confidence.  User shall restrict access to
 * the source code of the software to those employees and contractors of user
 * who have agreed to be bound by a confidentiality obligation which
 * incorporates the protections and restrictions substantially set forth
 * herein, and who have a need to access the source code in order to carry out
 * the business purpose between NVIDIA and user.  The software provided
 * herewith to user may only be used so long as the software is used solely
 * with NVIDIA products and no other third party products (hardware or
 * software).   The software must carry the NVIDIA copyright notice shown
 * above.  User must not disclose, copy, duplicate, reproduce, modify,
 * publicly display, create derivative works of the software other than as
 * expressly authorized herein.  User must not under any circumstances,
 * distribute or in any way disseminate the information contained in the
 * source code and/or the source code itself to third parties except as
 * expressly agreed to by NVIDIA.  In the event that user discovers any bugs
 * in the software, such bugs must be reported to NVIDIA and any fixes may be
 * inserted into the source code of the software by NVIDIA only.  User shall
 * not modify the source code of the software in any way.  User shall be fully
 * responsible for the conduct of all of its employees, contractors and
 * representatives who may in any way violate these restrictions.
 *
 * NO WARRANTY
 * THE ACCOMPANYING SOFTWARE (INCLUDING OBJECT AND SOURCE CODE) PROVIDED BY
 * NVIDIA TO USER IS PROVIDED "AS IS."  NVIDIA DISCLAIMS ALL WARRANTIES,
 * EXPRESS, IMPLIED OR STATUTORY, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF TITLE, MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.

 * LIMITATION OF LIABILITY
 * NVIDIA SHALL NOT BE LIABLE TO USER, USERS CUSTOMERS, OR ANY OTHER PERSON
 * OR ENTITY CLAIMING THROUGH OR UNDER USER FOR ANY LOSS OF PROFITS, INCOME,
 * SAVINGS, OR ANY OTHER CONSEQUENTIAL, INCIDENTAL, SPECIAL, PUNITIVE, DIRECT
 * OR INDIRECT DAMAGES (WHETHER IN AN ACTION IN CONTRACT, TORT OR BASED ON A
 * WARRANTY), EVEN IF NVIDIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.  THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING ANY FAILURE OF THE
 * ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.  IN NO EVENT SHALL NVIDIAS
 * AGGREGATE LIABILITY TO USER OR ANY OTHER PERSON OR ENTITY CLAIMING THROUGH
 * OR UNDER USER EXCEED THE AMOUNT OF MONEY ACTUALLY PAID BY USER TO NVIDIA
 * FOR THE SOFTWARE PROVIDED HEREWITH.
 */

//------------------------------------------------------------------------------
//! \file startupanimation.c
//! \brief Test application for StartupAnimation
//------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/time.h>
#include "nvstartupanimation.h"

void printOptions(void);
int tokenizeline(char *input, char **voString);

void printOptions(void)
{
    printf("Usage \n\n");
    printf("pv                     (Play .H264 file) \n");
    printf("kv                     (Kill playback) \n");
    printf("q                      (Quits the Program) \n");
    printf("h                      (prints the above information) \n");
}


int tokenizeline(char *input, char **voString) {
    int len = strlen(input);
    int i=0,k;
    char strtemp[255];
    int numstrings = 0;

    for (i = 0;i < len; i++) {
        char bQuoted = 0;
        while (i < len && isspace(input[i])) {
            i++;
        }

        if(i < len && input[i] == '"') {
            bQuoted = 1;
            i++;
        }

        k = 0;
        if (bQuoted) {
            while (i < len && input[i] != '"') {
                strtemp[k++] = input[i++];
            }

            if (i < len && input[i] == '"') {
                i++;
            }
            strtemp[k]='\0';
        }
        else {
            while (i < len && !isspace(input[i])) {
                strtemp[k++] = input[i++] ;
            }
            strtemp[k]='\0';
        }
        if (k) {
            voString[numstrings] = (char*)malloc(k + 1);
            strcpy(voString[numstrings++], strtemp);
        }
    }
    return numstrings;
}

static void OnError(void *pClient)
{
    printf("StartupAnimation Error\n");
}

static void OnEnd(void *pClinet)
{
    printf("StartupAnimaiton Ended\n");
}

int main(int argc, char* argv[])
{
    NvStartupAnimation *pStartupAnimation = NULL;
    char *voString[256] = {0};
    char input[256] = {0};
    char bQuit = 0;
    U32 i = 0;
    U32 numstrings = 0;
    NvResult result = RESULT_OK;

    while (!bQuit) {
        printf("-");
        fgets(input, 256, stdin);

        if (input[0] == 0 || !(numstrings = tokenizeline(input,voString))) {
            continue;
        }
        else if (!strcmp(voString[0],"h")) {
            printOptions();
        }
        else if (!strcmp(voString[0],"pv")) {
            NvSACallback oCallback;
            NvSAParams oParams;

            if (pStartupAnimation) {
                printf("Startup Animation is already running\n");
                goto freetokens;
            }

            memset(&oParams, 0, sizeof(NvSAParams));
            memset(&oCallback, 0, sizeof(NvSACallback));

            oCallback.OnEnd = OnEnd;
            oCallback.OnError = OnError;

            // Set to displayId = 1, which is HDMI on drive-cx
            oParams.uDisplayId = 1;
            oParams.pClient = NULL;
            oParams.pCallback = &oCallback;

            pStartupAnimation = NvStartupAnimationCreate(&oParams);
            if (pStartupAnimation == NULL) {
                printf("Failed to create StartupAnimation\n");
                goto freetokens;
            }
            result = NvStartupAnimationPlay(pStartupAnimation, voString[1], 30.0);
            if (IsFailed(result)) {
                printf("Faile to play file %s\n", voString[1]);
                goto freetokens;
            }
        }
        else if (!strcmp(voString[0], "kv")) {
            if (pStartupAnimation) {
                NvStartupAnimationStop(pStartupAnimation);
                NvStartupAnimationDestroy(pStartupAnimation);
                pStartupAnimation = NULL;
            }
        }
        else if(!strcmp(voString[0],"q") || !strcmp(voString[0],"quit")) {
            if (pStartupAnimation) {
                NvStartupAnimationStop(pStartupAnimation);
                NvStartupAnimationDestroy(pStartupAnimation);
                pStartupAnimation = NULL;
            }
            bQuit = 1;
        }

        freetokens:
        for(i = 0; i < numstrings; i++) {
            free(voString[i]);
        }
    }
    return 0;
}
