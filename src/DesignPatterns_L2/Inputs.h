#pragma once

namespace l2
{

    namespace sys
    {

        class Inputs
        {
        public:
            enum KeyCode
            {
                KeyCode_A,
                KeyCode_B,
                KeyCode_C,
                KeyCode_D,
                KeyCode_E,
                KeyCode_F,
                KeyCode_G,
                KeyCode_H,
                KeyCode_I,
                KeyCode_J,
                KeyCode_K,
                KeyCode_L,
                KeyCode_M,
                KeyCode_N,
                KeyCode_O,
                KeyCode_P,
                KeyCode_Q,
                KeyCode_R,
                KeyCode_S,
                KeyCode_T,
                KeyCode_U,
                KeyCode_V,
                KeyCode_W,
                KeyCode_X,
                KeyCode_Y,
                KeyCode_Z,
                KeyCode_1,
                KeyCode_2,
                KeyCode_3,
                KeyCode_4,
                KeyCode_5,
                KeyCode_6,
                KeyCode_7,
                KeyCode_8,
                KeyCode_9,
                KeyCode_0,
                KeyCode_Esc,
                KeyCode_Tab,
                KeyCode_Space,
                KeyCode_Enter,
                KeyCode_UpArrow,
                KeyCode_DownArrow,
                KeyCode_LeftArrow,
                KeyCode_RightArrow,
                KeyCode_Unknown
            };

            static const KeyCode GetKeyCode(const char keyValue);
            static const KeyCode GetArrowCode(const char keyValue);
        };

    }

}