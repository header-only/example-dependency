#ifndef SOME_NAMESPACE_AWESOME_HPP
#define SOME_NAMESPACE_AWESOME_HPP

#include <iostream>
#include <json.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/include/intrinsic.hpp>

namespace example_dependency {
  inline void hello() {
    nlohmann::json j;

    j["Don't know why, but this lib depens on stuffs that I don't want to bother with "] = BOOST_PP_CAT(4, 2);

    boost::fusion::vector<int, char, double> some_data(42, 'A', 42.43);
    j["int"] = boost::fusion::at_c<0>(some_data);
    j["char"] = boost::fusion::at_c<1>(some_data);
    j["double"] = boost::fusion::at_c<2>(some_data);

    std::cout << j.dump(2) << std::endl;
  }
}

#endif 
