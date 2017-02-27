/** @file */

#include "ApplyTransformationToCloud.h"

#include <Eigen/Geometry>
#include <YukariCloudCapture/ICloudGrabber.h>
#include <pcl/common/transforms.h>

using namespace Yukari::CloudCapture;
using namespace Yukari::Processing;

namespace Yukari
{
namespace Algorithms
{
  ApplyTransformationToCloud::ApplyTransformationToCloud()
  {
    /* Add default validator */
    m_validator = [](const PropertyContainer &inProps, const PropertyContainer &) {
      auto clouds = inProps.find("cloud");
      if (clouds == inProps.end())
        return "No point clouds provided";

      auto transformations = inProps.find("transform");
      if (transformations == inProps.end())
        return "No transformations provided";

      if (clouds->second.size() != transformations->second.size())
        return "Number of clouds and transformations must match";

      return "";
    };
  }

  void ApplyTransformationToCloud::execute()
  {
    Property cloud = getProperty(Processing::INPUT, "cloud");
    Property transform = getProperty(Processing::INPUT, "transform");

    size_t len = cloud.size();

    Property transformedCloud(len);

    for (size_t i = 0; i < len; i++)
    {
      ICloudGrabber::Cloud::Ptr c = cloud.value<ICloudGrabber::Cloud::Ptr>(i);
      Eigen::Matrix4f t = transform.value<Eigen::Matrix4f>(i);

      ICloudGrabber::Cloud::Ptr tc(new ICloudGrabber::Cloud());
      pcl::transformPointCloud(*c, *tc, t);

      transformedCloud[i] = tc;
    }

    setProperty(Processing::OUTPUT, "cloud", transformedCloud);
  }
}
}