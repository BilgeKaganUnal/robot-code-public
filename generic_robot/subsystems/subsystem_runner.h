#ifndef GENERIC_ROBOT_SUBSYSTEMS_SUBSYSTEM_RUNNER_H_
#define GENERIC_ROBOT_SUBSYSTEMS_SUBSYSTEM_RUNNER_H_

#include <atomic>

#include "generic_robot/queue_manager/queue_manager.h"
#include "generic_robot/subsystems/drivetrain/drivetrain_base.h"
#include "generic_robot/wpilib/wpilib_interface.h"
#include "third_party/aos/common/time.h"
#include "third_party/aos/common/util/phased_loop.h"
#include "third_party/aos/linux_code/init.h"
#include "third_party/frc971/control_loops/drivetrain/drivetrain.h"

namespace generic_robot {

class SubsystemRunner {
 public:
  SubsystemRunner();
  ~SubsystemRunner() = default;
  void operator()();
  void Stop();

 private:
  std::atomic<bool> running_;
  wpilib::WpilibInterface wpilib_;
  frc971::control_loops::drivetrain::DrivetrainLoop drivetrain_;
};

}  // namespace generic_robot

#endif  // GENERIC_ROBOT_SUBSYSTEMS_SUBSYSTEM_RUNNER_H_
