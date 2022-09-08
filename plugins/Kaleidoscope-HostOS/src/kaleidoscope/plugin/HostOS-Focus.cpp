/* -*- mode: c++ -*-
 * Kaleidoscope-HostOS -- Host OS detection and tracking for Kaleidoscope
 * Copyright (C) 2016, 2017, 2018  Keyboard.io, Inc
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

#include "kaleidoscope/plugin/HostOS-Focus.h"

#include <Arduino.h>                   // for PSTR, strcmp_P
#include <Kaleidoscope-FocusSerial.h>  // for Focus, FocusSerial
#include <stdint.h>                    // for uint8_t

#include "kaleidoscope/event_handler_result.h"  // for EventHandlerResult, EventHandlerResult::OK
#include "kaleidoscope/plugin/HostOS.h"         // for HostOS, Type

namespace kaleidoscope {
namespace plugin {

EventHandlerResult FocusHostOSCommand::onFocusEvent(const char *command) {
  const char *cmd = PSTR("hostos.type");

  if (::Focus.inputMatchesHelp(command))
    return ::Focus.printHelp(cmd);

  if (strcmp_P(command, cmd) != 0)
    return EventHandlerResult::OK;

  if (::Focus.isEOL()) {
    ::Focus.send(::HostOS.os());
  } else {
    uint8_t new_os;
    ::Focus.read(new_os);
    ::HostOS.os((hostos::Type)new_os);
  }

  return EventHandlerResult::EVENT_CONSUMED;
}

}  // namespace plugin
}  // namespace kaleidoscope

kaleidoscope::plugin::FocusHostOSCommand FocusHostOSCommand;
