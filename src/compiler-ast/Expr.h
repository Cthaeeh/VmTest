//
// Created by kai on 4/19/19.
//

#ifndef VMTEST_EXPR_H
#define VMTEST_EXPR_H

#include "AstNode.h"

class Expr;

typedef std::shared_ptr<Expr> ExprPtr;

class Expr : public AstNode
{

};

#endif //VMTEST_EXPR_H
