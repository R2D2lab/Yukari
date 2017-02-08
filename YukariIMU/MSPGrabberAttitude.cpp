/** @file */

#include "MSPGrabberAttitude.h"

#include <YukariMaths/Quaternion.h>
#include <YukariMaths/Vector3.h>

using namespace Yukari::Maths;

namespace Yukari
{
namespace IMU
{
  MSPGrabberAttitude::MSPGrabberAttitude(const std::string &port, unsigned int baud)
      : MSPGrabber(port, baud)
  {
    m_mspPayload.reserve(6);
  }

  MSPGrabberAttitude::~MSPGrabberAttitude()
  {
  }

  IMUFrame_sptr MSPGrabberAttitude::grabFrame()
  {
    m_mspPayload.clear();

    bool ok = m_client.requestData(MSPClient::ATTITUDE, m_mspPayload) &&
              MSPClient::ParseAttitudePayload(m_mspPayload, m_attitude);

    if (!ok)
      return nullptr;

    auto timeNow = std::chrono::high_resolution_clock::now();
    auto frameDuration = timeNow - m_lastFrameTime;
    m_lastFrameTime = timeNow;

    auto retVal = std::make_shared<IMUFrame>(frameDuration);
    retVal->orientation() =
        Quaternion(Vector3(m_attitude[0], m_attitude[1], m_attitude[2]), Quaternion::YZX, DEGREES);

    return retVal;
  }
}
}