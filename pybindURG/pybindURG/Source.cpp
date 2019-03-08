#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "Header.h"



using namespace::std;
namespace py = pybind11;

PYBIND11_MODULE(pybindURG, m) {
	m.doc() = "I'm always beneath you, but nothing is beneath me!";

	py::class_<urgCommunication>(m, "urgCommunication")
		.def(py::init<const std::string>())
		.def("run", &urgCommunication::run);

}