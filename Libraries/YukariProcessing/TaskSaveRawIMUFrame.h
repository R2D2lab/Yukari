/** @file */

#pragma once

#include "IFrameProcessingTask.h"

#include <iomanip>
#include <sstream>

#include <boost/filesystem/path.hpp>
#include <pcl/io/pcd_io.h>

#include <YukariCommon/LoggingService.h>

namespace Yukari
{
namespace Processing
{
  class TaskSaveRawIMUFrame : public IFrameProcessingTask
  {
  public:
    TaskSaveRawIMUFrame(const boost::filesystem::path &path)
        : IFrameProcessingTask(path)
        , m_logger(Common::LoggingService::Instance().getLogger("TaskSaveRawIMUFrame"))
    {
    }

    virtual int process(Task t) override
    {
      if (t.imuFrame)
      {
        /* Generate filename */
        std::stringstream ss;
        ss << std::setw(5) << std::setfill('0') << t.frameNumber;
        boost::filesystem::path imuFilename = m_outputDirectory / (ss.str() + "_imu.txt");

        /* Save IMU frame */
        t.imuFrame->save(imuFilename);
      }
      else
      {
        m_logger->error("No IMU frame, cannot save");
        return 1;
      }

      return 0;
    }

  private:
    Common::LoggingService::Logger m_logger;
  };
}
}
