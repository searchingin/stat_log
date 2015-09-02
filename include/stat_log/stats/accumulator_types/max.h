#pragma once
#include <boost/accumulators/statistics/max.hpp>
#include <iostream>

namespace stat_log
{
   namespace accumulator
   {
      template <typename AccumSet>
      struct traits<AccumSet, boost::accumulators::tag::max>
      {
         using SharedType = typename AccumSet::sample_type;
         static void serialize(AccumSet& acc, char* ptr)
         {
            *reinterpret_cast<SharedType*>(ptr) =
               boost::accumulators::max(acc);
         }

         static constexpr size_t size()
         {
            return sizeof(SharedType);
         }

         static constexpr const char* stat_name = "max";

         static void dumpStat(void* ptr)
         {
            std::cout << *reinterpret_cast<SharedType*>(ptr);
         }
      };
   }
}
