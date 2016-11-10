#ifndef O2016_SUBSYSTEMS_DRIVETRAIN_DRIVETRAIN_SUBSYSTEM_H_
#define O2016_SUBSYSTEMS_DRIVETRAIN_DRIVETRAIN_SUBSYSTEM_H_

#include "drivetrain_controller.h"
#include "o2016/queue_manager/queue_manager.h"
#include "o2016/subsystems/drivetrain/drivetrain_controller.h"

namespace o2016 {

namespace drivetrain {

class DrivetrainSubsystem {
 public:
  DrivetrainSubsystem();

  // Call this at 200hz to update the subsystem!
  void Update();

 private:
  DrivetrainInputQueue::QueueReader input_queue_reader_;
  DrivetrainOutputQueue& output_queue_;
  DrivetrainGoalQueue::QueueReader goal_queue_reader_;
  DrivetrainStatusQueue& status_queue_;

  // Tries to set all of the goals in the queue
  void UpdateGoals();
  // Tries to set the goal to a specific goal. It will only actually set the
  // goal if:
  //  - The new goal is a DistanceGoal
  //  - The new goal is a VelocityGoal and there is no currently-running
  //    DistanceGoal
  //  - The new goal is a VelocityGoal and it is set to override DistanceGoals
  //    (not implemented yet)
  // These rules are chosen because VelocityGoals are sent continuously and
  // DistanceGoals are sent one-at-a-time.
  bool TrySetGoal(const DrivetrainGoalProto& goal);

  controller::DrivetrainController controller_;

  DrivetrainGoalProto current_goal_;
};

}  // drivetrain

}  // frc1678

#endif /* ifndef O2016_SUBSYSTEMS_DRIVETRAIN_DRIVETRAIN_SUBSYSTEM_H_ */