// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------

/*!
*  Copyright (C) 2019, SICK AG, Waldkirch
*  Copyright (C) 2019, FZI Forschungszentrum Informatik, Karlsruhe, Germany
*
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.

*/

// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!
 * \file DeviceTemperatureVariableCommand.cpp
 *
 * \author  Diallo Djibril <djibril.diallo@ifollow.fr>
 * \date    2020-09-07
 */
//----------------------------------------------------------------------

#include <sick_safetyscanners/cola2/DeviceTemperatureVariableCommand.h>

#include <sick_safetyscanners/cola2/Cola2Session.h>
#include <sick_safetyscanners/cola2/Command.h>

namespace sick {
namespace cola2 {

DeviceTemperatureVariableCommand::DeviceTemperatureVariableCommand(
  Cola2Session& session, datastructure::DeviceTemperature& device_temperature)
  : VariableCommand(session, 362)
  , m_device_temperature(device_temperature)
{
  m_device_temperature_parser_ptr = std::make_shared<sick::data_processing::ParseDeviceTemperature>();
}

bool DeviceTemperatureVariableCommand::canBeExecutedWithoutSessionID() const
{
  return true;
}

bool DeviceTemperatureVariableCommand::processReply()
{
  if (!base_class::processReply())
  {
    return false;
  }

  m_device_temperature_parser_ptr->parseTCPSequence(getDataVector(), m_device_temperature);


  return true;
}


} // namespace cola2
} // namespace sick
