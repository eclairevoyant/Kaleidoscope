/* -*- mode: c++ -*-
 * Copyright (C) 2020  Eric Paniagua (epaniagua@google.com)
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "testing/common/VirtualDeviceTest.h"

#include <memory>

namespace kaleidoscope {
namespace testing {

std::unique_ptr<State> VirtualDeviceTest::RunCycle() {
  auto state = std::unique_ptr<State>(new State());
  sim_.RunCycle();
  state->Snapshot();
  return state;
}

}  // namespace testing
}  // namespace kaleidoscope
