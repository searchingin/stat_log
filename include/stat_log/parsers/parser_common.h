#pragma once
#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

#include <boost/any.hpp>

#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <regex>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <assert.h>

#define TERM_NUM_COLUMNS 100

namespace stat_log
{
enum class StatCmd
{
   NO_CMD,
   PRINT_STAT_TYPE,
   DUMP_STAT,
   CLEAR_STAT,
   DUMP_TIMESERIES,
};


template<typename Stat, bool IsParent>
struct DoCmd;
}

