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
 * \file DeviceTemperature.h
 *
 * \author  Diallo Djibril <djibril.diallo@ifollow.fr>
 * \date    2020-09-07
 */
//----------------------------------------------------------------------

#ifndef SICK_SAFETYSCANNERS_DATASTRUCTURE_DEVICETEMPERATURE_H
#define SICK_SAFETYSCANNERS_DATASTRUCTURE_DEVICETEMPERATURE_H

#include <iostream>


namespace sick {
namespace datastructure {

/*!
 * \brief Class containing the device temperature of a laser scanner.
 */
class DeviceTemperature
{
public:
  /*!
   * \brief Constructor of the device temperature.
   */
  DeviceTemperature();

  /*!
   * \brief Gets the device temperature for the scanner.
   *
   * \returns The device temperature for the scanner.
   */
  int16_t getDeviceTemperature() const;
  /*!
   * \brief Sets the device temperature for the scanner.
   */
  void setDeviceTemperature(const int16_t& device_temperature);

private:
  int16_t m_device_temperature;
};


} // namespace datastructure
} // namespace sick

#endif // SICK_SAFETYSCANNERS_DATASTRUCTURE_DEVICETEMPERATURE_H
