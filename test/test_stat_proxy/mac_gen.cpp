#include "mac_stat_tags.h"
#include "stat_proxy_interface.h"

void genStats_MAC()
{
   writeStatProxy<MAC::IP_PKTS_UP_TAG>(1);
}
