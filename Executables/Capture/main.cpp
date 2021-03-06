/** @file */

#include <iostream>

#include <boost/program_options.hpp>

#include <YukariCommon/LoggingService.h>

#include "CaptureFactory.h"

using namespace Yukari::Common;
using namespace Yukari::Capture;
namespace po = boost::program_options;

int main(int argc, char **argv)
{
  auto logger = LoggingService::Instance().getLogger("YukariCaptureApp");

  /* Init command line */
  po::options_description desc("Allowed options");
  po::variables_map args;

  // clang-format off
  desc.add_options()
    ("help", "Show brief usage message")
    ("loglevel", po::value<std::string>()->default_value("debug"), "Global log level")
    ("dir", po::value<std::string>()->default_value("."), "Root output directory")
    ("forceexit", "Do not wait for queued processing tasks to complete on exit")
    ("cloudgrabber", po::value<std::string>()->default_value("dummy"), "Cloud grabber to use")
    ("imugrabber", po::value<std::string>(), "IMU grabber to use")
    ("orientation", po::value<std::string>()->default_value("[0, 0, 0] 0"), "Relative IMU orientation as \"[axis] angle\"")
    ("position", po::value<std::string>()->default_value("[0, 0, 0]"), "Relative IMU position as \"[position]\"")
    ("capturetrigger", po::value<std::string>()->default_value(""), "Trigger for a single frame")
    ("exittrigger", po::value<std::string>()->default_value("signal(signal=2)"), "Trigger for program exit")
    ("process", po::value<std::vector<std::string>>()->multitoken(), "Add processing stage");
  // clang-format on

  /* Parse command line args */
  try
  {
    po::store(po::parse_command_line(argc, argv, desc), args);
  }
  catch (po::error const &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  /* Show usage */
  if (args.count("help"))
  {
    std::cout << desc << "\n";
    return 1;
  }

  /* Configure logging */
  LoggingService::Instance().configure(args);

  /* Create capture controller */
  CaptureController::Ptr captureController = CaptureFactory::Create(args);
  if (!captureController)
  {
    logger->error("Could not create capture controller!");
    return 2;
  }

  logger->info("Capture controller: {}", *captureController);
  LoggingService::Instance().flush();

  /* Run capture */
  int exitCode = captureController->run();

  /* Exit */
  LoggingService::Instance().flush();
  return exitCode;
}
