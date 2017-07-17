//File: python_wrapper.cc
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <pybind11/stl.h>

#include "../elf/pybind_helper.h"

#include "game_context.h"

namespace py = pybind11;

PYBIND11_PLUGIN(go_game) {
  py::module m("go_game", "Go game bindings.");
  register_common_func<GameContext>(m);

  CONTEXT_REGISTER(GameContext)
    .def("get_num_actions", &GameContext::get_num_actions);

  return m.ptr();
}