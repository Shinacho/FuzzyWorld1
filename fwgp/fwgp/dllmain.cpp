#include "fw_game_input_GamePadConnection.h"
#include "lib\jni.h"
#include <d2d1.h>
#include <Xinput.h>

#pragma comment(lib,"Xinput.lib")

static XINPUT_STATE state;
static XINPUT_GAMEPAD gamepad;

JNIEXPORT jfloatArray JNICALL Java_fw_game_input_GamePadConnection_getNativeState(JNIEnv* env, jclass thisj, jint plIdx) {
 jfloatArray result = env->NewFloatArray(fw_game_input_GamePadConnection_LENGTH);
 ZeroMemory(&state, sizeof(XINPUT_STATE));
 DWORD connection = XInputGetState(plIdx, &state);
 gamepad = state.Gamepad;
 float stateData[fw_game_input_GamePadConnection_LENGTH];
 stateData[fw_game_input_GamePadConnection_BUTTON_A] = float(gamepad.wButtons & XINPUT_GAMEPAD_A);
 stateData[fw_game_input_GamePadConnection_BUTTON_B] = float(gamepad.wButtons & XINPUT_GAMEPAD_B);
 stateData[fw_game_input_GamePadConnection_BUTTON_X] = float(gamepad.wButtons & XINPUT_GAMEPAD_X);
 stateData[fw_game_input_GamePadConnection_BUTTON_Y] = float(gamepad.wButtons & XINPUT_GAMEPAD_Y);
 stateData[fw_game_input_GamePadConnection_BUTTON_LB] = float(gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER);
 stateData[fw_game_input_GamePadConnection_BUTTON_RB] = float(gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER);
 stateData[fw_game_input_GamePadConnection_BUTTON_LEFT_STICK] = float(gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB);
 stateData[fw_game_input_GamePadConnection_BUTTON_RIGHT_STICK] = float(gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB);
 stateData[fw_game_input_GamePadConnection_BUTTON_POV_UP] = float(gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP);
 stateData[fw_game_input_GamePadConnection_BUTTON_POV_DOWN] = float(gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN);
 stateData[fw_game_input_GamePadConnection_BUTTON_POV_LEFT] = float(gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT);
 stateData[fw_game_input_GamePadConnection_BUTTON_POV_RIGHT] = float(gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT);
 stateData[fw_game_input_GamePadConnection_BUTTON_START] = float(gamepad.wButtons & XINPUT_GAMEPAD_START);
 stateData[fw_game_input_GamePadConnection_BUTTON_BACK] = float(gamepad.wButtons & XINPUT_GAMEPAD_BACK);
 stateData[fw_game_input_GamePadConnection_TRIGGER_LEFT] = (float)gamepad.bLeftTrigger / (float)fw_game_input_GamePadConnection_TRIGGER_MAX;
 stateData[fw_game_input_GamePadConnection_TRIGGER_RIGHT] = (float)gamepad.bRightTrigger / (float)fw_game_input_GamePadConnection_TRIGGER_MAX;
 stateData[fw_game_input_GamePadConnection_THUMB_STICK_LEFT_X] = (float)gamepad.sThumbLX / (float)fw_game_input_GamePadConnection_THUMSTICK_ABS_MAX * 2.0f;
 stateData[fw_game_input_GamePadConnection_THUMB_STICK_LEFT_Y] = (float)gamepad.sThumbLY / (float)fw_game_input_GamePadConnection_THUMSTICK_ABS_MAX * 2.0f;
 stateData[fw_game_input_GamePadConnection_THUMB_STICK_RIGHT_X] = (float)gamepad.sThumbRX / (float)fw_game_input_GamePadConnection_THUMSTICK_ABS_MAX * 2.0f;
 stateData[fw_game_input_GamePadConnection_THUMB_STICK_RIGHT_Y] = (float)gamepad.sThumbRY / (float)fw_game_input_GamePadConnection_THUMSTICK_ABS_MAX * 2.0f;
 stateData[fw_game_input_GamePadConnection_CONNECTION] = (connection == ERROR_SUCCESS);
 jfloat* aryP = env->GetFloatArrayElements(result, NULL);
 for (int i = 0; i < fw_game_input_GamePadConnection_LENGTH; i++) aryP[i] = stateData[i];
 env->ReleaseFloatArrayElements(result, aryP, 0);
 return result;
}
