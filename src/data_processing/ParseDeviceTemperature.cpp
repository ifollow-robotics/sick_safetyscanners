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
 * \file ParseDeviceTemperature.cpp
 *
 * \author  Diallo Djibril <djibril.diallo@ifollow.fr>
 * \date    2020-09-07
 */
//----------------------------------------------------------------------

#include <sick_safetyscanners/data_processing/ParseDeviceTemperature.h>

#include <sick_safetyscanners/cola2/Command.h>

namespace sick {
namespace data_processing {

ParseDeviceTemperature::ParseDeviceTemperature() {}


bool ParseDeviceTemperature::parseTCPSequence(const datastructure::PacketBuffer& buffer,
                                            datastructure::DeviceTemperature& device_temperature) const
{
  // Keep our own copy of the shared_ptr to keep the iterators valid
  const std::shared_ptr<std::vector<uint8_t> const> vec_ptr = buffer.getBuffer();
  std::vector<uint8_t>::const_iterator data_ptr             = vec_ptr->begin();
  device_temperature.setDeviceTemperature(readDeviceTemperature(data_ptr));
  return true;
}


int16_t
ParseDeviceTemperature::readDeviceTemperature(std::vector<uint8_t>::const_iterator data_ptr) const
{
  return read_write_helper::readInt16LittleEndian(data_ptr + 6);
}


} // namespace data_processing
} // namespace sick
