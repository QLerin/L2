#include "Inputs.h"

using namespace l2::sys;

const Inputs::KeyCode Inputs::GetKeyCode(const char keyValue)
{
    switch (keyValue)
    {
    case 0x41:
    case 0x61:
        return KeyCode_A;
    case 0x42:
    case 0x62:
        return KeyCode_B;
    case 0x43:
    case 0x63:
        return KeyCode_C;
    case 0x44:
    case 0x64:
        return KeyCode_D;
    case 0x45:
    case 0x65:
        return KeyCode_E;
    case 0x46:
    case 0x66:
        return KeyCode_F;
    case 0x47:
    case 0x67:
        return KeyCode_G;
    case 0x48:
    case 0x68:
        return KeyCode_H;
    case 0x49:
    case 0x69:
        return KeyCode_I;
    case 0x4A:
    case 0x6A:
        return KeyCode_J;
    case 0x4B:
    case 0x6B:
        return KeyCode_K;
    case 0x4C:
    case 0x6C:
        return KeyCode_L;
    case 0x4D:
    case 0x6D:
        return KeyCode_M;
    case 0x4E:
    case 0x6E:
        return KeyCode_N;
    case 0x50:
    case 0x70:
        return KeyCode_O;
    case 0x51:
    case 0x71:
        return KeyCode_P;
    case 0x52:
    case 0x72:
        return KeyCode_Q;
    case 0x53:
    case 0x73:
        return KeyCode_R;
    case 0x54:
    case 0x74:
        return KeyCode_S;
    case 0x55:
    case 0x75:
        return KeyCode_T;
    case 0x56:
    case 0x76:
        return KeyCode_U;
    case 0x57:
    case 0x77:
        return KeyCode_V;
    case 0x58:
    case 0x78:
        return KeyCode_W;
    case 0x59:
    case 0x79:
        return KeyCode_X;
    case 0x5A:
    case 0x7A:
        return KeyCode_Y;
    case 0x5B:
    case 0x7B:
        return KeyCode_Z;
    case 0x09:
        return KeyCode_Tab;
    case 0x27:
        return KeyCode_Esc;
    case 0x20:
        return KeyCode_Space;
    case 0x0D:
        return KeyCode_Enter;
    }
    return KeyCode_Unknown;
}

const Inputs::KeyCode Inputs::GetArrowCode(const char keyValue)
{
    switch (keyValue)
    {
    case 0x48:
        return KeyCode_UpArrow;
    case 0x4B:
        return KeyCode_LeftArrow;
    case 0x4D:
        return KeyCode_RightArrow;
    case 0x50:
        return KeyCode_DownArrow;
    }
    return KeyCode_Unknown;
}