#ifndef UTIL_FPSCOUNTER_H
#define UTIL_FPSCOUNTER_H

#include <util/Averager.h>
#include <util/Timer.h>


/**
 * FpsCounter class. For measuring fps.
 *
 * @author SwarmingLogic (Roald Fernandez)
 */
class FpsCounter
{
public:
  /**
   * @param N How many frames to average (makes for easier readout).
   */
  FpsCounter(int n = 3);
  virtual ~FpsCounter();

  double getFps() const;
  double getSpf() const;
  void tic();

private:
  Timer timer_;
  Averager averageSpf_;
  double lastTime_;

  // NonCopyable
  FpsCounter(const FpsCounter& c);
  FpsCounter& operator=(const FpsCounter& c);
};

#endif
