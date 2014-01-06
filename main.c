#include <stdio.h>
#include <Python.h>
#include <wchar.h>

int main(int argc, char *argv[]) {

  /* These have to be wchar_t */
  char *str_program_name = argv[0];
  char **str_argv = argv;

  /* For ever stupid reason, these don't need to be wchar_t * */
  char *_sys = "sys";
  char *_libdir = "lib";
  char *_path = "path";
  char *_dot = ".";

  char **_argv = str_argv;
  char *_program_name = str_program_name;

  /* Setup */
  Py_SetProgramName(_program_name);
  Py_Initialize();

  /* Add local path */
  printf("\nInit passed\n");
  PyObject *sys = PyImport_ImportModule(_sys);
  PyObject *path = PyObject_GetAttrString(sys, _path);
  PyList_Append(path, PyString_FromString(_dot));
  PyList_Append(path, PyString_FromString(_libdir));
  printf("\nLib passed\n");

  /* Run the 'main' module */
  int rtn = Py_Main(argc, _argv);
  Py_Finalize();

  return rtn;
}
