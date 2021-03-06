/** @file */

#pragma once

#include "IMSPGrabber.h"

#include <YukariCommon/LoggingService.h>

namespace Yukari
{
namespace IMU
{
  class TeensyIMUDevice : public IMSPGrabber
  {
  public:
    TeensyIMUDevice(const std::string &port, unsigned int baud = 115200);
    virtual ~TeensyIMUDevice();

    void setDispacement(const Eigen::Vector3f &displacement);

    virtual IMUFrame::Ptr grabFrame() override;

  protected:
    MSP::MSPClient::Payload m_mspPayloadQuat;

  private:
    Common::LoggingService::Logger m_logger;
  };
}
}