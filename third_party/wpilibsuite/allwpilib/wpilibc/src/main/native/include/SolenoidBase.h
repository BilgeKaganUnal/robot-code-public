/*----------------------------------------------------------------------------*/
/* Copyright (c) 2008-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "ErrorBase.h"
#include "SmartDashboard/SendableBase.h"

namespace frc {

/**
 * SolenoidBase class is the common base class for the Solenoid and
 * DoubleSolenoid classes.
 */
class SolenoidBase : public ErrorBase, public SendableBase {
 public:
  static int GetAll(int module);
  int GetAll() const;

  static int GetPCMSolenoidBlackList(int module);
  int GetPCMSolenoidBlackList() const;
  static bool GetPCMSolenoidVoltageStickyFault(int module);
  bool GetPCMSolenoidVoltageStickyFault() const;
  static bool GetPCMSolenoidVoltageFault(int module);
  bool GetPCMSolenoidVoltageFault() const;
  static void ClearAllPCMStickyFaults(int module);
  void ClearAllPCMStickyFaults();

 protected:
  explicit SolenoidBase(int pcmID);

  static constexpr int m_maxModules = 63;
  static constexpr int m_maxPorts = 8;

  int m_moduleNumber;  // PCM module number
};

}  // namespace frc
