//          Copyright Erle Carrara 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/moment.hpp>
#include <pybind11/pybind11.h>

using namespace boost::accumulators;
namespace py = pybind11;


using accumulator_set_type = accumulator_set<double, stats<tag::mean>>;


PYBIND11_PLUGIN(accumulators) {
    py::module m("accumulators");

    py::class_<accumulator_set_type>(m, "Accumulator")
        .def(py::init())
        .def("__call__", [](accumulator_set_type &acc, double v) {
            return acc(v);
        }, py::is_operator())
        .def("mean", [](const accumulator_set_type &acc) {
        return mean(acc);
    });

    return m.ptr();
}
