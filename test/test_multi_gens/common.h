#include "mac_stat_tags.h"
#include "sis_stat_tags.h"
#include "hw_intf.h"

#include <stat_log/stat_log.h>
#include <stat_log/backends/shared_mem_backend.h>
#include <stat_log/stats/stats_common.h>
#include <stat_log/stats/simple_counter.h>
#include <stat_log/stats/accumulator.h>
#include <stat_log/stats/accumulator_types/count.h>
#include <stat_log/stats/accumulator_types/min.h>
#include <stat_log/stats/accumulator_types/max.h>
#include <stat_log/stats/accumulator_types/mean.h>

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
// #include <boost/accumulators/statistics/min.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/*********************************
 * Statistic definitions
 *********************************/

struct TOP_MAC_SIS
{
   SL_NAME = "TOP_LEVEL";
   using ChildTypes = boost::fusion::vector<
      MAC,
      SIS
   >;
};

constexpr bool IsOperational = true;

using OpStatMacSis = stat_log::LogStatOperational<TOP_MAC_SIS>;
using ControlStatMacSis = stat_log::LogStatControl<TOP_MAC_SIS>;
/*********************************/

//TODO: threading vs no-threaded policy
//
namespace stat_log
{

   namespace ba = boost::accumulators;
   template <typename Tag>
   struct stat_tag_to_type<Tag, typename std::enable_if<
      std::is_base_of<MacBase, Tag>::value
      >::type
   >
   {
      using type = SimpleCounter<long unsigned int>;
   };

   template <typename Tag>
   struct stat_tag_to_type<Tag, typename std::enable_if<
      std::is_base_of<SisBase, Tag>::value
      >::type
   >
   {
      using type = SimpleCounter<int>;
   };

   using TheAccum = ba::accumulator_set<
         double
         , ba::stats<
               ba::tag::count
             , ba::tag::min
             , ba::tag::max
             , ba::tag::mean
             >
      >;

   template <>
   struct stat_tag_to_type<HW_INTERFACE::MISC_FPGA_FAULT_TAG>
   {
      using type = Accumulator<TheAccum>;
   };
}


template <bool IsOperational>
void initializeStatistics();

#define STAT_LOG_MAC_SIS_SHM_NAME "stat_log_mac_sis"
#define STAT_LOG_HW_INTF_SHM_NAME "stat_log_hw_intf"
#define STAT_LOG_LOGGER_NAME "SHM_LOGGER1"
#define STAT_LOG_LOGGER_SIZE_BYTES 4194304
