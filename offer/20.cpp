class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_POINT,
        CHAR_EXP,
        CHAR_ILLEGAL
    };

    CharType toCharType(char c)
    {
        if (c >= '0' && c <= '9')
            return CHAR_NUMBER;
        else if (c == '-' || c == '+')
            return CHAR_SIGN;
        else if (c == ' ')
            return CHAR_SPACE;
        else if (c == '.')
            return CHAR_POINT;
        else if (c == 'e' || c == 'E')
            return CHAR_EXP;
        else
            return CHAR_ILLEGAL;
    }

    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer = {
            {
                STATE_INITIAL, {
                    {CHAR_SPACE, STATE_INITIAL},
                    {CHAR_SIGN , STATE_SIGN},
                    {CHAR_POINT, STATE_POINT_WITHOUT},
                    {CHAR_NUMBER, STATE_INTEGER}
                }
            },
            {
                STATE_SIGN, {
                    {CHAR_POINT, STATE_POINT_WITHOUT},
                    {CHAR_NUMBER,STATE_INTEGER}
                }
            },
            {
                STATE_INTEGER, {
                    {CHAR_NUMBER,STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT},
                    {CHAR_SPACE, STATE_END},
                    {CHAR_EXP,   STATE_EXP}
                }
            },
            {
                STATE_POINT, {
                    {CHAR_SPACE, STATE_END},
                    {CHAR_EXP,   STATE_EXP},
                    {CHAR_NUMBER,STATE_FRACTION}
                }
            },
            {
                STATE_POINT_WITHOUT, {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            },
            {
                STATE_FRACTION, {
                    {CHAR_SPACE,  STATE_END},
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP,    STATE_EXP}
                }
            },
            {
                STATE_EXP, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SIGN,   STATE_EXP_SIGN}
                }
            },
            {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            },
            {
                STATE_EXP_NUMBER, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SPACE,  STATE_END}
                }
            },
            {
                STATE_END, {
                    {CHAR_SPACE,  STATE_END}
                }
            }
        };

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; ++i) {
            CharType chty = toCharType(s[i]);
            if (transfer[st].find(chty) == transfer[st].end()) {
                return false;
            }
            else {
                st = transfer[st][chty];
            }
        }

        return st == STATE_END || st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER;
    }
};