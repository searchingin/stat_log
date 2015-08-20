#pragma once
#include "stat_log/util/make_stat_tags.h"

struct SisBase{};

struct SIS
{
   NAME = "SIS";

   MAKE_STAT_TAG_STRUCT_BASE(MAC_PKTS_DOWN, SisBase)
   MAKE_STAT_TAG_STRUCT_BASE(MAC_PKTS_UP, SisBase)

   struct PER_NBR_STATS{
      NAME = "PER_NBR_STATS";
      MAKE_STAT_TAGS_NAMED_BASE(
            SisBase,
         (LINK_QUALITY)
         (RECEIVE_STATUS)
         (LINK_STATUS)
      )
   };

   using ChildTypes = boost::fusion::vector<
      MAC_PKTS_DOWN_TAG,
      MAC_PKTS_UP_TAG,
      PER_NBR_STATS
   >;
};
