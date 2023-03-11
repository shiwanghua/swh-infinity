//
// Created by jinhai on 23-2-22.
//

#pragma once

#include "common/types/internal_types.h"

namespace infinity {

enum class StatementType {
    kInvalidStmt,  // unused
    kSelect,
    kCopy,
    kInsert,
    kUpdate,
    kDelete,
    kCreate,
    kDrop,
    kPrepare,
    kExecute,
    kAlter,
    kShow,
    kExplain,
};

class BaseStatement {
public:
    explicit
    BaseStatement(StatementType type) : type_(type) {}

    virtual
    ~BaseStatement() = default;

    [[nodiscard]] virtual String
    ToString() const = 0;

    [[nodiscard]] inline StatementType
    Type() const {
        return type_;
    }

    StatementType type_{StatementType::kInvalidStmt};
    SizeT stmt_location_{0};
    SizeT stmt_length_ = {0};
    String text_{};
};

}