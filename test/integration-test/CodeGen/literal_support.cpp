//===--------------------------------------------------------------------------------*- C++ -*-===//
//                         _       _
//                        | |     | |
//                    __ _| |_ ___| | __ _ _ __   __ _
//                   / _` | __/ __| |/ _` | '_ \ / _` |
//                  | (_| | || (__| | (_| | | | | (_| |
//                   \__, |\__\___|_|\__,_|_| |_|\__, | - GridTools Clang DSL
//                    __/ |                       __/ |
//                   |___/                       |___/
//
//
//  This file is distributed under the MIT License (MIT).
//  See LICENSE.txt for details.
//
//===------------------------------------------------------------------------------------------===//

#include "gridtools/clang_dsl.hpp"

using namespace gridtools::clang;

stencil_function times_n {
  storage in;
  storage mul;

  Do { return in*mul; }
};

stencil test_stencil {
  storage in, out;
  var mul;

  Do {
    vertical_region(k_start, k_end) {
        mul = 2;
        out = times_n(in, mul);
    }
  }
};
