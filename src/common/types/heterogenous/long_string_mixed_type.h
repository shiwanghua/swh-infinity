//
// Created by JinHai on 2022/11/20.
//


#pragma once

#include "base_mixed_type.h"

namespace infinity {

struct __attribute__((packed)) LongStrMixedType : public BaseMixedType {
    LongStrMixedType() : BaseMixedType(MixedValueType::kLongStr) {}

    char_t header[BaseMixedType::LONG_STR_HEADER]{}; // 5 bytes is used to store the header of the string to shortcut some computation.
    u16 length{0};  // Max string length will be 65535
    ptr_t ptr{nullptr};
};

}