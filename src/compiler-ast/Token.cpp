//
// Created by kai on 4/19/19.
//

#include "Token.h"

Token::Token (Type type,
              const std::string &lexeme,
              int line)
    :type_(type),
     lexeme_(lexeme),
     line_(line)
{

}

//Token::Token()
//    :type_(Token::EoF),
//     lexeme_(""),
//     line_(1){}


Token::Type Token::type() const
{
    return type_;
}

int Token::line() const
{
    return line_;
}

const std::string& Token::lexeme() const
{
    return lexeme_;
}

std::string Token::toString() {
    switch (type_) {
        case EoF:
            return "[End of File]";
        default:
            return "[" + lexeme_ + "]";
    }
}
