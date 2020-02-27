#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <ApproxMVBB/ComputeApproxMVBB.hpp>
#include <ApproxMVBB/OOBB.hpp>

PYBIND11_MODULE(pyApproxMVBB, m) {
    namespace py = pybind11;

    m.doc() = "pybind11 binding to approxMVBB";

    // Definition of an oriented bounding box
    py::class_<ApproxMVBB::OOBB>(m, "OOBB")
        .def("getCornerPoints", &ApproxMVBB::OOBB::getCornerPoints<true>);

    // Definition of the approximation function
    m.def("approximateMVBB",
            [](Eigen::Ref<Eigen::Matrix<double, 3, Eigen::Dynamic>> pts,
                const double epsilon,
                const unsigned int pointSamples,
                const unsigned int gridSize,
                const unsigned int mvbbDiamOptLoops,
                const unsigned int mvbbGridSearchOptLoops,
                unsigned int seed)
                {
                    return ApproxMVBB::approximateMVBB(pts, epsilon, pointSamples, gridSize, mvbbDiamOptLoops, mvbbGridSearchOptLoops, seed);
                },
            py::arg("pts"),
            py::arg("epsilon"),
            py::arg("pointSamples"),
            py::arg("gridSize"),
            py::arg("mvbbDiamOptLoops"),
            py::arg("mvbbGridSearchOptLoops"),
            py::arg("seed"));
}
